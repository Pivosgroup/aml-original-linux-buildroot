#ifndef SD_EMBEDTHUNDER_H_00138F8F2E70_200809081558
#define SD_EMBEDTHUNDER_H_00138F8F2E70_200809081558
/*--------------------------------------------------------------------------*/
/*                               IDENTIFICATION                             */
/*--------------------------------------------------------------------------*/
/*     Filename  : embed_thunder.h                                         */
/*     Author     : Li Feng                                              */
/*     Project    : EmbedThunder                                        */
/*     Version    : 1.3  													*/
/*--------------------------------------------------------------------------*/
/*                  Shenzhen XunLei Networks			                    */
/*--------------------------------------------------------------------------*/
/*                  - C (copyright) - www.xunlei.com -		     		    */
/*                                                                          */
/*      This document is the proprietary of XunLei                          */
/*                                                                          */
/*      All rights reserved. Integral or partial reproduction               */
/*      prohibited without a written authorization from the                 */
/*      permanent of the author rights.                                     */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                         FUNCTIONAL DESCRIPTION                           */
/*--------------------------------------------------------------------------*/
/* This file contains the interfaces of EmbedThunder                         */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                              HISTORY                                     */
/*--------------------------------------------------------------------------*/
/*   Date     |    Author   | Modification                                  */
/*--------------------------------------------------------------------------*/
/* 2008.09.08 | Li Feng  | Creation                                      */
/*--------------------------------------------------------------------------*/
/* 2009.01.19 | ZengYuqing  | Update to version 1.2                                     */
/*--------------------------------------------------------------------------*/
/* 2009.04.13 | ZengYuqing  | Update to version 1.3    

1.et1.3�汾��et1.2�汾�Ļ����������˴�BTЭ������غ�vod�㲥���ܡ�
2.�ڽṹ��ET_TASK�е�����״̬_task_status��������ET_TASK_VOD(ע���״̬��Ӧ��ֵΪ2����ԭ����״̬ET_TASK_SUCCESS��Ϊ3��ET_TASK_FAILED��Ϊ4��ET_TASK_STOPPED��Ϊ5)����״̬������������������ϣ��������ڲ���״̬���ڸ�״̬�£��û����Ե���et_stop_taskǿ��ֹͣ���񣬵�������ֱ�ӵ���et_delete_task��
3.�ڽṹ��ET_TASK�У�����Ԫ��_valid_data_speed���ò���������ʾ�㲥ʱʵ�ʵ����������ٶȣ����ڵ����á�ע�⣬�ò����ڱ���꿪��_CONNECT_DETAIL�Ŀ���֮�¡�
4.�ڽṹ��ET_PEER_PIPE_INFO���޸�Ԫ��_peerid�ĳ���Ϊ21.
5.�ڽṹ��ET_BT_FILE��_file_status�����У�ȥ��ԭ���ġ��ļ�δ��ɡ�״̬��
6.��ע��licenseʱ�����ص��������������˷���ֵ21005����ʾ��������æ�����ؿ����һСʱ���Զ����ԡ�
7.�������ڵõ����ؿ��ڵ�ǰ���е�task��id�Ľӿں���et_get_all_task_id��
8.�������ڵõ�task_id��ʶ��BT�����������Ҫ���ص��ļ���id�Ľӿں���et_get_bt_download_file_index��
9.�������������͹ر�VOD�㲥�õ�http�������Ľӿں�����et_start_http_server��et_stop_http_server��
10.����VODʱ���ڶ�ȡ�������ݵĽӿں���et_vod_read_file��
11.���������û��Զ�������socket��ز����ĺ�������#define ET_SOCKET_IDX_SET_SOCKOPT (11)��
12.������Ѹ�׿���VODר��URL�������������������Ĺ��ܣ���ϸ˵���뿴et_create_new_task_by_url�Ľӿ�˵����
13.�ӿ�et_create_new_bt_task�ѱ��ӿ�et_create_bt_taskȡ������Ȼet_create_new_bt_task�������ã�������ֱ����et_create_bt_task��
14.������bt����ʱ�����������Ҫ���صĿ��ļ���piece�Ļ�����������Ŀ¼��������info_hash.tmp�ļ���info_hash.tmp.cfg,������������ɺ��������ļ��ᱻɾ�����������û����ɵĻ����ǲ���ɾ���ġ�
15.�ڽṹ��ET_BT_FILE�У�ȥ��ԭ���Ĳ�����char *_file_name_str;u32 _file_name_len;BOOL _is_need_download;����������ʾp2sp����״���Ĳ�����BOOL _has_record;u32 _accelerate_state��
16.���ӻ�ȡBT�����ļ�·�����ļ����Ľӿں�����et_get_bt_file_path_and_name��
17.���������û��Զ���������ͷ��ڴ�ĺ�������#define ET_MEM_IDX_GET_MEM (12) ��#define ET_MEM_IDX_FREE_MEM (13) ��
18.�ڽṹ��ET_TASK�У�����Ԫ��_ul_speed���ò���������ʾ������ϴ��ٶȡ�
19.�ڽṹ��ET_TASK�У�����Ԫ��_bt_dl_speed��_bt_ul_speed�������������ֱ�������ʾBT����Ĵ�BTЭ����ϴ��������ٶȣ����ڵ����á�ע�⣬�ò����ڱ���꿪��_CONNECT_DETAIL�Ŀ���֮�£���ֻ��BT������Ч��
20.��Ҫ��ʾ������꿪��_CONNECT_DETAIL����֮�µ����нṹ��Ͳ�����ֻ��Ѹ�׹�˾�ڲ������ã���ʱû�п��Ÿ���������飬������������鲻Ҫ�ڽ�������ж������꿪��_CONNECT_DETAIL������Ҫ����������صĽṹ��Ͳ������ɴ˴����Ĳ��㣬����£�	[2009.05.13]
21.��et_create_new_task_by_url�ӿ��еĲ���char* file_name_for_user ��Ϊ char* file_name��	[2009.05.14]
22.��et_create_continue_task_by_url�ӿ��еĲ���char* cur_file_name ��Ϊ char* file_name��	[2009.05.14]
23.���ӽӿ�et_create_task_by_tcid_file_size_gcid��	[2009.05.14]
24.et_create_continue_task_by_url��et_create_continue_task_by_tcid���ӷ��ش�����4199����ʾ��Ӧ��.cfg�ļ������ڡ�	[2009.06.08]
25.���ӽӿ�et_get_current_upload_speed��õײ��ϴ��ٶȡ�	[2009.06.29]
26.���ӽӿ�et_set_download_record_file_path �����������ؼ�¼�ļ���·����	[2009.07.01]
27.���ӽӿ�et_set_task_no_disk ���ڽ�vod��������Ϊ��������ģʽ��	[2009.07.22]
28.���ӽӿ�et_get_upload_pipe_info ���ڶ�ȡ�ϴ�pipe����Ϣ(����Ѹ���ڲ�������)��	[2009.07.23]
29.���ӶԽӿ�et_set_license_callback �й��ڻص������в��ܵ����κ����ؿ�Ľӿڵ���Ҫ˵����	[2009.07.27]
30.���ӶԽӿ�et_create_task_by_tcid_file_size_gcid �в���file_size�в����Ե���0����Ҫ������	[2009.07.27]
31.���ӶԽӿ�et_set_limit_speed �в��������Ե���0��˵����	[2009.08.27]
32.���ӶԽӿ�et_set_max_task_connection �в���ȡֵ��Χ��˵����	[2009.08.27]
33.�������û���ʱ��ӿ�et_vod_set_buffer_time [2009.08.27]
34.���ӻ�ȡ����ٷֱȽӿ�et_vod_get_buffer_percent [2009.08.27]
35.���ӶԽӿ�et_set_limit_speed ��ע��˵����				[2009.09.01]
36.���ӶԽӿ�et_get_current_download_speed ��ע��˵����	[2009.09.01]
37.���ӶԽӿ�et_get_current_upload_speed��ע��˵����		[2009.09.01]
38.ȥ��ET_PEER_PIPE_INFO�ṹ����Ԫ��_upload_speed��UPLOAD_ENABLE�����	[2009.09.01]
39.���ӶԽӿ�et_get_bt_file_info�Ĵ�����˵��:1174  �ļ���Ϣ���ڸ����У���ʱ���ɶ������Ժ�����!	[2009.09.03]
40.�����û��Զ���ӿ���typedef int32 (*et_fs_open)(char *filepath, int32 flag, u32 *file_id);��file_idΪu64���ش�˵������[2009.11.19]
41.���ӶԽӿ�et_set_license�Ĵ�����˵��:1925 	��ȡ����MAC ����!	[2009.11.23]
42.������vod �㲥ר���ڴ��йص��ĸ��ӿ�:et_vod_get_vod_buffer_size,et_vod_set_vod_buffer_size,et_vod_is_vod_buffer_allocated,et_vod_free_vod_buffer [2009.12.12]
43.�������ڲ�ѯvod �㲥����������Ƿ�������ϵĽӿ�:et_vod_is_download_finished	 		[2009.12.12]
*/

