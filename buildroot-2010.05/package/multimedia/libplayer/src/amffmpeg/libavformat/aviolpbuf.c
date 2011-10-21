
/*
 * Buffered I/O for ffmpeg system
 * Copyright (c) 2000,2001 Fabrice Bellard
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * 	LOOPBUF READ
 * 	Write By zhi.zhou@amlogic.com
 *
 */

#include "libavutil/crc.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "avio.h"
#include <stdarg.h>

/*
										Pos		
buffer    rp                         wp                   buffer_end 
|           |                           |                           |
================================
|                                                                     |
|<--------------buffer_size-------------->|


valid_data_too_read:
	if wp>=rp
		wp-rp
	else
	    buffer_size-(rp-wp)

valid_data_size:for seek;

alway ++,utill seek to empte the buff;

Can seek back size:
	min(valid_data_size-valid_data_too_read,data between buffe,rp)

*/
//#define LP_BUFFER_DEBUG
#define LP_SK_DEBUG
//#define LP_RD_DEBUG
#ifdef LP_SK_DEBUG
#define lp_sprint(level,fmt...) av_log(NULL,level,##fmt)
#else
#define lp_sprint(level,fmt...)
#endif

#ifdef LP_RD_DEBUG
#define lp_rprint(level,fmt...) av_log(NULL,level,##fmt)
#else
#define lp_rprint(level,fmt...)
#endif

#ifdef LP_BUFFER_DEBUG
#define lp_bprint(level,fmt...) av_log(NULL,level,##fmt)
#else
#define lp_bprint(level,fmt...)
#endif


#define LP_ASSERT(x)	 do{if(!(x)) av_log(NULL,AV_LOG_INFO,"****\t\tERROR at line file%s=%d\n\n\n",__FILE__,__LINE__);}while(0)

int url_lpopen(URLContext *s,int size)
{
	url_lpbuf_t *lp;
	if(!s)
		return -1;
	lp=av_mallocz(sizeof(url_lpbuf_t));
	if(!lp)
		return AVERROR(ENOMEM);
	lp->buffer=av_malloc(size);
	if(!lp->buffer)
	{
		av_free(lp->buffer);
		return AVERROR(ENOMEM);
	}
	s->lpbuf=lp;
	lp->buffer_size=size;
	lp->rp=lp->buffer;
	lp->wp=lp->buffer;
	lp->buffer_end=lp->buffer+size;
	lp->valid_data_size=0;
	lp->pos=0;
	lp->block_read_size=FFMIN(32*1024,size>>4);
	lp_lock_init(&lp->mutex,NULL);
	lp->file_size=url_lpseek(s,0,AVSEEK_SIZE);
	return 0;
}


int url_lpfillbuffer(URLContext *s,int size)
{
	url_lpbuf_t *lp;
	int rlen;
	int ssread;
	
	if(!s || !s->lpbuf)
		return AVERROR(EINVAL);

	lp=s->lpbuf;
	lp_lock(&lp->mutex);
	
	if(lp->wp>=lp->rp)
	{
		if(lp->rp!=lp->buffer)
			ssread=FFMIN(size,lp->buffer_end-lp->wp);
		else
			ssread=FFMIN(size,lp->buffer_end-lp->wp-32);
	}
	else
		ssread=FFMIN(size,lp->rp-lp->wp-32);/*reversed 32bytes;*/
	lp_bprint( AV_LOG_INFO,"fill buffer %d,buffer=%x,rp=%x,wp=%x,buffer_end=%x,size=%d\n",ssread,lp->buffer,lp->rp,lp->wp,lp->buffer_end,size);
	if(ssread<=0)
	{
		rlen=0;
		goto release;
	}
	rlen=s->prot->url_read(s,lp->wp,ssread);
	if(rlen>0)
	{
		lp->valid_data_size+=rlen;
		lp->pos+=rlen;
		lp->wp+=rlen;
		if(lp->wp>=lp->buffer_end)
			lp->wp=lp->buffer;
		
	}
release:
	lp_unlock(&lp->mutex);
	return rlen;
}

