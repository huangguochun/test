/*****************************************************************
* File Name: draw_frame.h
*
* Description: draw every page's frame
*
* COPYRIGHT:
*
* Create on: 2011-12-28 Author: Liu,Heng
*
*Modified by name on $(Date)
******************************************************************/

#ifndef __DRAW_FRAME_H__
#define __DRAW_FRAME_H__

/**********************INCLUDE FILES******************************/
#include "globals.h"
#include "pos.h"

/*****************************************************************
 * Function Name: draw_frame
 *
 * Description: draw every page's frame
 *
 * Parameters:
 * view: pointer of cricket_view_t instance
 *
 * Return:
 *****************************************************************/
void draw_frame(cricket_view_t *view);

/*****************************************************************
* Function Name: repaint_auto_refview
*
* Description: repaint auto refresh view page
*
* Parameters:
*
* Return:
*****************************************************************/
void repaint_auto_refview(int i_ref_time);

/*****************************************************************
* Function Name: clean_auto_ref_data
*
* Description: clean auto refresh page data
*
* Parameters:
*
* Return:
*****************************************************************/
void clean_auto_ref_data(void);

/*****************************************************************
* Function Name: record_focus_widget
*
* Description: record focus widget
* Parameters:
*
* Return:
*****************************************************************/
void record_focus_widget(HWidget *p_widget, HFocusEvent *p_evt);

/*****************************************************************
* Function Name: key_filter
*
* Description: key filter for RNK and LNK
* Parameters:
*
* Return:
*****************************************************************/
int key_filter(int i_evt, int key_code);

/*****************************************************************
* Function Name: set_prompt
*
* Description: set prompt
* Parameters:
*
* Return:
*****************************************************************/
void set_prompt(char * pc_str, char *pc_mb_left, char *pc_mb_right, ActionPerformed action_menu_bar, int i_img);

/* set prompt font size */
void set_prompt_font_size(int i_font_size);

/*****************************************************************
* Function Name: get_album_id, get_album_num, get_album_pos, next_pht, pre_pht, set_photo_detail_cnt
*
* Description: get album id, get album number, get album's photo position, go to next photo, go to prev photo, set photo detail content
* Parameters:
*
* Return:
*****************************************************************/
extern char gsac_pht_list_title[][PHT_TM_LENGHT];
void init_pht_detail_title(int pos, char *pc_title);
void init_pht_detail(char *pc_str);
char* get_album_id(void);
int get_album_num(void);
int get_album_pos(void);
void next_pht(void);
void pre_pht(void);
void set_photo_detail_cnt(char *pc_txt, char *pc_url);

/*****************************************************************
* Function Name: init_cmtary_data
*
* Description: init commentary data
* Parameters:
*
* Return:
*****************************************************************/
void init_cmtary_data(void);

/* init page style data */
void init_page_stytle_data(void);

/* head to head data */
int get_team_fid(void);
int get_team_sid(void);
char* get_match_type(void);
void init_h2h_data(int tid_f, int tid_s, char *mtype);

/* init menubar data */
void init_menubar(void);

#endif