#ifdef __cplusplus
extern "C" 
{
#endif

#ifdef WIN32
#ifndef WINCE
	#ifdef ETDLL_EXPORTS
	#define ETDLL_API __declspec(dllexport)
	#else
	#define ETDLL_API __declspec(dllimport)
	#endif
#else
	#define ETDLL_API
#endif
#else
	#define ETDLL_API
#endif

/************************************************************************/
/*                    TYPE DEFINE                                       */
/************************************************************************/
typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef char				int8;
typedef short				int16;
typedef int				int32;
#if defined(LINUX)
	typedef unsigned long long	uint64;
	typedef long long			int64;
#else
	#ifdef  NOT_SUPPORT_LARGE_INT_64
		typedef unsigned int	uint64;
		typedef int			__int64;
	#else
        #if defined(WIN32)
		typedef unsigned __int64 uint64;
		//typedef long long			__int64;
         #else
		typedef unsigned long	long uint64;
		typedef long long			__int64;
         #endif
	#endif
#endif

#if defined(LINUX)
#ifndef NULL
#define NULL	((void*)(0))
#endif
#endif

#ifndef TRUE
typedef int32 BOOL;
#define TRUE	(1)
#define FALSE	(0)
#endif


/************************************************************************/
/*                    STRUCT DEFINE                                     */
/************************************************************************/

enum ET_TASK_STATUS {ET_TASK_IDLE = 0, ET_TASK_RUNNING, ET_TASK_VOD,  ET_TASK_SUCCESS, ET_TASK_FAILED, ET_TASK_STOPPED};
enum ET_TASK_FILE_CREATE_STATUS {ET_FILE_NOT_CREATED = 0, ET_FILE_CREATED_SUCCESS,  ET_FILE_CREATED_FAILED};
enum ET_ENCODING_SWITCH_MODE 
{ 
	ET_ENCODING_PROTO_MODE = 0, /* ����ԭʼ�ֶ� */
	ET_ENCODING_GBK_SWITCH = 1,/*  ����GBK��ʽ���� */
	ET_ENCODING_UTF8_SWITCH = 2,/* ����UTF-8��ʽ���� */
	ET_ENCODING_BIG5_SWITCH = 3,/* ����BIG5��ʽ����  */
	
	ET_ENCODING_UTF8_PROTO_MODE = 4,/* ���������ļ��е�utf-8�ֶ�  */
	ET_ENCODING_DEFAULT_SWITCH = 5/* δ���������ʽ(ʹ��et_set_seed_switch_type��ȫ���������)  */
};


#ifdef _CONNECT_DETAIL
/* Ѹ�׹�˾�ڲ�������  */
typedef struct t_et_peer_pipe_info
{
	u32	_connect_type;
	char	_internal_ip[24];
	char	_external_ip[24];
	u16	_internal_tcp_port;
	u16	_internal_udp_port;
	u16	_external_port;
	char	_peerid[21];
    u32    _speed;
	
    u32    _upload_speed;

    u32    _score;
	
	/* pipe״̬ 
	0 ����
	1 ����
	2 ���ӳɹ�
	3 ��choke
	4 ��ʼ��������
	5 ��������
	6 ���سɹ�(��ɴ��ϴ�)
	*/
	u32    _pipe_state;
} ET_PEER_PIPE_INFO;

typedef struct t_et_peer_pipe_info_array
{
	 ET_PEER_PIPE_INFO _pipe_info_list[ 10 ];
    u32 _pipe_info_num;
} ET_PEER_PIPE_INFO_ARRAY;


#endif /*  _CONNECT_DETAIL  */


typedef struct t_et_download_task_info
{
	u32  _task_id;
	u32 _speed;    /*����������ٶ�*/
	u32 _server_speed;   /*����server ��Դ�������ٶ�*/  
	u32 _peer_speed;   /*����peer ��Դ�������ٶ�*/  
	u32 _ul_speed;    /*������ϴ��ٶ�*/
	u32 _progress;  /*�������*/  
	u32 _dowing_server_pipe_num; /*����server ������*/  
	u32 _connecting_server_pipe_num;  /*����server ����������*/  
	u32 _dowing_peer_pipe_num;  /*����peer ������*/  
	u32 _connecting_peer_pipe_num; /*����pipe ����������*/  

#ifdef _CONNECT_DETAIL
/* Ѹ�׹�˾�ڲ�������  */
       u32  _valid_data_speed;
	u32 _bt_dl_speed;   /*����BT ��Դ�������ٶȣ�ֻ��BT������Ч��*/  
	u32 _bt_ul_speed;   /*����BT ��Դ���ϴ��ٶȣ�ֻ��BT������Ч��*/  
	u32 _downloading_tcp_peer_pipe_num;
	u32 _downloading_udp_peer_pipe_num;
    
	u32 _downloading_tcp_peer_pipe_speed;
	u32 _downloading_udp_peer_pipe_speed;


	/* Server resource information */
	u32 _idle_server_res_num;
	u32 _using_server_res_num;
	u32 _candidate_server_res_num;
	u32 _retry_server_res_num;
	u32 _discard_server_res_num;
	u32 _destroy_server_res_num;

	/* Peer resource information */
	u32 _idle_peer_res_num;
	u32 _using_peer_res_num;

	u32 _candidate_peer_res_num;
	u32 _retry_peer_res_num;
	u32 _discard_peer_res_num;
	u32 _destroy_peer_res_num;
	u32 _cm_level;
    ET_PEER_PIPE_INFO_ARRAY _peer_pipe_info_array;    
#endif /*  _CONNECT_DETAIL  */
	uint64 _file_size;  /*�����ļ���С*/  

      /*����״̬: 	ET_TASK_IDLE  		����
                                	ET_TASK_RUNNING 	��������
                                 	ET_TASK_VOD 		������������ɣ����ڲ�����
                                 	ET_TASK_SUCCESS 	����ɹ�
                                 	ET_TASK_FAILED 		����ʧ�ܣ�ʧ����Ϊfailed_code
                                 	ET_TASK_STOPPED 	������ֹͣ
	 */  
	enum ET_TASK_STATUS  _task_status;   

	 /*����ʧ��ԭ��
              102  �޷�����
              103  �޷���ȡcid
              104  �޷���ȡgcid
              105  cid У�����
              106  gcidУ�����
              107  �����ļ�ʧ��
              108  д�ļ�ʧ��
              109  ���ļ�ʧ��
              112  �ռ䲻���޷������ļ�
              113 У��cidʱ���ļ����� 
              130  ����Դ����ʧ��

              15400 ���ļ�����ʧ��(bt����)
              
         */  	  
	u32  _failed_code;
	 
	/* Time information  */
	/* ע�⣺1.������ʱ���ǻ����1970��1��1�տ�ʼ������
		 		2.���ǵ��ڻ�ȡ����ʼʱ�䣨_start_time�������ʱ�䣨_finished_time��֮�䣬ϵͳ��ʱ���п��ܱ�������Ķ����¿�ʼʱ��������ʱ�䣬
		 		�������ʱ��ԶԶ���ڿ�ʼʱ�䣨�����1���£�����������£���������ʱ��ֱ�����������û���κ����塣
		 		��ˣ�������������ʱ������������õ�ʱ����߼���ƽ���ٶ�
		 		3.�����������񣬿�ʼʱ�䣨_start_time����¼���������������Ŀ�ʼʱ��   */
	u32 _start_time;	
	u32 _finished_time;

	enum ET_TASK_FILE_CREATE_STATUS _file_create_status;
	uint64 _downloaded_data_size; 		 /*�����ص����ݴ�С*/  
	uint64 _written_data_size;  /*��д����̵����ݴ�С*/  
}ET_TASK;


typedef struct  t_et_bt_file
{
	u32 _file_index;
	uint64 _file_size;	
	uint64 _downloaded_data_size; 		 /*�����ص����ݴ�С*/  
	uint64 _written_data_size; 			 /*��д�����̵����ݴ�С*/  
	u32 _file_percent;/* �ļ����ؽ���    */	

	/*�ļ�״̬:(�Ķ�˵��:ԭ���� 2:�ļ�δ��� ���״̬,����ȥ��)
		0:�ļ�δ����
		1:�ļ���������
		2:�ļ��������
		3:�ļ�����ʧ�� 
	*/
	u32 _file_status;


	/*��������ѯ״̬:
		0:δ��ѯ��
		1:���ڲ�ѯ, 
		2:��ѯ�ɹ���
		3:��ѯʧ�� 
	*/
	u32 _query_result;

	
	/*������ʧ��ԭ�������
		 15383  �޷�����
		 15393  cid У�����
		 15386  gcidУ�����
		 15394  �����ļ�ʧ��
		 15395  �������سɹ�,�ȴ�pieceУ��(��ʱ״̬,pieceУ��ɹ������ļ��ɹ�)
		 108  д�ļ�ʧ��
		 109  ���ļ�ʧ��
		 112  �ռ䲻���޷������ļ�
		 113 У��cidʱ���ļ�����
		 130  ����Դ����ʧ��
		 131  ��ѯ��Դʧ��

		 15389 ���ļ��ٶ�̫��
	*/	   
	u32 _sub_task_err_code;

	BOOL _has_record; /* Ϊ1 ��ʾxunlei��Դ�����и��ļ��ļ�¼������ͨ��p2sp������м��� */
	
	/*ͨ��p2sp������м��ٵ�״̬:
		0:δ���٣�
		1:���ڼ���, 
		2:���ٳɹ���
		3:����ʧ�ܣ�
		4:������ɡ���˼��ָ���ܼ��ٳɹ���ʧ�ܣ���֮����ļ��Ѿ������ٹ��������ٱ�����	*/
	u32 _accelerate_state; 
	
}ET_BT_FILE;



typedef struct  t_et_proxy_info
{
	char _server[32];
	char _user[32];
	char _password[32];

	u32 _port;

	int32 _proxy_type; /* 0 direct connect type, 1 socks5 proxy type, 	2 http_proxy type, 3 ftp_proxy type */
	int32 _server_len;
	int32 _user_len;
	int32 _password_len;
} ET_PROXY_INFO;

/* Structures for bt downloading */

#define ET_MAX_TD_CFG_SUFFIX_LEN (8)

typedef struct t_et_torrent_file_info
{
	u32 _file_index;
	char *_file_name;
	u32 _file_name_len;
	char *_file_path;
	u32 _file_path_len;
	uint64 _file_offset;
	uint64 _file_size;
} ET_TORRENT_FILE_INFO;

typedef struct t_et_torrent_seed_info
{
	char _title_name[256-ET_MAX_TD_CFG_SUFFIX_LEN];
	u32 _title_name_len;
	uint64 _file_total_size;
	u32 _file_num;
	u32 _encoding;//�����ļ������ʽ��GBK = 0, UTF_8 = 1, BIG5 = 2
	unsigned char _info_hash[20];
	ET_TORRENT_FILE_INFO *file_info_array_ptr;
} ET_TORRENT_SEED_INFO;


/*--------------------------------------------------------------------------*/
/*                Interfaces provid by EmbedThunder download library				        */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                ���ؿ�ĳ�ʼ���ͷ���ʼ���ӿ�				        */
/*--------------------------------------------------------------------------*/
/*
  * ��ʼ�����ؿ� 
  * ����ֵ: 0    �ɹ�
                      1025  ��ʼ�����ڴ�ʧ��
                      3672 ���ؿ��Ѿ�����ʼ������
                      4112 �Ƿ�����
                      ������ʼ�����ؿ��߳�ʧ�ܴ����� 
  * �������hub����Ҫ����proxy_for_hub���ó�NULL��proxy_typeΪ0
  *
  * ע�⣺Ѹ�����ؿ�������������нӿڶ��������������֮����ܵ��ã�������������-1����
  */
ETDLL_API int32 et_init(ET_PROXY_INFO* proxy_for_hub);

/*
  * ����ʼ�����ؿ� 
  * ����ֵ: 0    �ɹ�       
  * 
  * ע�⣺1.Ѹ�����ؿ�������������нӿڣ�����et_init�����������������֮����ã�������������-1����
 */
ETDLL_API int32 et_uninit(void);

/* Check the status of et */
ETDLL_API int32 et_check_critical_error(void);


/*--------------------------------------------------------------------------*/
/*              license��ؽӿ�			        
----------------------------------------------------------------------------*/
/* ���ô˿ͻ��˵� license 
  * ����ֵ: 0    �ɹ�       
  			   1925 	��ȡ����MAC ����
  			   
*  ע�⣺����������ؿ��ʼ��֮��������������et_start_task��֮ǰ���ô˺���
* ���������ڲ��Ե�license:
                               License                               |��� |��Ч��                         |״̬(���������ؽ��)
08083000021b29b27e57604f68bece019489747910|0000000|2008-08-13��2009-08-06|00

*/
ETDLL_API  int32 	et_set_license(char *license, int32 license_size);

/* ����license�ϱ�����������ؽ���ĵĻص�֪ͨ���� 
* �ر�ע��:������ص���������,����Ӧ�þ�����࣬�����в����������������������κ����ؿ�Ľӿ�!��Ϊ�����ᵼ�����ؿ�����!����!!! 
*
* ���ؿ��ÿ��һ��ʱ�䣨�ü���ɷ��������أ�һ��ΪһСʱ����license������
* �ϱ����ص�license����et_set_license���ã����������᷵�ظ�license��״̬(���)
*  �͹���ʱ��.
*
*  ע�⣺�����ؿⱻ��ʼ��(����et_init)�󣬽���������et_set_license�������ؿ�
*  ����license�������ϱ������õ�license������������ڳ�ʼ�����ؿ��û�е�
*  ��et_set_licenseȥ����license�����ؿ�Ҳ���������֮����������ϱ�����
*  ��������·����������ؽ��Ϊ21004(license����ٵ�)��ʹ���ؿⲻ�ܼ�������������!
*
*  ���⣬���ڷ���������Ӧ���ܺܿ죬������������license(����et_set_license)�󾡿�
*  ����et_set_license_callback���ûص��������������ؿ⽫�޷��ѷ��������صĽ��ͨ
*  ֪���������һ���Ƚϱ��յķ��������ڽ�������аѵ���et_set_license_callback
*  ���ڵ���et_set_license֮ǰ
*
*  ��һ��������ʾ�ϱ����صĽ�� result:
*    4096   ��ʾͨѶ����ԭ���������������������������,����һ������expire_time��Ϊ0����Ϊ���ܵ���������롣
*    4118   ��ʾlicense�ϱ�ʧ�ܣ�ԭ��ͬ4096���������е�����ͨ�������رգ��˺��½������񽫲������ء�
*    21000 ��ʾ LICENSE ��֤δͨ����ԭ���� LICENSE �����ᡣ
*    21001 ��ʾ LICENSE ��֤δͨ����ԭ���� LICENSE ���ڡ�
*    21002 ��ʾ LICENSE ��֤δͨ����ԭ���� LICENSE �����ա�
*    21003 ��ʾ LICENSE ��֤δͨЭ��ԭ���� LICENSE ���ظ�ʹ�á�
*    21004 ��ʾ LICENSE ��֤δͨЭ��ԭ���� LICENSE ����ٵġ�
*    21005 ��ʾ ��������æ�����ؿ����һСʱ���Զ����ԡ�
*    
*  �ڶ���������ʾ�೤ʱ������ expireTime����λΪ�룩.
*/
typedef int32 ( *ET_NOTIFY_LICENSE_RESULT)(u32 result, u32 expire_time);
ETDLL_API  int32 	et_set_license_callback( ET_NOTIFY_LICENSE_RESULT license_callback_ptr);


/*--------------------------------------------------------------------------*/
/*              ���ؿ�ȫ�ֲ���������ؽӿ�			        
----------------------------------------------------------------------------*/
/*
  * ��ȡ���ؿ�汾��, ����ֵ�ǰ汾�ŵ��ַ���
  *                   
  */
ETDLL_API const char* et_get_version(void);

/*
  * �������ؼ�¼�ļ���·��������ļ����ڼ�¼���ؿ����гɹ����ع����һ�û�б�ɾ�������ļ�����Ϣ��
  *	ע�⣺1.·������Ϊ�գ����Ȳ���Ϊ0�ҳ��Ȳ�����255�ֽڣ�Ҫ��'/'���Ž����������Ǿ���·����Ҳ���������·����
  *   			   2.���ļ���һ��Ҫ���ڲ����ǿ�д�ģ���Ϊ���ؿ���Ҫ�ڴ��ļ��д����ļ���
  *                    3.����������������ؿⱻ��ʼ���󣬴�������֮ǰ���á�
  */
ETDLL_API  int32 et_set_download_record_file_path(const char *path,u32  path_len);


/*
  * �������������,����1�������16�������򣬷���4112����
  *                   
  */
ETDLL_API int32 et_set_max_tasks(u32 task_num);

/*
  * ��ȡ���������
  *  
  * ע�⣺������-1����ʾ���ؿ⻹û�б���ʼ����
  */
ETDLL_API u32 et_get_max_tasks(void);


/*
  * ������������ٶȺ��ϴ��ٶ�,��KBΪ��λ,-1��ʾ������
  *                   
  * ע�⣺1.download_limit_speed��upload_limit_speedΪ���ؿ����н��յ��ͷ���ȥ����������������������������ĸ���ͨ��ָ���Ҫ���ص��ļ����ݣ�
  *			��ˣ�������ֵ���������̫С����Ϊupload_limit_speed���õ�̫С������Ӱ�������ٶȣ��ò���ʧ!
  *			2.������ֵ��������Ϊ0�����򷵻�4112 ����
  *			3.���û������Ҫ�󣬽��鲻Ҫ��������ӿڣ���Ϊ���ؿ�������Դ״������ѡ����ʵ��ٶȡ�
  *			4.������ؿ�����root�ʻ����еĻ������ؿ⻹���������״�����е������غ��ϴ��ٶȣ��ﵽ�������٣�
  *			�����ͻ��ڱ��ֺ���������ٶȵ�ͬʱ�ֲ�Ӱ��ͬһ���������������Ե������ٶȡ�
 */
ETDLL_API int32 et_set_limit_speed(u32 download_limit_speed, u32 upload_limit_speed);

/*
  * ��ȡ����ٶ�,��KBΪ��λ
  *                   
  */
ETDLL_API int32 et_get_limit_speed(u32* download_limit_speed, u32* upload_limit_speed);


/*
  * �����������������
  *                   
  * ע�⣺connection_num ��ȡֵ��ΧΪ[1~200]�����򷵻�4112 �������û������Ҫ�󣬽��鲻Ҫ�������
  *       		�ӿڣ���Ϊ���ؿ�������Դ״������ѡ����ʵ���������
  */
ETDLL_API int32 et_set_max_task_connection(u32 connection_num);

/*
  * ��ȡ�������������
  *                   
  * ע�⣺������-1����ʾ���ؿ⻹û�б���ʼ����
  */
ETDLL_API u32 et_get_max_task_connection(void);

/*
 * ��ȡ�ײ������ٶ�
 * ע�⣺�ײ������ٶ�Ϊ���ؿ����н��յ�����������������������������ĸ���ͨ��ָ���Ҫ���ص��ļ����ݣ�
 *			��ˣ�����ٶ�ͨ���Ǵ��ڻ��������������et_get_task_info��ET_TASK�ṹ���е������ٶ�(_speed)֮��!                   
 *
 */
ETDLL_API u32 et_get_current_download_speed(void);


/*
 * ��ȡ�ײ��ϴ��ٶ�
  * ע�⣺�ײ��ϴ��ٶ�Ϊ���ؿ����з���ȥ����������������������������ĸ���ͨ��ָ��͵�Ե�Э������ļ������ϴ���
  *			��ˣ�����ٶ�ͨ���Ǵ��ڻ��������������et_get_task_info��ET_TASK�ṹ���е��ϴ��ٶ�(_ul_speed)֮��!                   
 *
 */
ETDLL_API u32 et_get_current_upload_speed(void);


/*
  * �õ����ؿ��ڵ�ǰ���е�task��id��*buffer_lenΪtask_id_buffer�ĳ��ȣ���*buffer_len����ʱ������4115������*buffer_len������ȷ�ĳ��ȡ� 
  * ����ֵ: 0    �ɹ�
                        4112 ��������buffer_len��task_id_buffer����Ϊ��
                        4113 ��ǰû���κ�����
                        4115 buffer��������Ҫ������buffer size
  *
  * ע�⣺�������4115����ʾ�����task_id_buffer����������Ҫ���´�������buffer��
  *                 
  */
ETDLL_API int32 et_get_all_task_id(  u32 *buffer_len, u32 *task_id_buffer );



/*--------------------------------------------------------------------------*/
/*              task��ؽӿ�			        
----------------------------------------------------------------------------*/
/*
  * ����url���ص�������
  * ����ֵ: 0    �ɹ���task_id ��ʶ�ɹ�����������
                        4103 �Ѿ��������������
			   4119 ������ͻ������Ѹ�����ؿ�ͬһʱ��ֻ�ܴ���һ������Ĵ�����ɾ��������û���ͬʱ������/��ɾ�����������ϵ����񣬻��г�ͻ��                       
			   4200  �Ƿ�url
                        4201  �Ƿ�path
                        4202 �Ƿ�filename
                        4216 �Ѿ�����һ��������ͬurl���������
                        4222 ��Ҫ���ص��ļ��Ѿ�����

  *                   
  * ע�⣺1.����url��file_path�в���ΪNULL����Ӧ��url_length��file_path_lenҲ����Ϊ0������url_length���
  *       ���ܳ���511�ֽڣ�file_path_len���ܳ���255�ֽ�,Ҫȷ��file_pathΪ�Ѵ��ڵ�·��(����·�������·������)������file_path��ĩβҪ���ַ�'/'��
  *       ����ref_url��descriptionҪ��û�еĻ��ɵ���NULL,��Ӧ��ref_url_length��description_lenҲ��Ϊ0���еĻ�ref_url_length��description_len���ܴ���511��
  *       ����file_nameҲ��Ϊ�ջ�file_name_length����0����������£�Ѹ�׽���url�н������ļ���������еĻ�file_nameҪ����linux�ļ�������������file_name_length���ܴ���255��
  *       2.Ŀǰֻ�ܽ���"http://","https://","ftp://"��"thunder://"��ͷ��url.
  *       3.֧�ִ���Ѹ�׿���vodר��url����������url�ĸ�ʽ���£���/�ָ��ֶΣ���
		�汾��0
			http://host:port/version/gcid/cid/file_size/head_size/index_size/bitrate/packet_size/packet_count/tail_pos/url_mid/filename
		�汾��1
			http://host:port/version/gcid/cid/file_size/head_size/index_size/bitrate/packet_size/packet_count/tail_pos/��չ���б�/url_mid/filename

		host:port			ΪCDN��Ⱥ����������pubnet1.sandai.net:80
		version			��vod url�İ汾�ţ� ��ǰ0/1
		gcid				�ļ���gcid��Ϣ��ʮ�����Ʊ���
		cid				�ļ���cid��Ϣ��ʮ�����Ʊ���
		file_size 			�ļ���С, ʮ�����Ʊ���
		head_size 		ͷ�����ݴ�С, ʮ�����Ʊ���
		index_size 		�������С, ʮ�����Ʊ���
		bitrate			������(bit) , ʮ�����Ʊ���
		packet size 	����С , ʮ�����Ʊ��� 
		packet_count 	��������ʮ�����Ʊ���
		tail_pos   		β����ʼλ�ã�ʮ�����Ʊ���
		url_mid 		У����
		url_mid ��ʾgcid[20] + cid[20] + file_size[8]����MD5��ϣ���ٽ���ʮ�����Ʊ���õ�
		filename 			�ļ���, ��1.wmv
		��չ���б� 		��չ��/��չ��/.../ext_mid, ��/�ָ���չ��
		��һ����չ����custno���ͻ��ţ�����url��Ϊ�ͻ����е�
		ext_mid ��ʾ������չ��+url_mid����MD5��ϣ���ٽ���ʮ�����Ʊ���õ�
  */
ETDLL_API int32 et_create_new_task_by_url(char* url, u32 url_length, 
							  char* ref_url, u32 ref_url_length,
							  char* description, u32 description_len,
							  char* file_path, u32 file_path_len,
							  char* file_name, u32 file_name_length, 
							  u32* task_id);


/*
  * ����url���صĶϵ���������Ҫ��cfg�����ļ����ڣ����򴴽�����ʧ��
  * ����ֵ: 0    �ɹ���task_id ��ʶ�ɹ�����������       
                        4103 �Ѿ��������������
			   4119 ������ͻ������Ѹ�����ؿ�ͬһʱ��ֻ�ܴ���һ������Ĵ�����ɾ��������û���ͬʱ������/��ɾ�����������ϵ����񣬻��г�ͻ��                       
                        4199  ��Ӧ��.cfg�ļ�������
                        4200  �Ƿ�url
                        4201  �Ƿ�path
                        4202 �Ƿ�filename
                        4216 �Ѿ�����һ��������ͬurl���������
                        4222 ��Ҫ���ص��ļ��Ѿ����ڣ�û��Ҫ����
                        6159 cfg�ļ��Ѿ����ٻ��������ϵ���������ʧ��
  * 
  * ע�⣺1.����url,file_path��file_name�в���ΪNULL����Ӧ��url_length��file_path_len��file_name_length
  *       Ҳ����Ϊ0������url_length����ܳ���511�ֽڣ�file_path_len��file_name_length���ܳ���255�ֽ�,Ҫȷ��file_nameҪ����linux�ļ�������������file_pathΪ�Ѵ��ڵ�·��(����·�������·������)������file_path��ĩβҪ���ַ�'/'��
  *       ����ref_url��descriptionҪ��û�еĻ��ɵ���NULL,��Ӧ��ref_url_length��description_lenҲ��Ϊ0���еĻ�ref_url_length��description_len���ܴ���511��
  *       ���⣬file_name��Ӧ��td�ļ���td.cfg�ļ�һ��Ҫ���ڡ�
  *       2.Ŀǰֻ�ܽ���"http://","https://","ftp://"��"thunder://"��ͷ��url.
  *       3.������Ҫ�ر�ע����ǣ�����file_nameҪ�����������et_create_new_task_by_url����ʱ�����file_name_for_user���ļ�������һ�£��������ļ�����չ�����ܱ����ؿ��Զ��޸ģ�
  		���Ϊ��ȷ�����ؿ�����������������ʱ��׼ȷ���ҵ���֮��Ӧ��.td��.td.cfg�ļ�,һ���Ƚϱ��յķ�����������et_create_new_task_by_url���������ʱ�򣬵�������Ϣ�е�
  		ET_TASK�ṹ���е�_file_create_statusΪET_FILE_CREATED_SUCCESS��ʱ�򣬵���et_get_task_file_name�����õ�����������ļ�������ȥ����׺.td����õ�������������ʱ����ȷ�ļ���.
  *       4.֧��������Ѹ�׿���vodר��url����������
 */
ETDLL_API int32 et_create_continue_task_by_url(char* url, u32 url_length, 
								   char* ref_url, u32 ref_url_length,
								   char* description, u32 description_len,
								   char* file_path, u32 file_path_len,
								   char* file_name, u32 file_name_length,
								   u32* task_id);



/*
  * ����cid���ص�������
  * ����ֵ: 0    �ɹ���task_id ��ʶ�ɹ�����������
                        4103 �Ѿ��������������
 			   4119 ������ͻ������Ѹ�����ؿ�ͬһʱ��ֻ�ܴ���һ������Ĵ�����ɾ��������û���ͬʱ������/��ɾ�����������ϵ����񣬻��г�ͻ��                       
                        4201  �Ƿ�path
                        4202 �Ƿ�filename
                        4205 �Ƿ�cid
                        4216 �Ѿ�����һ����ͬ���������
                        4222 ��Ҫ���ص��ļ��Ѿ�����
  *                   
  * ע�⣺1.����tcid(content-id)Ϊ20�ֽڵ�ʮ���������ִ�������ΪNULL;file_name��file_pathҲ����ΪNULL����Ӧ�� 
  *       file_name_length��file_path_lenҲ����Ϊ0������file_path_len��file_name_length���ܳ���255�ֽ�,Ҫȷ��file_nameҪ����linux�ļ�������������file_pathΪ�Ѵ��ڵ�·��(����·�������·������)������file_path��ĩβҪ���ַ�'/'��
  *       ����file_sizeҪ�ǲ�֪���Ļ��ɵ���0,���в��ɺ�����һ�������ֵ����Ϊ�����ᵼ���޷����أ�
  */
ETDLL_API int32 et_create_new_task_by_tcid(u8 *tcid, uint64 file_size, char *file_name, u32 file_name_length, char *file_path, u32 file_path_len, u32* task_id );

/*
  * ����cid���ص���������
  * ����ֵ: 0    �ɹ���task_id ��ʶ�ɹ�����������
                        4103 �Ѿ��������������
 			   4119 ������ͻ������Ѹ�����ؿ�ͬһʱ��ֻ�ܴ���һ������Ĵ�����ɾ��������û���ͬʱ������/��ɾ�����������ϵ����񣬻��г�ͻ��                       
                           4199  ��Ӧ��.cfg�ļ�������
                    4201  �Ƿ�path
                        4202 �Ƿ�filename
                        4205 �Ƿ�cid
                         4216 �Ѿ�����һ����ͬ���������
                        4219 ��ȡcid�����п����Ǵ�.cfg�еò���cid��õ���cid�������cid��һ��
                       4222 ��Ҫ���ص��ļ��Ѿ����ڣ�û��Ҫ����
                        6159 cfg�ļ��Ѿ����ٻ��������ϵ���������ʧ��
  *                   
  * ע�⣺1.����tcid(content-id)Ϊ20�ֽڵ�ʮ���������ִ�������ΪNULL;file_name,file_pathҲ����ΪNULL����Ӧ��  
  *       file_name_length��file_path_lenҲ����Ϊ0������file_path_len��file_name_length���ܳ���255�ֽ�,Ҫȷ��file_pathΪ�Ѵ��ڵ�·��(����·�������·������)������file_path��ĩβҪ���ַ�'/'��
  *       ���⣬file_name��Ӧ��td�ļ���td.cfg�ļ�һ��Ҫ���ڡ�
  *       2.������Ҫ�ر�ע����ǣ�����file_nameҪ�����������et_create_new_task_by_tcid����ʱ�����file_name���ļ�������һ�£��������ļ�����չ�����ܱ����ؿ��Զ��޸ģ�
  		���Ϊ��ȷ�����ؿ�����������������ʱ��׼ȷ���ҵ���֮��Ӧ��.td��.td.cfg�ļ�,һ���Ƚϱ��յķ�����������et_create_new_task_by_tcid���������ʱ�򣬵�������Ϣ�е�
  		ET_TASK�ṹ���е�_file_create_statusΪET_FILE_CREATED_SUCCESS��ʱ�򣬵���et_get_task_file_name�����õ�����������ļ�������ȥ����׺.td����õ�������������ʱ����ȷ�ļ���.
  */
ETDLL_API int32 et_create_continue_task_by_tcid(u8 *tcid, char*file_name, u32 file_name_length, char*file_path, u32 file_path_len, u32* task_id );


/*
  * ����cid+file_size+gcid���ص�����
  * ����ֵ: 0    �ɹ���task_id ��ʶ�ɹ�����������
                        4103 �Ѿ��������������
 			   4119 ������ͻ������Ѹ�����ؿ�ͬһʱ��ֻ�ܴ���һ������Ĵ�����ɾ��������û���ͬʱ������/��ɾ�����������ϵ����񣬻��г�ͻ��                       
                        4201  �Ƿ�path
                        4202 �Ƿ�filename
                        4205 �Ƿ�cid
                         4216 �Ѿ�����һ����ͬ���������
                        4222 ��Ҫ���ص��ļ��Ѿ�����
  *                   
  * ע�⣺1.����tcid(content-id)Ϊ20�ֽڵ�ʮ���������ִ�������ΪNULL;file_name��file_pathҲ����ΪNULL����Ӧ�� 
  *       file_name_length��file_path_lenҲ����Ϊ0������file_path_len��file_name_length���ܳ���255�ֽ�,Ҫȷ��file_nameҪ����linux�ļ�������������file_pathΪ�Ѵ��ڵ�·��(����·�������·������)������file_path��ĩβҪ���ַ�'/'��
  *       ����file_sizeһ��Ҫ��ȷ��ֵ���в��ɵ���0,Ҳ���ɺ�����һ�������ֵ����Ϊ�����ᵼ���޷����أ�
  */
ETDLL_API int32 et_create_task_by_tcid_file_size_gcid(u8 *tcid, uint64 file_size, u8 *gcid,char *file_name, u32 file_name_length, char *file_path, u32 file_path_len, u32* task_id );


/*
 * ����bt��������(�ýӿ��Ѿ���et_create_bt_taskȡ��)
*/
ETDLL_API int32 et_create_new_bt_task(char* seed_file_full_path, u32 seed_file_full_path_len, 
								char* file_path, u32 file_path_len,
								u32* download_file_index_array, u32 file_num,
								u32* task_id);



/* 
 * ����bt����������½ӿ�(������Ͷϵ����������ʹ�ô˽ӿڣ���ȡ��et_create_new_bt_task�ӿ�
 *                        �ഫ��һ������seed_switch_type )
 * ����ֵ: 0     �ɹ���task_id ��ʶ�ɹ�����������
 *		   15361 �����ļ�������
 * 		   15362 �����ļ�����ʧ��
 *		   15363 �����ļ�����֧�ֽ���(�����ļ���С����2G)
 *		   15364 �����ļ������ļ���ŷǷ�
 *         15365 bt���ر�����
 *         15367 �����ļ���ȡ����
 *         15368 ��֧�ֵ������ļ���Ϣ������ͣ�ֻ֧��gbk��utf-8��big5
 *		   15369 �ײ㲻֧��gbkתutf-8
 *		   15370 �ײ㲻֧��gbkתbig5
 *		   15371 �ײ㲻֧��utf-8תgbk
 *		   15372 �ײ㲻֧��utf-8תbig5
 *		   15373 �ײ㲻֧��big5תgbk
 *		   15374 �ײ㲻֧��big5תutf-8
 *		   15375 �����ļ�û��utf-8�ֶΡ�(�������������ʽ����ΪET_ENCODING_UTF8_PROTO_MODEʱ����
 *		   15376 �ظ����ļ��������
                 15400 ���ļ�����ʧ��
 *		   4112  �Ƿ������������ļ�ȫ·�����ļ�����Ŀ¼·��Ϊ�ջ�̫��
                 4201  file_path�Ƿ�
                4216 �Ѿ�����һ����ͬ���������
  *		   2058  �ð汾�����ؿⲻ֧��BT����
 * ע�⣺1.����seed_file_full_path��*.torrent�ļ�����ȫ·��������·�������·�����ɣ�����ΪNULL, ���Ȳ��ɴ���256+255��
            file_path���ļ����غ��ŵ�·����Ҳ����ΪNULL, ���Ȳ��ɴ���255
  *         ��Ӧ��seed_file_full_path_len��file_path_lenҲ����Ϊ0��ͬʱҪȷ��file_pathΪ�Ѵ��ڵ�·��(����·�������·������)��
  *         ����file_path��ĩβҪ���ַ�'/'��
  *        2.download_file_index_array���û�ѡ�����Ҫ���ص��ļ�������飬file_numΪ�����ڰ������ļ��������ļ���Ų��ܳ�����������ӵ��ļ�������
  *        3.seed_switch_type�������õ�������������ļ����������ʽ
  *                          0 ����ԭʼ�ֶ�
  *                          1 ����GBK��ʽ���� 
  *                          2 ����UTF-8��ʽ����
  *                          3 ����BIG5��ʽ���� 
  *				  4 ���������ļ��е�utf-8�ֶ�
  *				  5 δ���������ʽ(ʹ��et_set_seed_switch_type��ȫ���������)  
  */

ETDLL_API int32 et_create_bt_task(char* seed_file_full_path, u32 seed_file_full_path_len, 
								char* file_path, u32 file_path_len,
								u32* download_file_index_array, u32 file_num,
								enum ET_ENCODING_SWITCH_MODE encoding_switch_mode, u32* task_id);

/* 
 * ����emule����������½ӿ�(������Ͷϵ����������ʹ�ô˽ӿ� )
 * ����ֵ: 0     �ɹ���task_id ��ʶ�ɹ�����������
 *		   4103 �Ѿ��������������
 *         4112  �Ƿ�������emule����Ϊ�ջ�̫��,ȫ·�����ļ�����Ŀ¼·��Ϊ�ջ�̫��
           4201  file_path�Ƿ�
           4216 �Ѿ�����һ����ͬ���������
  *		   2058  �ð汾�����ؿⲻ֧��emule����
 *         20482 �Ƿ���ed2k_link
 * ע�⣺1 ed2k_link��emule���ص�����,����ΪNULL,���Ȳ��ɳ���2048
 *       2 path���ļ����غ��ŵ�·����Ҳ����ΪNULL, ���Ȳ��ɴ���255
  *         ��Ӧ��seed_file_full_path_len��file_path_lenҲ����Ϊ0��ͬʱҪȷ��file_pathΪ�Ѵ��ڵ�·��(����·�������·������)��
  *         ����file_path��ĩβҪ���ַ�'/'��
  */

ETDLL_API int32 et_create_emule_task(const char* ed2k_link, u32 ed2k_link_len, char* path, u32 path_len, 
    char* file_name, u32 file_name_length, u32* task_id );


/*
  * ��������Ϊ����������ν�������񣬾��Ǹ�������Ȼ�������ݣ���ȴ��д��������
   * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4113 ��ǰû�п����е�����
                        4116 �������Ͳ���ȷ����������ΪBT����Ҳ����Ϊ��������
			   4117  ����״̬����ȷ���п����Ǹ������Ѿ�start��
 *                   
 * ע�⣺1.�ýӿ�һ��Ҫ��et_start_task֮ǰ���÷�����Ч��
 			2.�ýӿ�ֻ����vod�㲥����
 			3.����һ��������Ϊ�������񣬽���������Ϊ���̡�
 			4.�ýӿ�ֻ�������´��������񣬶�����������������
  */
ETDLL_API int32 et_set_task_no_disk(u32 task_id);

/*
  * ��������Ϊ��ҪУ�������ݲŸ���������������
   * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4113 ��ǰû�п����е�����
                        4116 �������Ͳ���ȷ����������ΪBT����Ҳ����Ϊ��������
			   4117  ����״̬����ȷ���п����Ǹ������Ѿ�start��
 *                   
 * ע�⣺1.�ýӿ�һ��Ҫ��et_start_task֮ǰ���÷�����Ч��
 			2.�ýӿ�ֻ����vod�㲥����
  */
ETDLL_API int32 et_vod_set_task_check_data(u32 task_id);

/*
  * ����task_id ��ʶ������
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4113 ��ǰû�п����е�����
			   4117  ����״̬����ȷ���п����Ǹ������Ѿ�start����
                        4211  �Ƿ�GCID,��cid�����޷�����
  *                   
  */
ETDLL_API int32 et_start_task(u32 task_id);


/*
  * ֹͣtask_id ��ʶ������
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4110  task_id��ʶ���������������е�����,�޷�ֹͣ
                        4113  ��ǰû�п�ֹͣ������
  *                   
  * ע�⣺1.����et_stop_taskͣ��task֮�����ٵ���et_start_task�����ٴ�����task��������
  *       ����et_delete_task֮��ͨ������et_create_continue_task_by_xxx������������
  *       2.ֻҪ�ǵ���et_start_task��������������״̬��ʲô��RUNNING��VOD,SUCCESS, FAILED�����ڵ���
  *       et_delete_task֮ǰ���������et_stop_task������ֹͣ��
*/
ETDLL_API int32 et_stop_task(u32 task_id);

/*
  * ɾ��task_id ��ʶ������
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4109  task_id��ʶ������û��ֹͣ���޷�ɾ��
                        4113  ��ǰû�п�ɾ��������
 			   4119 ������ͻ������Ѹ�����ؿ�ͬһʱ��ֻ�ܴ���һ������Ĵ�����ɾ��������û���ͬʱ������/��ɾ�����������ϵ����񣬻��г�ͻ��                       
  *                   
  * ע�⣺����et_delete_task֮ǰҪȷ�������Ѿ���et_stop_taskֹͣ��
 */
ETDLL_API int32 et_delete_task(u32 task_id);


/*
  * ��ȡtask_id ��ʶ�������������Ϣ 
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4113 ��ǰû�����е�����
                        4112  ��Ч������ET_TASK *info ����Ϊ��
  */
ETDLL_API int32 et_get_task_info(u32 task_id, ET_TASK *info);

/*
  * ��ȡtask_id ��ʶ��������ļ��� ��ע�⣬���ʺ�BT����
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
			   4110  ����û������
 			   4112  �Ƿ�������file_name_buffer����Ϊ��
                        4113 ��ǰû�����е�����
                        4116 �������Ͳ��ԣ���������Ͳ���ΪBT����
                        4202 �޷���������ļ���,�п�������Ϊ�ļ�δ�����ɹ�(������Ϣ�е�_file_create_status ������ET_FILE_CREATED_SUCCESS)
                        4215 buffer_size��С
  *
  * ע�⣺1.�����ET_TASK_RUNNING״̬�µ��øýӿڣ����ص�Ϊ��ʱ�ļ���(*.td)��������ɹ�������򷵻������ļ�����
  *	  		buffer_sizeΪ��������������������buffer size��Сʱ���ӿڷ���4215�����˲���������ȷ������buffer size��
  *	  		2.�������������¼������жϣ���ͣ�磬�����ȣ�����Ҫ����ʱ��Ϊȷ������ʱ�������ļ�������ȷ�ģ�
  *			��������et_create_new_task_by_xxx����������ʱ����������Ϣ�е�_file_create_status һ������ET_FILE_CREATED_SUCCESS��
  *			���øýӿڻ���������ȷ�ļ����������������Ա������á�ע��������Ҫȥ���ļ�����׺.td�õ���ȷ���ļ����� 
   *	  		3.����Ѹ�����ؿ�������ļ��������һ����Ҫ˵����ע�⣬���ʺ�BT���񣩣�������������et_create_new_task_by_url��et_create_new_task_by_tcid�ӿڴ���һ���µ���������ʱ��ע�⣬����BT���񣩣�
  *			������������ļ���������file_name_for_user��file_name������������չ����ȷ����my_music.mp3���ģ������ؿ����»������ļ��ϸ��մ���ȥ��������������my_music.mp3����
  *			��������������ļ����ǿյģ�file_name_for_user��file_name����NULL�������������ã�����չ��û�л������my_music��my_music.m3p��,��Ѹ�����ؿ������������ҵ�����ȷ�ļ�������չ���Զ����ļ��������������������ļ���Ϊmy_music.mp3����
  *			��������£�Ϊȷ���������������ж϶���Ҫ����ʱ�������ļ�����ȷ��������Ҫ����et_create_new_task_by_url��et_create_new_task_by_tcid�ӿڴ���������ʱ����et_get_task_file_name�������ȷ�ļ����Ա���ʱ֮�衣
 */
ETDLL_API int32 et_get_task_file_name(u32 task_id, char *file_name_buffer, int32* buffer_size);
ETDLL_API int32 et_get_task_tcid(u32 task_id, u8 * tcid);



/*
  * ɾ��task_id ��ʶ�����������ļ�����Щ�ļ��п�������ʱ�ļ�������ʧ�ܻ������б���ֹ����Ҳ�п������Ѿ����ص���Ŀ���ļ�������ɹ����� 
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4109 ��ǰ������������
                        4113 ��ǰû�п�ִ�е�����
  *
  * ע�⣺�����Ҫ�ô˺���ɾ���������ʱ�ļ��Ļ���һ��Ҫ��et_stop_task֮��et_delete_task֮ǰ���ô˺�����
  *                  ��Ȼ������㲻��ɾ���������ʱ�ļ����ɲ����ô˺�����
  */
ETDLL_API int32 et_remove_task_tmp_file(u32 task_id);

/*
  * ɾ��ָ�����ļ���ƥ�����ʱ�ļ����� file_name.td��file_name.td.cfg�ļ��� 
  * ����ֵ: 0    �ɹ�
  *
  * ע�⣺��������ĵ����������޹ء�
  */
ETDLL_API int32 et_remove_tmp_file(char* file_path, char* file_name);



/*--------------------------------------------------------------------------*/
/*              BT����ר�ýӿ�			
 *
 *              ע�⣺����ⲿ�ֵĽӿں������ش�����Ϊ2058����ʾ�ð汾�����ؿⲻ֧��BT���أ�	
 *
----------------------------------------------------------------------------*/
/* ���������ļ�ȫ·��(����·���������ļ�������������ܳ���256+255�ֽ�)�����������ļ���Ϣ: pp_seed_info 
 * ����ֵ: 0    �ɹ�
 *		   15361 �����ļ�������
 * 		   15362 �����ļ�����ʧ��
 *		   15363 �����ļ�����֧�ֽ���(�����ļ���С����2G)
 *		   15364 �����ļ������ļ���ŷǷ�
 *         15365 bt���ر�����
 *         15366 bt���ز�֧�ֵ�ת������
 *         15367 �����ļ���ȡ����
 *         15368 ��֧�ֵ������ļ���Ϣ������ͣ�ֻ֧��gbk��utf-8��big5
 *		   15369 �ײ㲻֧��gbkתutf-8
 *		   15370 �ײ㲻֧��gbkתbig5
 *		   15371 �ײ㲻֧��utf-8תgbk
 *		   15372 �ײ㲻֧��utf-8תbig5
 *		   15373 �ײ㲻֧��big5תgbk
 *		   15374 �ײ㲻֧��big5תutf-8
 *		   15375 �����ļ�û��utf-8�ֶΡ�(�������������ʽ����ΪET_ENCODING_UTF8_PROTO_MODEʱ����
 *         4112  �Ƿ������������ļ�ȫ·������256+255�ֽڻ�����ַ���
 * ע�⣺1�_info_hashΪ2��ֵ���룬��ʾ���Լ�ת��Ϊhex��ʽ��
 *       2  �����et_release_torrent_seed_info�ɶ�ʹ�á�
 *       3  _encoding�ֶ�����: GBK = 0, UTF_8 = 1, BIG5 = 2
 *       4  �൱�ڵ���et_get_torrent_seed_info_with_encoding_mode����encoding_switch_mode=ET_ENCODING_DEFAULT_SWITCH
 */
 
ETDLL_API int32 et_get_torrent_seed_info( char *seed_path, ET_TORRENT_SEED_INFO **pp_seed_info );




/* ��et_get_torrent_seed_info�����ϣ�����encoding_switch_mode�ֶΣ������������ӱ��������ʽ
 * ���������ļ�ȫ·��(����·���������ļ�������������ܳ���256+255�ֽ�)�����������ļ���Ϣ: pp_seed_info 
 * ����ֵ: 0    �ɹ�
 *		   15361 �����ļ�������
 * 		   15362 �����ļ�����ʧ��
 *		   15363 �����ļ�����֧�ֽ���(�����ļ���С����2G)
 *		   15364 �����ļ������ļ���ŷǷ�
 *         15365 bt���ر�����
 *         15366 bt���ز�֧�ֵ�ת������
 *         15367 �����ļ���ȡ����
 *         15368 ��֧�ֵ������ļ���Ϣ������ͣ�ֻ֧��gbk��utf-8��big5
 *		   15369 �ײ㲻֧��gbkתutf-8
 *		   15370 �ײ㲻֧��gbkתbig5
 *		   15371 �ײ㲻֧��utf-8תgbk
 *		   15372 �ײ㲻֧��utf-8תbig5
 *		   15373 �ײ㲻֧��big5תgbk
 *		   15374 �ײ㲻֧��big5תutf-8
 *		   15375 �����ļ�û��utf-8�ֶΡ�(�������������ʽ����ΪET_ENCODING_UTF8_PROTO_MODEʱ����
 *         4112  �Ƿ������������ļ�ȫ·������256+255�ֽڻ�����ַ���
 * ע�⣺1)�_info_hashΪ2��ֵ���룬��ʾ���Լ�ת��Ϊhex��ʽ��
 *       2)  �����et_release_torrent_seed_info�ɶ�ʹ�á�
 *       3)  _encoding�ֶ�����: GBK = 0, UTF_8 = 1, BIG5 = 2
 *       4)  seed_switch_type�������õ�������������ļ����������ʽ?
 * 				0 ����ԭʼ�ֶ�
 * 				1 ����GBK��ʽ���� 
 * 				2 ����UTF-8��ʽ����
 * 				3 ����BIG5��ʽ���� 
 * 				4 ���������ļ��е�utf-8�ֶ�
 * 				5 δ���������ʽ(ʹ��et_set_seed_switch_type��ȫ���������)  
*/

ETDLL_API int32 et_get_torrent_seed_info_with_encoding_mode( char *seed_path, enum ET_ENCODING_SWITCH_MODE encoding_switch_mode, ET_TORRENT_SEED_INFO **pp_seed_info );


/* �ͷ�ͨ��et_get_torrent_seed_info�ӿڵõ��������ļ���Ϣ��
 * ע�⣺�����et_get_torrent_seed_info�ɶ�ʹ�á�
 */
ETDLL_API int32 et_release_torrent_seed_info( ET_TORRENT_SEED_INFO *p_seed_info );


/* torrent�ļ���GBK,UTF8,BIG5���뷽ʽ��Ĭ�������switch_type=0���ؿⲻ�����ӱ������ת�����û����Ը���
 * et_get_torrent_seed_info�ӿڵõ������ļ������ʽ������Ӧ��������ʾ����
 * ���û���Ҫָ�����������ʽʱʹ�ô˽ӿڣ��������������ļ���ʽ��UTF8,
 * �û�ϣ�����ؿ���GBK��ʽ�������Ҫ����et_set_enable_utf8_switch(1)
 * switch_type: 
 * 				0 ����ԭʼ�ֶ�
 * 				1 ����GBK��ʽ���� 
 * 				2 ����UTF-8��ʽ����
 * 				3 ����BIG5��ʽ���� 
 * 				4 ���������ļ��е�utf-8�ֶ�
 * 				5 δ���������ʽ(ʹ��ϵͳĬ���������:GBK_SWITCH) 
 * ����ֵ: 0    �ɹ�
 *         15366 ����ϵͳ��֧��(ϵͳ��֧��ICONV��������)
 *         15368 ��֧�ֵı����ʽת������switch_type����0��1��2
 */
ETDLL_API int32 et_set_seed_switch_type( enum ET_ENCODING_SWITCH_MODE switch_type );


/*
  * �õ�task_id ��ʶ��BT�����������Ҫ���ص��ļ���id��*buffer_lenΪfile_index_buffer�ĳ��ȣ���*buffer_len����ʱ������4115������*buffer_len������ȷ�ĳ��ȡ� 
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4112 ��������buffer_len��file_index_buffer����Ϊ��
                        4113 ��ǰû�п�ִ�е�����
                        4115 buffer��������Ҫ������buffer size
                        4116 ������������ͣ�task_id ��ʶ��������BT����
  *
  * ע�⣺�������4115����ʾ�����file_index_buffer����������Ҫ���´�������buffer��
  *                 
  */
ETDLL_API int32 et_get_bt_download_file_index( u32 task_id, u32 *buffer_len, u32 *file_index_buffer );

/*
  * ��ȡtask_id ��ʶ��bt�����У��ļ����Ϊfile_index����Ϣ������� ET_BT_FILE�ṹ�С�
  * ����ֵ: 0    �ɹ�
                        1174  �ļ���Ϣ���ڸ����У���ʱ���ɶ������Ժ�����!
                        4107  �Ƿ�task_id
                        4113 ��ǰû�����е�����
                        4112  ��Ч������ET_BT_FILE *info ����Ϊ��    
                        15364 �����ļ���ŷǷ�
  */
ETDLL_API int32 et_get_bt_file_info(u32 task_id, u32 file_index, ET_BT_FILE *info);

/*
  * ��ȡtask_id ��ʶ��bt�����У��ļ����Ϊfile_index���ļ���·��������Ŀ¼�ڣ����ļ�����
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        4112  ��Ч������file_path_buffer��file_name_buffer ����Ϊ��,*file_path_buffer_size��*file_name_buffer_size ����С��256    
                        4113 ��ǰû�����е�����
                        4116 �������Ͳ��ԣ����������Ӧ��ΪBT����
                        1424 buffer_size��С
                        15364 �����ļ���ŷǷ�
  * ע��: 1.����buffer�ĳ���*buffer_size ������С��256��
	  	    2.���ص�·��Ϊ����Ŀ¼�ڵ�·��������ļ��ڴ��̵�·��Ϊc:/tddownload/abc/abc_cd1.avi ,�����û�ָ��������Ŀ¼Ϊc:/tddownload���򷵻ص�·��Ϊabc/  
          	    3.���ص�·�����ļ����ı��뷽ʽ���û��ڴ���������ʱ�����encoding_switch_mode��ͬ��
	  	    4.�����������1424������������Ҫ���*file_path_buffer_size��*file_name_buffer_size�Ƿ�С��256�����������µ��øú������ɡ�
  */
ETDLL_API int32 et_get_bt_file_path_and_name(u32 task_id, u32 file_index,char *file_path_buffer, int32 *file_path_buffer_size, char *file_name_buffer, int32* file_name_buffer_size);


/*--------------------------------------------------------------------------*/
/*              VOD�㲥ר�ýӿ�			        
 *
 *              ע�⣺����ⲿ�ֵĽӿں������ش�����Ϊ2058����ʾ�ð汾�����ؿⲻ֧��VOD���ܣ�	
 *
----------------------------------------------------------------------------*/
/*
  * ����HTTP��ʽ�㲥��Ҫ��HTTP���񣬲���Ϊ�˿ںš�
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
     ��HTTP SERVER�����󣬿ɹ��������㲥���㲥URL��ʽ��http://ip:port/task_id_file_index.rmvb
     ip �����д˳����IP
     port ������Ķ˿ں�
     task_id ��Ҫ�㲥������ID
     file_index�������е��ļ�������BT������Ч����ͨ�������
     rmvb ��ý���ļ����ͣ�����Ϊwmv avi�ȣ���Ҫ��ĳЩ��������Ҫ�ļ�����׺ʹ��
  */
ETDLL_API int32 et_start_http_server(u16 port);

/*
  * ֹͣHTTP��ʽ�㲥��Ҫ��HTTP����
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
  */
ETDLL_API int32 et_stop_http_server(void);

/*
  * API��ʽ��ȡVOD���ݡ�����Ϊ����ID����ʼλ�ã���ȡ���ȣ���������ַ������ʱ��(��λ����)��
  �����ȡ����16*1024,�ﵽ���Ż�ȡ�ٶ�,��ʱ500,1000����
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        18534 ��ȡ�����ڽ�����
                        18535 �������ж�
                        18536 ��ȡ���ݳ�ʱ
                        18537 δ֪����������
                        18538 �ڴ�̫��
                        18539 ���ڻ�ȡ����״̬
                        18540 �����Ѿ�ֹͣ
                        18541 ��������
  */
ETDLL_API int32 et_vod_read_file(int32 task_id, uint64 start_pos, uint64 len, char *buf, int32 block_time );

/*
  * API��ʽ��ȡBT VOD���ݡ�����Ϊ����ID����ʼλ�ã���ȡ���ȣ���������ַ������ʱ��(��λ����)��
  * ����ֵ: 0    �ɹ�
                        4107  �Ƿ�task_id
                        18534 ��ȡ�����ڽ�����
                        18535 �������ж�
                        18536 ��ȡ���ݳ�ʱ
                        18537 δ֪����������
                        18538 �ڴ�̫��
                        18539 ���ڻ�ȡ����״̬
                        18540 �����Ѿ�ֹͣ
                        18541 ��������
*/
ETDLL_API int32 et_vod_bt_read_file(int32 task_id, u32 file_index, uint64 start_pos, uint64 len, char *buf, int32 block_time );

/*
���û���ʱ�䣬��λ��,Ĭ��Ϊ30�뻺��,���������ø�ֵ,�Ա�֤��������
 * ����ֵ: 0    �ɹ�
                       2058 �޴˹���
*/
ETDLL_API int32 et_vod_set_buffer_time(int32 buffer_time );


/*
�õ�����ٷֱ�
����start����֮��,�ٵ���et_vod_read_file�󣬵��øú������ܵõ����
 * ����ֵ: 0    �ɹ�
                       2058 �޴˹���
                        4107  �Ƿ�task_id
                        18537 δ֪����������
                        18540 �����Ѿ�ֹͣ
*/
ETDLL_API int32 et_vod_get_buffer_percent(int32 task_id,  int32* percent );


/*
���ص㲥�ڴ��С
 * ����ֵ: 0    �ɹ�
                       2058 �޴˹���
*/
ETDLL_API int32 et_vod_get_vod_buffer_size(int32* buffer_size);


/*
���õ㲥�ڴ��С,�����ڵ㲥�ڴ滹δ����ʱ�������ã����򷵻�ʧ��
 * ����ֵ: 0    �ɹ�
                       2058 �޴˹���
                       18401 ���е㲥����
                       18411 �㲥�ڴ��Ѿ�����
                       18412 �㲥�ڴ����ù�С,����С��2M
*/
ETDLL_API int32 et_vod_set_vod_buffer_size(int32 buffer_size);

/*
���ص㲥�ڴ��Ƿ��Ѿ�����
 * ����ֵ: 0    �ɹ�
                       2058 �޴˹���
*/
ETDLL_API int32 et_vod_is_vod_buffer_allocated(int32* allocated);

/*
�ͷŵ㲥�ڴ�,���������е㲥�����˳�ɾ��֮��,���򷵻ش���
 * ����ֵ: 0    �ɹ�
                       2058 �޴˹���
                       18401 ���е㲥����
*/
ETDLL_API int32 et_vod_free_vod_buffer(void);

/*
�жϵ㲥���������Ƿ���ɣ������ж��Ƿ���Կ�ʼ������һ����Ӱ
 * ����ֵ: 0    �ɹ�
                       2058 �޴˹���
                        4107  �Ƿ�task_id
                        18537 δ֪����������
                        18540 �����Ѿ�ֹͣ
*/
ETDLL_API int32 et_vod_is_download_finished(int32 task_id, BOOL* finished );

/*
����log�����ļ�·��,Ҫ��et_init����֮ǰ����
 * ����ֵ: 0    �ɹ�
                       2058 �޴˹���
*/
ETDLL_API int32 et_set_log_conf_path(const char* path);

/*
��ȡ����ThreadID
*/
ETDLL_API int32 et_get_task_ids(int32* p_task_count, int32 task_array_size, char* task_array);

/*--------------------------------------------------------------------------*/
/*             �����û��Զ���ĵײ�ӿ�
----------------------------------------------------------------------------*/
#define ET_FS_IDX_OPEN           (0)
#define ET_FS_IDX_ENLARGE_FILE   (1)
#define ET_FS_IDX_CLOSE          (2)
#define ET_FS_IDX_READ           (3)
#define ET_FS_IDX_WRITE          (4)
#define ET_FS_IDX_PREAD          (5)
#define ET_FS_IDX_PWRITE         (6)
#define ET_FS_IDX_FILEPOS        (7)
#define ET_FS_IDX_SETFILEPOS     (8)
#define ET_FS_IDX_FILESIZE       (9)
#define ET_FS_IDX_FREE_DISK      (10)

#define ET_SOCKET_IDX_SET_SOCKOPT (11)

#define ET_MEM_IDX_GET_MEM           (12)
#define ET_MEM_IDX_FREE_MEM          (13)
#define ET_ZLIB_UNCOMPRESS      (14)
#define ET_FS_IDX_GET_FILESIZE_AND_MODIFYTIME   (15)
#define ET_FS_IDX_DELETE_FILE     (16)
#define ET_FS_IDX_RM_DIR              (17)
#define ET_FS_IDX_MAKE_DIR              (18)
#define ET_FS_IDX_RENAME_FILE              (19)
#define ET_SOCKET_IDX_CREATE         (20)
#define ET_SOCKET_IDX_CLOSE         (21)
#define ET_FS_IDX_FILE_EXIST      (22)
#define ET_DNS_GET_DNS_SERVER   (23)
#define ET_LOG_WRITE_LOG            (24)
/*
 * ���������û��Զ���ĵײ�ӿڣ������û������Լ�ʵ���ļ���д��������Ȼ���������ӿ����ý�����
 * �������÷�Χ�ڵ����⺯��ʵ�֡�����������ã����ؿ�����Ĭ�ϵ�ϵͳ�ӿ���ʵ�֡�
 * �����ڵ���et_init֮ǰ������ϣ����������ʧ��
 *
 * ����ֵ��0      �ɹ�
 *         3272   ��ŷǷ�
 *         3273   ����ָ����Ч
 *         3672   ���ؿ��Ѿ���ʼ�������˺�������Ҫ��et_init֮ǰ���У�
 *
 * �����б�˵����
 * int32 fun_idx    �ӿں��������
 * void *fun_ptr    �ӿں���ָ��
 *
 *
 *  Ŀǰ֧�ֵĽӿں�������Լ����Ӧ�ĺ�������˵����
 *
 *  ��ţ�0 (ET_FS_IDX_OPEN)      ����˵����typedef int32 (*et_fs_open)(char *filepath, int32 flag, u32 *file_id);
 *   ˵�������ļ�����Ҫ�Զ�д��ʽ�򿪡��ɹ�ʱ����0�����򷵻ش�����
 *   ����˵����
 *	 filepath����Ҫ���ļ���ȫ·���� 
 *	 flag��    ��(flag & 0x01) == 0x01ʱ���ļ������ڴ����ļ��������ļ�������ʱ��ʧ��
                                                                       ����ļ��������Զ�дȨ�޴��ļ�
                      ��(flag & 0x02) == 0x02ʱ����ʾ��ֻ���ļ�
                      ��(flag & 0x04) == 0x04ʱ����ʾ��ֻд
                      ��(flag ) = 0x 0ʱ����ʾ��дȨ�޴��ļ�
 *	 file_id�� �ļ��򿪳ɹ��������ļ����
 *
 *  ��ţ�1 (ET_FS_IDX_ENLARGE_FILE)  ����˵����typedef int32 (*et_fs_enlarge_file)(u32 file_id, uint64 expect_filesize, uint64 *cur_filesize);
 *   ˵�������¸ı��ļ���С��Ŀǰֻ��Ҫ��󣩡�һ�����ڴ��ļ��󣬽���Ԥ�����ļ��� �ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id����Ҫ���Ĵ�С���ļ����
 *   expect_filesize�� ϣ�����ĵ����ļ���С
 *   cur_filesize�� ʵ�ʸ��ĺ���ļ���С��ע�⣺�����ô�С�ɹ���һ��Ҫ��ȷ���ô˲�����ֵ!��
 *
 *  ��ţ�2 (ET_FS_IDX_CLOSE)  ����˵����typedef int32 (*et_fs_close)(u32 file_id);
 *   ˵�����ر��ļ����ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id����Ҫ�رյ��ļ����
 *
 *  ��ţ�3 (ET_FS_IDX_READ)  ����˵����typedef int32 (*et_fs_read)(u32 file_id, char *buffer, int32 size, u32 *readsize);
 *   ˵������ȡ��ǰ�ļ�ָ���ļ����ݡ��ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id�� ��Ҫ��ȡ���ļ����
 *   buffer��  ��Ŷ�ȡ���ݵ�bufferָ��
 *   size��    ��Ҫ��ȡ�����ݴ�С�������߿��Ա�֤���ᳬ��buffer�Ĵ�С��
 *   readsize��ʵ�ʶ�ȡ���ļ���С��ע�⣺�ļ���ȡ�ɹ���һ��Ҫ��ȷ���ô˲�����ֵ!��
 *
 *  ��ţ�4 (ET_FS_IDX_WRITE)  ����˵����typedef int32 (*et_fs_write)(u32 file_id, char *buffer, int32 size, u32 *writesize);
 *   ˵�����ӵ�ǰ�ļ�ָ�봦д�����ݡ��ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id��  ��Ҫд����ļ����
 *   buffer��   ���д�����ݵ�bufferָ��
 *   size��     ��Ҫд������ݴ�С�������߿��Ա�֤���ᳬ��buffer�Ĵ�С��
 *   writesize��ʵ��д����ļ���С��ע�⣺�ļ�д��ɹ���һ��Ҫ��ȷ���ô˲�����ֵ!��
 *
 *  ��ţ�5 (ET_FS_IDX_PREAD)  ����˵����typedef int32 (*et_fs_pread)(u32 file_id, char *buffer, int32 size, uint64 filepos, u32 *readsize);
 *   ˵������ȡָ��ƫ�ƴ����ļ����ݡ��ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id�� ��Ҫ��ȡ���ļ����
 *   buffer��  ��Ŷ�ȡ���ݵ�bufferָ��
 *   size��    ��Ҫ��ȡ�����ݴ�С�������߿��Ա�֤���ᳬ��buffer�Ĵ�С��
 *   filepos�� ��Ҫ��ȡ���ļ�ƫ��
 *   readsize��ʵ�ʶ�ȡ���ļ���С��ע�⣺�ļ���ȡ�ɹ���һ��Ҫ��ȷ���ô˲�����ֵ!��
 *
 *  ��ţ�6 (ET_FS_IDX_PWRITE)  ����˵����typedef int32 (*et_fs_pwrite)(u32 file_id, char *buffer, int32 size, uint64 filepos, u32 *writesize);
 *   ˵������ָ��ƫ�ƴ�д�����ݡ��ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id��  ��Ҫд����ļ����
 *   buffer��   ���д�����ݵ�bufferָ��
 *   size��     ��Ҫд������ݴ�С�������߿��Ա�֤���ᳬ��buffer�Ĵ�С��
 *   filepos��  ��Ҫ��ȡ���ļ�ƫ��
 *   writesize��ʵ��д����ļ���С��ע�⣺�ļ�д��ɹ���һ��Ҫ��ȷ���ô˲�����ֵ!��
 *
 *  ��ţ�7 (ET_FS_IDX_FILEPOS)  ����˵����typedef int32 (*et_fs_filepos)(u32 file_id, uint64 *filepos);
 *   ˵������õ�ǰ�ļ�ָ��λ�á��ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id�� �ļ����
 *   filepos�� ���ļ�ͷ��ʼ������ļ�ƫ��
 *
 *  ��ţ�8 (ET_FS_IDX_SETFILEPOS)  ����˵����typedef int32 (*et_fs_setfilepos)(u32 file_id, uint64 filepos);
 *   ˵�������õ�ǰ�ļ�ָ��λ�á��ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id�� �ļ����
 *   filepos�� ���ļ�ͷ��ʼ������ļ�ƫ��
 *
 *  ��ţ�9 (ET_FS_IDX_FILESIZE)  ����˵����typedef int32 (*et_fs_filesize)(u32 file_id, uint64 *filesize);
 *   ˵������õ�ǰ�ļ���С���ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   file_id�� �ļ����
 *   filepos�� ��ǰ�ļ���С
 *
 *  ��ţ�10 (ET_FS_IDX_FREE_DISK)  ����˵����typedef int32 (*et_fs_get_free_disk)(const char *path, u32 *free_size);
 *   ˵�������path·�����ڴ��̵�ʣ��ռ䣬һ�������Ƿ���Դ����ļ����ж����ݡ��ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   path��     ��Ҫ��ȡʣ����̿ռ�����ϵ�����·��
 *   free_size��ָ��·�����ڴ��̵ĵ�ǰʣ����̿ռ䣨ע�⣺�˲���ֵ��λ�� KB(1024 bytes) !��
 *
 *  ��ţ�11 (ET_SOCKET_IDX_SET_SOCKOPT)  ����˵����typedef _int32 (*et_socket_set_sockopt)(u32 socket, int32 socket_type); 
 *   ˵��������socket����ز�����Ŀǰֻ֧��Э���PF_INET���ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   socket��     ��Ҫ���õ�socket���
 *   socket_type����socket�����ͣ�Ŀǰ��Ч��ֵ��2����SOCK_STREAM  SOCK_DGRAM����2�����ȡֵ�����ڵ�OSһ�¡�
 *
 *  ��ţ�12 (ET_MEM_IDX_GET_MEM)  ����˵����typedef int32 (*et_mem_get_mem)(u32 memsize, void **mem);
 *   ˵�����Ӳ���ϵͳ����̶���С�������ڴ�顣�ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   memsize��     ��Ҫ������ڴ��С
 *   mem�� �ɹ�����֮���ڴ���׵�ַ����*mem�з��ء�
 *
 *  ��ţ�13 (ET_MEM_IDX_FREE_MEM)  ����˵����typedef int32 (*et_mem_free_mem)(void* mem, u32 memsize);
 *   ˵�����ͷ�ָ���ڴ�������ϵͳ���ɹ�����0�����򷵻ش�����
 *   ����˵����
 *   mem��     ��Ҫ�ͷŵ��ڴ���׵�ַ
 *   memsize����Ҫ�ͷŵ��ڴ��Ĵ�С
 *
 *  ��ţ�14 (ET_ZLIB_UNCOMPRESS)  ����˵����typedef _int32 (*et_zlib_uncompress)( unsigned char *p_out_buffer, int *p_out_len, const unsigned char *p_in_buffer, int in_len );
*   ˵����ָ��zlib��Ľ�ѹ����������,����kad��������Դ���Ľ�ѹ,���emule��Դ����
*   ����˵����
*   p_out_buffer����ѹ�����ݻ�����
*   p_out_len��   ��ѹ�����ݳ���
*   p_in_buffer�� ����ѹ���ݻ�����
*   in_len��      ����ѹ���ݳ���
*/
ETDLL_API int32 et_set_customed_interface(int32 fun_idx, void *fun_ptr);



ETDLL_API int32 et_set_customed_interface_mem(int32 fun_idx, void *fun_ptr);

#ifdef _CONNECT_DETAIL
/* Ѹ�׹�˾�ڲ�������  */

/*
  * ��ȡ�ϴ�pipe����Ϣ 
  * ����ֵ: 0    �ɹ�
                        4112  ��Ч������p_upload_pipe_info_array ����Ϊ��
  */
ETDLL_API int32 et_get_upload_pipe_info(ET_PEER_PIPE_INFO_ARRAY * p_upload_pipe_info_array);

#endif /*  _CONNECT_DETAIL  */


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/*
 * ����Ϊһ����򵥵�demoʾ�������ิ�ӵĲ�������ο�demo.c�ļ�
 */
/////////////////////////////////////////////////////////////////
//#include <stdio.h>
//#include <unistd.h>
//#include <string.h> 
//
//#include "embed_thunder.h"
//
//    
///*  This is the call back function of license report result
//	Please make sure keep it in this type:
//	typedef int32 ( *ET_NOTIFY_LICENSE_RESULT)(u32 result, u32 expire_time);
//*/
//int notify_license_result(unsigned int  result, unsigned int  expire_time)
//{
//	/* Add your code here ! */
//	
//	printf("\n******************* notify_license_result ******************\n");
//	printf("result=%u,expire_time=%u",result,expire_time);
//	printf("\n*************** End of notify_license_result ****************\n\n");
//
//	return 0;
//}
// 
///* Main of the demo */
//int main()
//{
//	ET_TASK info;
//	int ret_val = 0;
//	unsigned int task_id = 0;
//	char * url = "http://down.sandai.net/Thunder5.8.6.600.exe";
//
//	/* Initiate the Embed Thunder download library without proxy */
//	 ret_val = et_init( NULL );
//        if(ret_val != 0)
//       {
//              printf(" init error, ret = %d \n", ret_val);
//		goto ErrHandle;
//       }
//
//	/* Set license to  Embed Thunder download library */
//	ret_val=et_set_license("08083000021b29b27e57604f68bece019489747910", strlen("08083000021b29b27e57604f68bece019489747910"));
//	if(ret_val!=0)		
//       {
//           printf(" set_license error, ret = %d \n", ret_val);
//   		goto ErrHandle2;
//       }
//
//	/* Set license callback function to  Embed Thunder download library */
//	ret_val=et_set_license_callback( notify_license_result);
//	if(ret_val!=0)		
//       {
//           printf(" set_license_callback error, ret = %d \n", ret_val);
//   		goto ErrHandle2;
//       }
//	
//	/* Create task */
//       ret_val = et_create_new_task_by_url(url, strlen(url),			 /* url */
//       								NULL, 0,						 /* ref_url */
//       								NULL, 0,						 /* description */
//       								"./", strlen("./"), 			 /* file path */
//       								"Thunder5.8.6.600.exe", strlen("Thunder5.8.6.600.exe"),    /* user file name */
//       								&task_id);
//       if(ret_val != 0)
//	{
//		printf(" create_new_task  error, ret = %d \n",  ret_val);
//		goto ErrHandle3;  
//	}
//	   
//	/* Start task */
//       ret_val = et_start_task(task_id);
//       if(ret_val != 0)
//       {
//           printf(" start_task %u, error, ret = %d \n", task_id, ret_val);
//           goto ErrHandle4;    
//       }
//
//	/* Get the task information */
//	while(TRUE)
//	{
//   		memset(&info,0,sizeof(ET_TASK));
//     	       ret_val = et_get_task_info( task_id, &info);
//		if(ret_val != 0)
//		{
//		    printf("\n get_task_info %u, error, ret = %d \n", task_id, ret_val);
//		    goto ErrHandle4;    
//		}
//		else
//		{
//	        	printf("task id: %u, task_status=%d, task_speed=%7u (%7u,%7u),task_progress=%3u,pipes=(%3u,%3u,%3u,%3u), filesize=%llu\r", 
//	               	task_id,info._task_status,info._speed,info._server_speed, info._peer_speed, info._progress, info._dowing_server_pipe_num, 
//	               	info._connecting_server_pipe_num, info._dowing_peer_pipe_num, info._connecting_peer_pipe_num, info._file_size);
//	        	fflush(stdout);
//		}
//
//		/* Check if the task has finished */
//              if(info._task_status==ET_TASK_SUCCESS ||info._task_status ==ET_TASK_FAILED)
//              {
//                  if((ret_val == 0)&&(info._task_status ==ET_TASK_SUCCESS ))
//                  {
//                      printf("\ntask id:%u, Down load task success!\n", task_id);
//                  }
//                  else 
//                  if((ret_val == 0)&&(info._task_status ==ET_TASK_FAILED))
//                  {
//                      printf("\ntask_id:%u, Down load task failed! \n", task_id);
//                  }
//                      
//      		    /* Stop the task */
//                  et_stop_task( task_id);
//                          
//       	    /* Delete the task */
//                  et_delete_task( task_id);
//      		
//      		    break;
//              }
//					 
//		usleep(2000*1000);
//	}
//
//    /* Uninitiate the Embed Thunder download library */
//    et_uninit();
//
//    return 0;
//
///* Error handler */
//
//ErrHandle4:
//
//    et_stop_task( task_id);
//
//ErrHandle3:
//
//    et_delete_task(task_id);
//
//ErrHandle2:
//	
//    et_uninit();
//
//ErrHandle:
//
//    return 1;
//}

#ifdef __cplusplus
}
#endif
#endif
