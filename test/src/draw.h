/************************************************************************
* Name : draw.h
* Copyright : Hisoft
* Autor : ruanqingyong
* Date : 2012.01.04
* Description : 
************************************************************************/

/*
 * draw the view based on difference view id.
 */
#ifndef __DRAW_H__
#define __DRAW_H__


#include "globals.h"
void draw_init_head(int i_page_type);
void draw(int i_page_type);
void draw_init_tail(int i_page_type);
void draw_manual_clean(int i_page_type);

HContainer *draw_set_list_member(ActionPerformed p_action, char *p_str, int i_bgcolor, int i_h_color);
void draw_set_def_focus(HContainer *c);
HButton *draw_show_calendar(char *p_date, short s_width, short s_height, int i_color);
HButton *draw_show_viewmore(char *p_str, short s_width, int i_bgcolor, int i_h_color);
void draw_limit_length(char *p_str, int i_len);

#endif
/******************************* EOF ***********************************/