int url_lpread(URLContext *s,unsigned char * buf,int size)
{
	url_lpbuf_t *lp;
	int len=size;
	int valid_data_can_read;
	unsigned char *tbuf=buf;

	if(!s || !s->lpbuf)
		return -1;
	lp=s->lpbuf;
	lp_lock(&lp->mutex);
	lp_rprint(AV_LOG_INFO, "url_lpread:buffer=%x,rp=%x,wp=%x,end=%x,lp->valid_data_size=%d,pos=%lld\n",
		lp->buffer,lp->rp,lp->wp,lp->buffer_end,lp->valid_data_size,lp->pos);
	while(len>0)
	{
		if(lp->wp>=lp->rp)
			valid_data_can_read=lp->wp-lp->rp;
		else
			valid_data_can_read=lp->buffer_end-lp->rp;
		valid_data_can_read=FFMIN(len,valid_data_can_read);
		LP_ASSERT(valid_data_can_read>=0);
		if(valid_data_can_read==0)
		{
			int rlen;
			lp_unlock(&lp->mutex);
			rlen=url_lpfillbuffer(s,lp->block_read_size);
			if(rlen<=0)
				{
				lp_unlock(&lp->mutex);
				return ((size-len)>0)?(size-len):rlen;
				}
			lp_lock(&lp->mutex);
		}
		lp_rprint( AV_LOG_INFO, "url_lpread:buffer=%x,rp=%x,wp=%x,end=%x,tbuf=%x,valid_data_can_read=%x(%d)\n",
			lp->buffer,lp->rp,lp->wp,lp->buffer_end,tbuf,valid_data_can_read,valid_data_can_read);
		if(valid_data_can_read>0)
		{
			if(tbuf!=NULL)
			{
				memcpy(tbuf,lp->rp,valid_data_can_read);
				tbuf+=valid_data_can_read;
			}
			lp->rp+=valid_data_can_read;
			if(lp->rp>=lp->buffer_end)
				lp->rp=lp->buffer;
			len-=valid_data_can_read;
		}
		LP_ASSERT(lp->rp>=lp->buffer);
		LP_ASSERT(lp->rp<lp->buffer_end);
	}
	lp_unlock(&lp->mutex);
	return (tbuf-buf);
}

