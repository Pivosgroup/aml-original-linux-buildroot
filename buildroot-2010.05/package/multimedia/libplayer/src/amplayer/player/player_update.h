#ifndef _PLAYER_UPDATE_H_
#define _PLAYER_UPDATE_H_

#include <player_type.h>
#include "player_priv.h"

unsigned int get_pts_pcrscr(play_para_t *p_para);
unsigned int get_pts_video(play_para_t *p_para);
int     update_playing_info(play_para_t *p_para);
int     set_media_info(play_para_t *p_para);
int     check_time_interrupt(long *old_msecond, int interval_ms);

#endif