int64_t url_lpseek(URLContext *s, int64_t offset, int whence)
{
	int64_t pos_on_read;
	url_lpbuf_t *lp;
	int valid_data_can_seek_forward;
	int valid_data_can_seek_back;
	int64_t offset1;
	int ret;

	if(!s || !s->lpbuf)
		return AVERROR(EINVAL);

	lp=s->lpbuf;
	lp_lock(&lp->mutex);
	lp_sprint( AV_LOG_INFO, "url_lpseek:offset=%lld whence=%d,buffer=%x,rp=%x,wp=%x,end=%x,pos=%lld\n",
		offset,whence,lp->buffer,lp->rp,lp->wp,lp->buffer_end,lp->pos);
	if (whence == AVSEEK_SIZE)
	{
		int64_t size;
		size = s->prot->url_seek(s, 0, AVSEEK_SIZE);
		if(size<0){
			if ((size = s->prot->url_seek(s, -1, SEEK_END)) < 0)
			{
				lp_unlock(&lp->mutex);
				return size;
			}
			size++;
			s->prot->url_seek(s,lp->pos, SEEK_SET);
		}
		lp_sprint(AV_LOG_INFO,"get file size=%lld\n",size);
		lp_unlock(&lp->mutex);
		return size;
	}
	else if(whence == SEEK_END)
	{
		if ((offset1=s->prot->url_seek(s, offset, SEEK_END)) < 0)
		{
			lp_unlock(&lp->mutex);
			return offset1;
		}
		lp->rp=lp->buffer;
		lp->wp=lp->buffer;
		lp->valid_data_size=0;
		lp->pos=offset1;
		lp_unlock(&lp->mutex);
		return offset1;
	}
    if (whence != SEEK_CUR && whence != SEEK_SET)
    {
      		lp_unlock(&lp->mutex);
        	return AVERROR(EINVAL);
    }

	if(lp->wp>=lp->rp)
		valid_data_can_seek_forward=lp->wp-lp->rp;
	else
		valid_data_can_seek_forward=lp->buffer_size-(lp->rp-lp->wp);
	pos_on_read = lp->pos-valid_data_can_seek_forward;
 	
	if(whence == SEEK_CUR)
	{
		offset1 = pos_on_read;
		if (offset == 0)
		{
			lp_unlock(&lp->mutex);
			return offset1;
		}
		offset += offset1;
	}
	valid_data_can_seek_back=FFMIN(lp->valid_data_size-valid_data_can_seek_forward,
						lp->buffer_size-valid_data_can_seek_forward-64);
	if(valid_data_can_seek_back<0) 
		valid_data_can_seek_back=0;
	offset1 = offset - pos_on_read;/*seek forword or back*/
	lp_sprint( AV_LOG_INFO, "url_lpseek:pos_on_read=%lld,can seek forwart=%d,can seek bacd=%d,offset1=%lld\n",
		pos_on_read,valid_data_can_seek_forward,valid_data_can_seek_back,offset1);
	if(offset1>=0 && offset1<=valid_data_can_seek_forward)
	{/*seek forward in lp buffer*/
		lp_sprint( AV_LOG_INFO, "url_lpseek:buffer seek forword offset=%lld offset1=%lld whence=%d\n",offset,offset1,whence);
		lp->rp+=(int)offset1;
		if(lp->rp>=lp->buffer_end)
			lp->rp-=lp->buffer_size;
	}else if(offset1<0 && (-offset1)<=valid_data_can_seek_back)
	{/*seek back in lp buffer*/
		lp_sprint( AV_LOG_INFO, "url_lpseek:buffer seek back offset=%lld offset1=%lld whence=%d,(int)offset1=%d\n",offset,offset1,whence,(int)offset1);
		lp->rp+=(int)offset1;
		if(lp->rp<lp->buffer)
			lp->rp+=lp->buffer_size;
		
	}else if(offset1>0 && (s->is_streamed || s->is_slowmedia) && 
			(offset1<lp->buffer_size-lp->block_read_size) && 
			(lp->file_size<=0 || (lp->file_size>0 && offset1<lp->file_size/2)))/*if offset1>filesize/2,thendo first seek end,don't buffer*/
	{/*seek to buffer end,but buffer is not full,do read seek*/
		lp_sprint( AV_LOG_INFO, "url_lpseek:buffer read seek forward offset=%lld offset1=%lld  whence=%d\n",offset,offset1,whence);
		lp->rp+=valid_data_can_seek_forward;
		if(lp->rp>=lp->buffer_end)
			lp->rp-=lp->buffer_size;
		lp_unlock(&lp->mutex);
		url_lpread(s,NULL,offset1-valid_data_can_seek_forward);/*do read seek*/
		lp_lock(&lp->mutex);
	}else
	{/*not support in buffer seek,do low level seek now*/
		lp_sprint( AV_LOG_INFO, "url_lpseek:buffer lowlevel seek  offset=%lld  offset1=%lld whence=%d\n",offset,offset1,whence);
		
		if ((offset1=s->prot->url_seek(s, offset, SEEK_SET)) < 0)
		{
			lp->valid_data_size=0;/*seek failed clear all old datas*/
			s->prot->url_seek(s, lp->pos, SEEK_SET);/*clear the lowlevel errors*/
			lp_unlock(&lp->mutex);
			return  offset1;
		}
		lp->rp=lp->buffer;
		lp->wp=lp->buffer;
		lp->valid_data_size=0;
		lp->pos=offset;
	}
	lp_sprint( AV_LOG_INFO, "url_lpseekend:offset=%lld whence=%d,buffer=%x,rp=%x,wp=%x,end=%x,pos=%lld\n",
		offset,whence,lp->buffer,lp->rp,lp->wp,lp->buffer_end,lp->pos);
	LP_ASSERT(lp->rp>=lp->buffer);
	LP_ASSERT(lp->rp<lp->buffer_end);
	lp_unlock(&lp->mutex);
	return offset;
}

int64_t url_lpexseek(URLContext *s, int64_t offset, int whence)
{
	url_lpbuf_t *lp;
	int64_t ret;

	if(!s || !s->lpbuf || !s->prot->url_exseek)
		return AVERROR(EINVAL);

	lp=s->lpbuf;
	lp_lock(&lp->mutex);
	if (whence == AVSEEK_FULLTIME)
	{
		ret=s->prot->url_exseek(s,0, AVSEEK_FULLTIME);/*clear the lowlevel errors*/
	}
	else if (whence == AVSEEK_BUFFERED_TIME)
	{
		ret=s->prot->url_exseek(s,0, AVSEEK_BUFFERED_TIME);/*clear the lowlevel errors*/
	}
	else if(whence == AVSEEK_TO_TIME ){
	 	if(s->prot->url_exseek){
			if((ret=s->prot->url_exseek(s, offset, AVSEEK_TO_TIME))>=0)
			{
				lp->rp=lp->buffer;
				lp->wp=lp->buffer;
				lp->valid_data_size=0;
				lp->pos=0; 
				goto seek_end;
			}
	 	}
		ret= AVERROR(EPIPE);
	}
seek_end:
	lp_unlock(&lp->mutex);
	return ret;
}

int url_lp_getbuffering_size(URLContext *s,int *forward_data,int *back_data)
{
	url_lpbuf_t *lp;
	int valid_data_can_seek_forward;
	int valid_data_can_seek_back;
	int ret;

	if(!s || !s->lpbuf)
		return AVERROR(EINVAL);

	lp=s->lpbuf;
	lp_lock(&lp->mutex);
	if(lp->wp>=lp->rp)
		valid_data_can_seek_forward=lp->wp-lp->rp;
	else
		valid_data_can_seek_forward=lp->buffer_size-(lp->rp-lp->wp);

	valid_data_can_seek_back=FFMIN(lp->valid_data_size-valid_data_can_seek_forward,
						lp->buffer_size-valid_data_can_seek_forward-64);
	if(valid_data_can_seek_back<0) 
		valid_data_can_seek_back=0;
	lp_unlock(&lp->mutex);

	if(forward_data)	
		*forward_data=valid_data_can_seek_forward;
	if(back_data)	
		*back_data=valid_data_can_seek_back;
	return (valid_data_can_seek_back+valid_data_can_seek_forward);
}


int64_t url_lp_get_buffed_pos(URLContext *s)
{
	url_lpbuf_t *lp;
	int64_t pos;
	if(!s || !s->lpbuf)
			return AVERROR(EINVAL);
	lp=s->lpbuf;
	lp_lock(&lp->mutex);
	pos=lp->pos;
	lp_unlock(&lp->mutex);
	return pos;
}

int url_lp_intelligent_buffering(URLContext *s,int size)
{
	int forward_data,back_data;
	int datalen;
	url_lpbuf_t *lp;
	int ret=0;
	
	if(!s || !s->lpbuf)
		return AVERROR(EINVAL);

	
	lp=s->lpbuf;
	if(size <=0)
		size=lp->block_read_size; 
	datalen= url_lp_getbuffering_size(s,&forward_data,&back_data);
	lp_bprint( AV_LOG_INFO, "url_lp buffering:datalen=%d,forward_datad=%d,back_data=%d,lp->buffer_size=%d,size=%d\n",
		datalen,forward_data,back_data,lp->buffer_size,size);
	if(datalen>=0 && ((datalen <lp->buffer_size-1024) || (back_data>(forward_data/2+1))))
		ret=url_lpfillbuffer(s,size);

	return ret;
}

int url_lpfree(URLContext *s)
{
	if(s->lpbuf)
	{
		lp_lock(&s->lpbuf->mutex);
		/*release other threadlater...*/
		lp_unlock(&s->lpbuf->mutex);
		if(s->lpbuf->buffer)
			av_free(s->lpbuf->buffer);
		av_free(s->lpbuf);
		s->lpbuf=NULL;
	}
	return 0;
}




