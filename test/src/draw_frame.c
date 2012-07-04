/*****************************************************************
 * File Name: draw_frame.c
 *
 * Description: draw every page's frame
 *
 * COPYRIGHT:
 *
 * Create on: 2011-12-28 Author: Liu,Heng
 *
 *Modified by name on $(Date)
 *****************************************************************/
#define _CRT_SECURE_NO_WARNINGS
/**********************INCLUDE FILES******************************/
#include "vmtimer.h"
#include "string.h"
#include "vmchset.h"
#include "stdlib.h"

#include "hplane.h"
#include "hlayout.h"
#include "hlabel.h"
#include "hwindow.h"
#include "ui.h"
#include "hmenubar.h"
#include "htextinput.h"

#include "pos.h"
#include "draw_frame.h"
#include "switch_helper.h"
#include "action_cricket.h"
#include "resources.h"
#include "framework_wrapper.h"
#include "draw.h"
#include "draw_macros.h"
#include "http_wrapper.h"
#include "draw.h"

/* match bar text, match bar page type */
static char str_match_bar[][10] = {TXT_MATCHES, TXT_NEWS, TXT_PHOTOS, TXT_TEAMS};
static int ptype_match_bar[] = {live_matches_view, news_view, photos_view, teams_intl_view};
static int match_bar_num = 4;
static char str_pstatistics[][10] = {TXT_BATTING, TXT_BOWLING};
static int ptype_pstatistics[] = {player_batting_view, player_bowling_view};
static int statistics_bar_num = 2;

/* static data for auto refresh page */
static HButton *p_ref_opt[6];
static HImage *p_check_img;
static int sgi_ref_timer = -1;

/* static data for check update */
static HContainer *p_cnt_prompt;
static HLabel *p_lab_prompt;
static HButton *p_btn_prompt;

/* init page style data */
static void init_page_data(void);

/* draw the top of view */
static void draw_view_top(HLayout *p_layout, char *pc_viewname);

/* draw the title bar of view */
static void draw_view_titlebar(HLayout *p_layout, char bar_array[][10], int ptype_arr[], const int i_size, const int bar_pos);

/* draw search frame */
static void draw_search_frame(HLayout *p_layout);

/* draw team type */
static void draw_team_type(HLayout *p_layout, int i_page_type);

/* draw team type */
static void draw_cmtary_type(HLayout *p_layout, int i_page_type);

/* draw menu bar */
static void draw_menubar(char *lstr, char *rstr, ActionPerformed act_func);

/* add option item */
static void add_option_item(HButton *p_btn, char *pc_opt, int i_ptype, ActionPerformed act_func);

/* draw setting option */
static void draw_setting(void);

/* draw help */
static void draw_help(void);

/* draw about */
static void draw_about(void);

/* draw auto refresh */
static void draw_auto_refresh(void);

/* draw prompt */
static void draw_prompt(void);

/* draw home page list */
static void draw_homepage_list(void);

static void draw_photo_detail_frame(void);

static void auto_timer(int i_tid);

static void load_default_img(char *pc_imag_f, char *pc_img_s);

/* commentary data  */
static char gac_cmtary_fi[32];
static char gac_cmtary_si[32];

void init_cmtary_data()
{
	if(recnt_match_detail_view == g_current_view)
	{
		sprintf(gac_cmtary_fi, "1st Innings\n%s: %s/%s(%s)", whether_null(g_parse_pool.recent_1st_innings_team), whether_null(g_parse_pool.recent_1st_innings_runs), \
			whether_null(g_parse_pool.recent_1st_innings_wickets), whether_null(g_parse_pool.recent_1st_innings_overs));
		sprintf(gac_cmtary_si, "2nd Innings\n%s: %s/%s(%s)", whether_null(g_parse_pool.recent_2nd_innings_team), whether_null(g_parse_pool.recent_2nd_innings_runs), \
			whether_null(g_parse_pool.recent_2nd_innings_wickets), whether_null(g_parse_pool.recent_2nd_innings_overs));
	}
	else
	{
		if(NULL != g_parse_pool.ongoing_match_runs)
			sprintf(gac_cmtary_si, "2nd Innings\n%s: %s/%s(%s)", whether_null(g_parse_pool.ongoing_match_sn_team), whether_null(g_parse_pool.ongoing_match_runs), \
				whether_null(g_parse_pool.ongoing_match_wickets), whether_null(g_parse_pool.ongoing_match_overs));
		else
			sprintf(gac_cmtary_si, "2nd Innings\n : %d/%d(%d)", 0, 0, 0);
		sprintf(gac_cmtary_fi, "1st Innings\n%s: %s/%s(%s)", whether_null(g_parse_pool.ongoing_match_1st_sn_team), whether_null(g_parse_pool.ongoing_match_1st_runs), \
			whether_null(g_parse_pool.ongoing_match_1st_wickets), whether_null(g_parse_pool.ongoing_match_1st_overs));
	}

	draw_limit_length(gac_cmtary_fi, CMTARY_TITLE_TEXT_LENGTH);
	draw_limit_length(gac_cmtary_si, CMTARY_TITLE_TEXT_LENGTH);
}

/* head to head data */
static int gsi_team_fid = 0;
static int gsi_team_sid = 0;
static char gac_match_type[10];

int get_team_fid()
{
	return gsi_team_fid;
}

int get_team_sid()
{
	return gsi_team_sid;
}

char* get_match_type()
{
	return gac_match_type;
}

/* init head to head data */
void init_h2h_data(int tid_f, int tid_s, char *mtype)
{
	gsi_team_fid = tid_f;
	gsi_team_sid = tid_s;
	if (strcmp(mtype, "odi") == 0){
		sprintf(gac_match_type, "%s", "ODI");
	}
	if (strcmp(mtype, "t20") == 0){
		sprintf(gac_match_type, "%s", "T20");
	}
	if (strcmp(mtype, "test") == 0){
		sprintf(gac_match_type, "%s", "Test");
	}
}


/* data for photo detail */
static int gsi_pht_num = 0;
static int gsi_pht_pos = 0;
static char gsac_pht_id[21];
static char gsac_pht_title[512];
static HContainer *gsp_cnt_pic = NULL;
static HButton *gsp_btn_pic = NULL;
static HLabel *gsp_lab_pic = NULL;

char gsac_pht_list_title[5][PHT_TM_LENGHT];

/* save photo title */
void init_pht_detail_title(int pos, char *pc_title)
{
	if(NULL == pc_title)
		sprintf(gsac_pht_list_title[pos], " ");
	else
	{
		draw_limit_length(pc_title, PHT_TM_LENGHT);
		sprintf(gsac_pht_list_title[pos], "%s", whether_null(pc_title));
	}
}

void init_pht_detail(char *pc_str)
{
	if(NULL == pc_str || 512 < strlen(pc_str))
		sprintf(gsac_pht_title, " ");
	else
		sprintf(gsac_pht_title, "%s", whether_null(pc_str));
}

void init_pht_detail_data(int i_pht_num, char *pc_pht_id, int i_pos)
{
	gsi_pht_num = i_pht_num;
	gsi_pht_pos = i_pos;

	if(NULL == pc_pht_id)
		return ;
	sprintf(gsac_pht_id, "%s", whether_null(pc_pht_id));
}

char* get_album_id()
{
	return gsac_pht_id;
}

int get_album_num()
{
	return gsi_pht_num;
}

int get_album_pos()
{
	return gsi_pht_pos;
}

void next_pht()
{
	(gsi_pht_pos < gsi_pht_num)?gsi_pht_pos ++:(gsi_pht_pos = 1);
}

void pre_pht()
{
	(gsi_pht_pos > 1)?gsi_pht_pos --:(gsi_pht_pos = gsi_pht_num);
}

/* draw page frame */
void draw_frame(cricket_view_t *view)
{
	HPlane *p_plane = window->get_default_plane();

	HLayout *p_top_layout = ui_next_ver_layout();
	gp_cnt_content = NEXT_CNT;

	gp_focus_widget = NULL;
	init_page_stytle_data();

	/* add top layout */
	hcontainer_set_layout(NEXT_CNT, p_top_layout);
	ui_set_bgcolor((HWidget *)CUR_BTN, COLOR_MAIN_HUE);
	hplane_set_top_widget(p_plane, (HWidget *)CUR_CNT);

	/* add content layout */
	gp_verlayout = ui_next_ver_layout();
	gp_verlayout->s_gap_x = 2;
	gp_verlayout->s_gap_y = 0;
	hcontainer_set_layout(gp_cnt_content, gp_verlayout);
	ui_set_opaque((HWidget *)gp_cnt_content, 0);
	hplane_add_widget(p_plane, (HWidget *)gp_cnt_content);

	switch(view->base.i_page_type)
	{
	case live_matches_view:
		gp_img_cricket_home_bg->s_y = 0;
		hcontainer_set_bgimg(p_plane->p_content, gp_img_cricket_home_bg);
		break;

	case team_details_view:
#ifdef __LQVGA_H__
		gp_img_cricket_home_bg->s_y = 0;
#else
		gp_img_cricket_home_bg->s_y = -VIEW_TOP_HEIGHT/2;
#endif
		hcontainer_set_bgimg(p_plane->p_content, gp_img_cricket_home_bg);
		break;

	default:
		hcontainer_set_bgimg(p_plane->p_content, gp_img_cricket_bg);
		break;
	}

	if(sgi_ref_timer > 0)
	{
		vm_delete_timer_ex(sgi_ref_timer);
		sgi_ref_timer = -1;
	}

	/* draw frame */
	switch(view->base.i_page_type)
	{
	case live_matches_view:
		init_page_data();
		load_default_img(TEAM_FLAG_DIMG_48, NULL);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_LIST_MEMBER_CNT_X_GAP, 0, 0, 0);
		draw_view_top(p_top_layout, TXT_CRICKET);
		draw_view_titlebar(p_top_layout, str_match_bar, ptype_match_bar, match_bar_num, 0);
		draw_homepage_list();
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menu_bar);
		if(g_auto_refresh_time > 0)
			sgi_ref_timer = vm_create_timer_ex(g_auto_refresh_time*1000, auto_timer);
		break;

	case news_view:
		init_page_data();
		gp_msg_img = NEXT_IMG;
		himage_set_support_png(gp_msg_img, 1);
		himage_load_frome_resource(gp_msg_img, PHOTO_IMG);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 0, 0);
		draw_view_top(p_top_layout, TXT_LATEST_NEWS);
		draw_view_titlebar(p_top_layout, str_match_bar, ptype_match_bar, match_bar_num, 1);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menu_bar);
		if(g_auto_refresh_time > 0)
			sgi_ref_timer = vm_create_timer_ex(g_auto_refresh_time*1000, auto_timer);
		break;

	case photos_view:
		init_page_data();
		load_default_img(PHOTO_COVER_DIMG, NULL);
		gp_msg_img = NEXT_IMG;
		himage_set_support_png(gp_msg_img, 1);
		himage_load_frome_resource(gp_msg_img, PHOTO_IMG);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 0, 0);
		draw_view_top(p_top_layout, TXT_LATEST_PHOTOS);
		draw_view_titlebar(p_top_layout, str_match_bar, ptype_match_bar, match_bar_num, 2);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menu_bar);
		if(g_auto_refresh_time > 0)
			sgi_ref_timer = vm_create_timer_ex(g_auto_refresh_time*1000, auto_timer);
		break;

	case teams_intl_view:
	case teams_ipl_view:
		init_page_data();
		load_default_img(TEAM_FLAG_DIMG_32, NULL);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 0, 0);
		draw_view_top(p_top_layout, TXT_TEAMS);
		draw_view_titlebar(p_top_layout, str_match_bar, ptype_match_bar, match_bar_num, 3);
		draw_team_type(p_top_layout, view->base.i_page_type);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_search);
		if(g_auto_refresh_time > 0)
			sgi_ref_timer = vm_create_timer_ex(g_auto_refresh_time*1000, auto_timer);
		break;

	case recent_matches_view:
		gp_verlayout->s_gap_y = 3;
		init_page_data();
		load_default_img(TEAM_FLAG_DIMG_32, NULL);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 0, 0);
		draw_view_top(p_top_layout, TXT_RECENT_MATCHES);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case recnt_match_detail_view:
		gi_img_data_cur = -1;
		gi_img_data_num = 0;
		load_default_img(TEAM_FLAG_DIMG_48, NULL);
		draw_view_top(p_top_layout, TXT_RECENT_MATCHES);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case match_score_view:
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, 0, 0, 0);
		init_page_data();
		draw_view_top(p_top_layout, TXT_SCORE);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case match_score_detail_view:
		draw_view_top(p_top_layout, TXT_SCORE);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_refresh);
		break;

	case match_cmtary_first_view:
	case match_cmtary_second_view:
		init_page_data();
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, 0, 0, 0);
		draw_view_top(p_top_layout, TXT_COMMENTARY);
		draw_cmtary_type(p_top_layout, view->base.i_page_type);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_refresh);
		break;

	case upcoming_matches_view:
		gp_verlayout->s_gap_y = 3;
		init_page_data();
		load_default_img(TEAM_FLAG_DIMG_32, NULL);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 0, 0);
		draw_view_top(p_top_layout, TXT_UPCOMING_MATCHES);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case upcom_match_detail_view:
		gi_img_data_cur = -1;
		gi_img_data_num = 0;
		load_default_img(TEAM_FLAG_DIMG_48, NULL);
		draw_view_top(p_top_layout, TXT_UPCOMING_MATCHES);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case match_team_player_view:
	case team_player_view:
		init_page_data();
		load_default_img(PLAYER_PHT_DIMG_64, NULL);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, 0, 0, 0);
		sprintf(gac_text_buffer, "%s players", whether_null(get_team_abbre(view->i_msg_id)));
		draw_view_top(p_top_layout, gac_text_buffer);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case match_hth_view:
		init_page_data();
		draw_view_top(p_top_layout, TXT_HEAD2HEAD);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case ongoing_matches_view:
		gp_verlayout->s_gap_y = 3;
		init_page_data();
		load_default_img(TEAM_FLAG_DIMG_32, NULL);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 0, 0);
		draw_view_top(p_top_layout, TXT_ONGOING_SERIES);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case ongoing_match_details_view:
		gi_img_data_cur = -1;
		gi_img_data_num = 0;
		load_default_img(TEAM_FLAG_DIMG_48, PLAYER_PHT_DIMG_40);
		draw_view_top(p_top_layout, TXT_ONGOING_SERIES);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case news_detail_view:
		if(-1 != gi_msg_data_cur)
			init_pht_detail_data(g_msg_data[gi_msg_data_cur].i_msg, NULL, g_msg_data[gi_msg_data_cur].i_id);
		init_page_data();
		draw_view_top(p_top_layout, TXT_LATEST_NEWS);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_nxtref);
		break;

	case photos_detail_view:
		if(-1 != gi_msg_data_cur)
			init_pht_detail_data(g_msg_data[gi_msg_data_cur].i_msg, g_msg_data[gi_msg_data_cur].pc_id, 1);
		init_page_data();
		load_default_img(PHOTO_DETAIL_DIMG, NULL);
		gp_default_img->s_x = (PHT_DETAIL_WIDTH - gp_default_img->s_width)/2;
		gp_default_img->s_y = (window->s_screen_height - TITLE_BAR_HEIGHT - MENU_BAR_HEIGHT-10 - gp_default_img->s_height)/2;
		gp_temp_img_two = NEXT_IMG;
		himage_set_support_png(gp_temp_img_two, 1);
		himage_load_frome_resource(gp_temp_img_two, PHOTO_IMG_TM);
		sprintf(gac_text_buffer, "%d/%d", gsi_pht_pos, gsi_pht_num);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, 0, 0, 0);
		draw_view_top(p_top_layout, gac_text_buffer);
		draw_photo_detail_frame();
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case teams_search_view:
		init_page_data();
		load_default_img(TEAM_FLAG_DIMG_32, NULL);
		draw_view_top(p_top_layout, TXT_SEARCH);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 2, 0);
		draw_search_frame(p_top_layout);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case team_details_view:
		init_page_data();
		load_default_img(TEAM_FLAG_DIMG_48, PLAYER_PHT_DIMG_40);
		draw_view_top(p_top_layout, TXT_TEAMS);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case team_fixtures_view:
		gp_verlayout->s_gap_y = 3;
		init_page_data();
		load_default_img(TEAM_FLAG_DIMG_32, NULL);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 0, 0);
		draw_view_top(p_top_layout, TXT_END_FIXTURES);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;
	case player_details_view:
		init_page_data();
		gp_verlayout->s_gap_y = 2;
		load_default_img(PLAYER_PHT_DIMG_64/*PLAYER_PHT_DIMG_40*/, TEAM_FLAG_DIMG_32);
		ui_set_pad((HWidget *)gp_cnt_content, DRAW_LIST_MEMBER_CNT_X_GAP, DRAW_LIST_MEMBER_CNT_X_GAP, 0, 0);
		draw_view_top(p_top_layout, TXT_PLAYERS);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_okrefresh);
		break;

	case player_profile_view:
		init_page_data();
		load_default_img(PLAYER_PHT_DIMG_40, NULL);
		draw_view_top(p_top_layout, TXT_PROFILE);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_refresh);
		break;

	case player_batting_view:
		init_page_data();
		draw_view_top(p_top_layout, TXT_STATISTICS);
		draw_view_titlebar(p_top_layout, str_pstatistics, ptype_pstatistics, statistics_bar_num, 0);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_refresh);
		break;

	case player_bowling_view:
		init_page_data();
		draw_view_top(p_top_layout, TXT_STATISTICS);
		draw_view_titlebar(p_top_layout, str_pstatistics, ptype_pstatistics, statistics_bar_num, 1);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_refresh);
		break;

	case player_career_view:
		init_page_data();
		draw_view_top(p_top_layout, TXT_CAREER);
		draw_menubar(TXT_OPTIONS, TXT_BACK, action_menubar_refresh);
		break;
 
	case setting_view:
		init_page_data();
		draw_view_top(p_top_layout, TXT_SETTING);
		draw_setting();
		draw_menubar(TXT_OK, TXT_BACK, action_menubar_ok);
		break;

	case auto_refresh_setting_view:
		g_pre_page_type = auto_refresh_setting_view;
		init_page_data();
		draw_view_top(p_top_layout, TXT_AUTO_REFRESH_SET);
		draw_auto_refresh();
		draw_menubar(TXT_OK, TXT_BACK, action_menubar_autorefresh);
		break;

	case check_for_update_view:
		g_pre_page_type = check_for_update_view;
		init_page_data();
		ui_set_pad((HWidget *)gp_cnt_content, PROMPT_LAYOUT_LR_PD, PROMPT_LAYOUT_LR_PD, PROMPT_CNT_TOP_PAD, 0);
		draw_view_top(p_top_layout, TXT_CHECK_FOR_UPDATE);
		draw_prompt();
		draw_menubar(NULL, TXT_CANCEL, action_menubar_back);
		break;

	case about_view:
		g_pre_page_type = about_view;
		init_page_data();
		draw_view_top(p_top_layout, TXT_ABOUT);
		draw_about();
		draw_menubar(NULL, TXT_BACK, action_menubar_back);
		break;

	case help_view:
		g_pre_page_type = help_view;
		init_page_data();
		draw_view_top(p_top_layout, TXT_HELP);
		draw_help();
		draw_menubar(NULL, TXT_BACK, action_menubar_back);
		break;
	}
}

/* init page style data */
void init_page_stytle_data()
{
	gp_bot_border = NEXT_BORDER;
	gp_popmenu_border = NEXT_BORDER;
	gp_bot_border->i_color = COLOR888_TO_COLOR565(COLOR_OPT_BORDER);
	gp_bot_border->i_hover_color = COLOR888_TO_COLOR565(COLOR_OPT_BORDER);
	gp_bot_border->c_style = BORDER_STYLE_BOTTOM_LINE;
	gp_temp_border = NEXT_BORDER;
	gp_loading_border = NEXT_BORDER;
}

/* init page style data */
static void init_page_data()
{
	gi_msg_data_cur = -1;
	gi_msg_data_num = 0;
	gi_img_data_cur = -1;
	gi_img_data_num = 0;
}

/* draw the top of view */
static void draw_view_top(HLayout *p_layout, char *pc_viewname)
{
	NEXT_BTN;
	hbutton_set_image(CUR_BTN, gp_top_img);
	ui_set_size((HWidget *)CUR_BTN, window->s_screen_width, VIEW_TOP_HEIGHT);
	ui_set_enable_focus((HWidget *)CUR_BTN, 0);
	ui_set_enable_hover((HWidget *)CUR_BTN, 0);
	hlayout_add_widget(p_layout, (HWidget *)CUR_BTN);
}

/* draw the title bar of view */
static void draw_view_titlebar(HLayout *p_layout, char bar_array[][10], int ptype_arr[], const int i_size, const int bar_pos)
{
	int i = 0;
	int x, y, width;
	int height = TITLE_BAR_HEIGHT;
	HImage *p_img = NEXT_IMG;
	HImage *p_img_n = NEXT_IMG;

	/* set bar container border */
	switch(g_current_view)
	{
	case live_matches_view:
		himage_load_frome_resource(p_img, TITLE_IMG);
		himage_load_frome_resource(p_img_n, TITLE_MATCH_P_IMG);
		break;

	case news_view:
		himage_load_frome_resource(p_img, TITLE_IMG);
		himage_load_frome_resource(p_img_n, TITLE_NEWS_P_IMG);
		break;

	case photos_view:
		himage_load_frome_resource(p_img, TITLE_IMG);
		himage_load_frome_resource(p_img_n, TITLE_PHOTO_P_IMG);
		break;

	case teams_intl_view:
	case teams_ipl_view:
		himage_load_frome_resource(p_img, TITLE_IMG);
		himage_load_frome_resource(p_img_n, TITLE_TEAM_P_IMG);
		break;

	case player_batting_view:
	case player_bowling_view:
		height = TITLE_BAR_HEIGHT_S;
		himage_load_frome_resource(p_img, STATICS_BG_IMG);
		himage_load_frome_resource(p_img_n, STATICS_BG_IMG_P);
		break;
	}

	ui_set_border((HWidget *)NEXT_CNT, gp_bot_border);
	ui_set_size((HWidget *)CUR_CNT, window->s_screen_width, height);
	hcontainer_set_bgimg(CUR_CNT, p_img);

	x = 0;
	y = 0;
	width = window->s_screen_width/i_size;

	for(i = 0; i < i_size; i ++)
	{
		NEXT_BTN;
		if(player_batting_view == g_current_view || player_bowling_view == g_current_view)
			hbutton_set_text(CUR_BTN, bar_array[i]);
		ui_set_position((HWidget *)CUR_BTN, x, y);
		x += width;
		ui_set_size((HWidget *)CUR_BTN, width, height);
		ui_set_opaque((HWidget *)CUR_BTN, 0);
		ui_set_font((HWidget *)CUR_BTN, FONT_SMALL);
		ui_set_color((HWidget *)CUR_BTN, COLOR_WHITE);
		ui_set_enable_focus((HWidget *)CUR_BTN, 0);

		if(bar_pos == i)
		{
			hbutton_set_image(CUR_BTN, p_img_n);
			(window->get_default_plane())->p_own_focus_widget = (HWidget *)CUR_BTN;
		}

		CUR_BTN->base.pv_user_data = (void *)ptype_arr[i];
		CUR_BTN->base.action_performed = switch_view;

		hcontainer_add_widget(CUR_CNT, (HWidget *)CUR_BTN);
	}

	hlayout_add_widget(p_layout, (HWidget *)CUR_CNT);
}

/* draw search frame */
static void draw_search_frame(HLayout *p_layout)
{
	gp_textinput = htextinput_new();
	htextinput_set_max_len(gp_textinput, SEARCH_TEXT_SIZE);
	ui_set_size((HWidget *)gp_textinput, SEARCH_WIDTH, SEARCH_HEIGHT);
	ui_set_position((HWidget *)gp_textinput, SEARCH_POSITION_X, SEARCH_POSITION_Y);
	NEXT_BORDER->s_corner_width = 2;
	ui_set_bgcolor((HWidget *)gp_textinput, COLOR_WHITE);
	ui_set_border((HWidget *)gp_textinput, CUR_BORDER);
	gp_textinput->base.action_performed = action_search_bar;

	ui_set_size((HWidget *)NEXT_CNT, window->s_screen_width, SEARCH_BAR_HEIGHT);
	ui_set_bgcolor((HWidget *)CUR_CNT, COLOR_MAIN_HUE);

	ui_set_enable((HWidget *)gp_textinput, 0);

	ui_set_bgcolor((HWidget *)CUR_CNT, COLOR_MSG_ORANGE);
//	hplane_set_own_focus_widget(window->get_default_plane(), (HWidget *)gp_textinput);
//	gp_focus_widget = (HWidget *)gp_textinput;

	hcontainer_add_widget(CUR_CNT,  (HWidget *)gp_textinput);
	hlayout_add_widget(p_layout, (HWidget *)CUR_CNT);
}

/* draw team type */
static void draw_team_type(HLayout *p_layout, int i_page_type)
{
	HButton *p_btn_intl = NEXT_BTN;
	HButton *p_btn_ipl = NEXT_BTN;
	HPlane *p_plane = window->get_default_plane();
	HImage *p_img_p = NEXT_IMG;
	HContainer *c = NULL;

	/* set bar container border */
	ui_set_size((HWidget *)NEXT_CNT, /*DRAW_TEAM_CON_WIDTH*/window->s_screen_width, TEAM_TYPE_HEIGHT/*TITLE_BAR_HEIGHT*/);
	c = CUR_CNT;
	ui_set_bgcolor((HWidget *)CUR_CNT, COLOR_MAIN_HUE);

	/* set background image */
	himage_set_support_png(NEXT_IMG, 1);
	himage_load_frome_resource(CUR_IMG, TEAM_TYPE_IMG_BG);
	CUR_IMG->s_x = DRAW_MATCH_LIST_CON_GAP;
	hcontainer_set_bgimg(CUR_CNT, CUR_IMG);

	/* enable focus */
	ui_set_enable_focus((HWidget *)p_btn_intl, 0);
	ui_set_enable_focus((HWidget *)p_btn_ipl, 0);

	/* set text */
	hbutton_set_text(p_btn_intl, TXT_MENS_INTL);
	hbutton_set_text(p_btn_ipl, TXT_SWITCH_TO_IPL);
	ui_set_size((HWidget *)p_btn_intl, TEAM_TYPE_WIDHT_INTL, TEAM_TYPE_HEIGHT_INTL);
	ui_set_size((HWidget *)p_btn_ipl, TEAM_TYPE_WIDHT_IPL, TEAM_TYPE_HEIGHT_IPL);
	ui_set_position((HWidget *)p_btn_intl, DRAW_MATCH_LIST_CON_GAP/*1*/, 0);
	ui_set_position((HWidget *)p_btn_ipl, DRAW_MATCH_LIST_CON_GAP + TEAM_TYPE_WIDHT_INTL/*TEAM_TYPE_WIDHT+1*/, 0);
	ui_set_color((HWidget *)p_btn_intl, COLOR_TOP_GRAY);
	ui_set_color((HWidget *)p_btn_ipl, COLOR_TOP_GRAY);
	ui_set_opaque((HWidget *)p_btn_intl, 0);
	ui_set_opaque((HWidget *)p_btn_ipl, 0);
	p_btn_intl->base.pv_user_data = (void *)teams_intl_view;
	p_btn_ipl->base.pv_user_data = (void *)teams_ipl_view;
	p_btn_intl->base.action_performed = switch_view;
	p_btn_ipl->base.action_performed = switch_view;

	himage_set_support_png(p_img_p, 1);
	(teams_intl_view == i_page_type)? \
		(himage_load_frome_resource(p_img_p, TEAM_TYPE_IMG_F), hbutton_set_image(p_btn_intl, p_img_p), ui_set_enable_hover((HWidget *)p_btn_intl, 0), ui_set_color((HWidget *)p_btn_intl, COLOR_WHITE), p_plane->p_own_focus_widget = (HWidget *)p_btn_intl):\
		(himage_load_frome_resource(p_img_p, TEAM_TYPE_IMG_S), hbutton_set_image(p_btn_ipl, p_img_p), ui_set_enable_hover((HWidget *)p_btn_ipl, 0), ui_set_color((HWidget *)p_btn_ipl, COLOR_WHITE), p_plane->p_own_focus_widget = (HWidget *)p_btn_ipl);

	hcontainer_add_widget(CUR_CNT, (HWidget *)p_btn_intl);
	hcontainer_add_widget(CUR_CNT, (HWidget *)p_btn_ipl);
	hlayout_add_widget(p_layout, (HWidget *)CUR_CNT);
}

/* draw team type */
static void draw_cmtary_type(HLayout *p_layout, int i_page_type)
{
	HLabel *p_lab_fi = NEXT_LAB;
	HLabel *p_lab_si = NEXT_LAB;
	HPlane *p_plane = window->get_default_plane();
	HContainer *c =NULL, *cc =NULL, *ccc = NULL;
	HImage *i =NULL;

	/* set bar container border */
	c = NEXT_CNT;
	ui_set_size((HWidget *)c, window->s_screen_width, CMTARY_TITLE_BAR_HEIGHT);
	ui_set_bgcolor((HWidget *)c, COLOR_MAIN_HUE);

	ui_set_enable((HWidget *)p_lab_fi, 1);
	ui_set_enable((HWidget *)p_lab_si, 1);
	ui_set_opaque((HWidget *)p_lab_fi, 0);
	ui_set_opaque((HWidget *)p_lab_si, 0);
	hlabel_set_line_space(p_lab_fi, CMTARY_TXT_SPACE);
	hlabel_set_line_space(p_lab_si, CMTARY_TXT_SPACE);
	ui_set_pad((HWidget *)p_lab_fi, CMTARY_TITLEBAR_LR_PAD, CMTARY_TITLEBAR_LR_PAD, 4, 4);
	ui_set_pad((HWidget *)p_lab_si, CMTARY_TITLEBAR_LR_PAD, CMTARY_TITLEBAR_LR_PAD, 4, 4);
	ui_set_enable_focus((HWidget *)p_lab_fi, 1);
	ui_set_enable_focus((HWidget *)p_lab_si, 1);
	hlabel_set_text(p_lab_fi, gac_cmtary_fi);
	hlabel_set_text(p_lab_si, gac_cmtary_si);
	ui_set_size((HWidget *)p_lab_fi, DRAW_MATCH_LIST_CON_WIDTH/*window->s_screen_width*//2, CMTARY_TITLE_BAR_HEIGHT-1);
	ui_set_size((HWidget *)p_lab_si, DRAW_MATCH_LIST_CON_WIDTH/*window->s_screen_width*//2, CMTARY_TITLE_BAR_HEIGHT-1);
	p_lab_fi->base.s_top_y = CMTARY_TXT_Y;
	p_lab_si->base.s_top_y = CMTARY_TXT_Y;
	ui_set_color((HWidget *)p_lab_fi, COLOR_TOP_GRAY);
	ui_set_color((HWidget *)p_lab_si, COLOR_TOP_GRAY);
	ui_set_hover_color((HWidget *)p_lab_fi, COLOR_TOP_GRAY);
	ui_set_hover_color((HWidget *)p_lab_si, COLOR_TOP_GRAY);
	p_lab_fi->base.pv_user_data = (void *)match_cmtary_first_view;
	p_lab_si->base.pv_user_data = (void *)match_cmtary_second_view;
	p_lab_fi->base.action_performed = switch_view;
	p_lab_si->base.action_performed = switch_view;

	cc = NEXT_CNT;
	ui_set_position((HWidget *)cc, DRAW_MATCH_LIST_CON_GAP, 0);
	hcontainer_add_widget(cc, (HWidget *)p_lab_fi);
	hcontainer_add_widget(c, (HWidget *)cc);
	ccc = NEXT_CNT;
	hcontainer_add_widget(ccc, (HWidget *)p_lab_si);
	ui_set_position((HWidget *)ccc, (DRAW_MATCH_LIST_CON_WIDTH >> 1) + DRAW_MATCH_LIST_CON_GAP, 0);
	hcontainer_add_widget(c, (HWidget *)ccc);
	i = NEXT_IMG;
	himage_set_support_png(i, 1);
	himage_load_frome_resource(i, DRAW_COM_CNT_IMG);
	hcontainer_set_bgimg(c, i);
	i->s_x = DRAW_MATCH_LIST_CON_GAP;
	hlayout_add_widget(p_layout, (HWidget *)c);

	i = NULL, i = NEXT_IMG;
	himage_set_support_png(i, 1);
	if (match_cmtary_first_view == i_page_type){
		ui_set_color((HWidget *)p_lab_fi, COLOR_WHITE);
		p_plane->p_own_focus_widget = (HWidget *)p_lab_fi;
		himage_load_frome_resource(i, DRAW_COM_LEFT_IMG);
		hcontainer_set_bgimg(cc, i);
	}else{
		ui_set_color((HWidget *)p_lab_si, COLOR_WHITE);
		p_plane->p_own_focus_widget = (HWidget *)p_lab_si;
		himage_load_frome_resource(i, DRAW_COM_RIGHT_IMG);
		hcontainer_set_bgimg(ccc, i);
	}
}

/* new global image */
static HImage *new_global_img(char *p_img_name, int i_support_png)
{
	HImage *p_img = himage_new();
	himage_set_support_png(p_img, i_support_png);
	himage_load_frome_resource(p_img, p_img_name);
	HIMAGE_CLEAR_ATTRIBUTE(p_img, IMAGE_ATTR_AUTO_FREE);
	HIMAGE_CLEAR_ATTRIBUTE(p_img, IMAGE_ATTR_AUTO_FREE_BUF);
	HIMAGE_CLEAR_ATTRIBUTE(p_img, IMAGE_ATTR_AUTO_RESET);

	return p_img;
}

void init_menubar()
{
	gp_mb_img_n = new_global_img(MENUBAR_IMG_N, 0);
	gp_mb_img_nl = new_global_img(MENUBAR_NOLINE, 0);
	gp_mb_img_p = new_global_img(MENUBAR_IMG_P, 0);
	gp_img_opt_item = new_global_img(POPUP_ITEM_IMG_P, 0);
	gp_loading_bg = new_global_img(LOADING_IMG, 1);
	gp_top_img = new_global_img(LOGO_IMG, 0);
	
	gp_img_cricket_bg = new_global_img(BACK_BG_IMG, 0);
	gp_img_cricket_home_bg = new_global_img(HOME_IMG, 0);
}

static void draw_menubar(char *lstr, char *rstr, ActionPerformed act_func)
{
	HMenuBar *p_mb = hmenubar_get_instance();

	hmenubar_set_text(lstr, rstr);
	if(NULL == lstr)
		HWIDGET_CLEAR_ATTRIBUTE(&p_mb->p_btn_left->base, ATTR_ENABLE_HOVER);
	else
		HWIDGET_SET_ATTRIBUTE(&p_mb->p_btn_left->base, ATTR_ENABLE_HOVER);
	if(NULL == rstr)
		HWIDGET_CLEAR_ATTRIBUTE(&p_mb->p_btn_right->base, ATTR_ENABLE_HOVER);
	else
		HWIDGET_SET_ATTRIBUTE(&p_mb->p_btn_right->base, ATTR_ENABLE_HOVER);
	ui_set_color((HWidget *)p_mb, COLOR_WHITE);
	p_mb->base.base.action_performed = act_func;
	ui_set_font((HWidget *)p_mb, FONT_LAGER);
	set_height((HWidget *)p_mb, MENU_BAR_HEIGHT);

	/* set attribute for spline.png */
	hmenubar_set_middle_space(2);//8
	if(NULL == lstr)
		hcontainer_set_bgimg(&p_mb->base, gp_mb_img_nl);
	else
		hcontainer_set_bgimg(&p_mb->base, gp_mb_img_n);

	hbutton_set_image(p_mb->p_btn_left, NULL);
	hbutton_set_image(p_mb->p_btn_right, NULL);
	HWIDGET_CLEAR_ATTRIBUTE(W(p_mb->p_btn_left), ATTR_ENABLE_BGCOLOR);
	HWIDGET_CLEAR_ATTRIBUTE(W(p_mb->p_btn_right), ATTR_ENABLE_BGCOLOR);
	ui_set_opaque((HWidget *)p_mb->p_btn_left, 0);
	ui_set_opaque((HWidget *)p_mb->p_btn_right, 0);
	ui_set_hover_color((HWidget *)p_mb->p_btn_left, COLOR_WHITE);
	ui_set_hover_color((HWidget *)p_mb->p_btn_right, COLOR_WHITE);
	hplane_set_bottom_widget(window->get_default_plane(), (HWidget *)p_mb);
	ui_invalidate((HWidget *)p_mb);
	ui_validate((HWidget *)p_mb);
}

static int g_bgcolor = 0;

/* add option item */
static void add_option_item(HButton *p_btn, char *pc_opt, int i_ptype, ActionPerformed act_func)
{
	hbutton_set_text(p_btn, pc_opt);
	ui_set_pad((HWidget *)p_btn, DRAW_MATCH_LIST_CON_GAP, 0, 0, 0);
	p_btn->base.pv_user_data = (void *)i_ptype;
	p_btn->base.action_performed = act_func;

#ifdef __QCIF_H__
	if(auto_refresh_setting_view == g_current_view)
		ui_set_size((HWidget *)p_btn, window->s_screen_width-3, SETTING_ITEM_HEIGHT);
	else
		ui_set_size((HWidget *)p_btn, window->s_screen_width, SETTING_ITEM_HEIGHT);
#else
	ui_set_size((HWidget *)p_btn, window->s_screen_width, SETTING_ITEM_HEIGHT);
#endif

	g_bgcolor?ui_set_bgcolor((HWidget *)p_btn, COLOR_LIST_BG_TWO):ui_set_bgcolor((HWidget *)p_btn, COLOR_LIST_BG_ONE);
	g_bgcolor = ~g_bgcolor;
	ui_set_hover_bgcolor((HWidget *)p_btn, COLOR_MSG_ORANGE);
	ui_set_hover_color((HWidget *)p_btn, COLOR_WHITE);
	hbutton_set_space(p_btn, OPT_TXT_IMG_SPACE);
	ui_set_border((HWidget *)p_btn, gp_bot_border);
	ui_set_font((HWidget *)p_btn, FONT_MEDIUM);
	hbutton_set_text_align(p_btn, ALIGN_LEFT | ALIGN_SPACE_TEXT_LEFT);
	hbutton_set_align(p_btn, ALIGN_LEFT);
	hlayout_add_widget(gp_verlayout, (HWidget *)p_btn);

	if(setting_view == g_current_view && i_ptype == g_pre_page_type)
	{
		hplane_set_own_focus_widget(window->get_default_plane(), (HWidget *)p_btn);
		gp_focus_widget = (HWidget *)p_btn;
	}
}

/* draw setting option */
static void draw_setting()
{
	g_bgcolor = 0;
	add_option_item(NEXT_BTN, TXT_REFRESH_INTERVAL, auto_refresh_setting_view, switch_view);
	add_option_item(NEXT_BTN, TXT_CHECK_FOR_UPDATE, check_for_update_view, switch_view);
	add_option_item(NEXT_BTN, TXT_HELP, help_view, switch_view);
	add_option_item(NEXT_BTN, TXT_ABOUT, about_view, switch_view);
}

/* draw help */
static void draw_help()
{
	hbutton_set_text(NEXT_BTN, "Yahoo! Cricket");
	ui_set_size((HWidget *)CUR_BTN, window->s_screen_width, VIEW_TOP_HEIGHT);
	ui_set_color((HWidget *)CUR_BTN, COLOR_WHITE);
	ui_set_enable((HWidget *)CUR_BTN, 0);
	ui_set_enable_focus((HWidget *)CUR_BTN, 0);
	ui_set_font((HWidget *)CUR_BTN, VIEW_TOP_FONT);
	hlayout_add_widget(gp_verlayout, (HWidget *)CUR_BTN);

	hlabel_set_text(NEXT_LAB, "All trademarks, logos and names are properties of their respective owners. Reference to any non-Yahoo! trademarks, logos and names is not intended to claim any association with the respective owners and should not be construed so. This is not the official website of Indian Premier League.");
	ui_set_font((HWidget *)CUR_LAB, HELP_ABOUT_FONT);
	set_width((HWidget *)CUR_LAB, window->s_screen_width);
	ui_set_pad((HWidget *)CUR_LAB, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, DRAW_MATCH_LIST_CON_GAP, 0);
	ui_set_color((HWidget *)CUR_LAB, COLOR_WHITE);
	hlayout_add_widget(gp_verlayout, (HWidget *)CUR_LAB);
}

/* draw about */
static void draw_about()
{
	hbutton_set_text(NEXT_BTN, get_version_number());
	ui_set_size((HWidget *)CUR_BTN, window->s_screen_width, window->s_screen_height - VIEW_TOP_HEIGHT - MENU_BAR_HEIGHT);
	ui_set_font((HWidget *)CUR_BTN, HELP_ABOUT_FONT);
	ui_set_color((HWidget *)CUR_BTN, COLOR_WHITE);
	ui_set_enable((HWidget *)CUR_BTN, 0);
	ui_set_enable_focus((HWidget *)CUR_BTN, 0);
	hlayout_add_widget(gp_verlayout, (HWidget *)CUR_BTN);
}

/* draw auto refresh */
static void draw_auto_refresh()
{
	int i;
	for(i = 0; i < 6; i ++)
		p_ref_opt[i] = NEXT_BTN;

	g_bgcolor = 0;
	add_option_item(p_ref_opt[0], TXT_15S, 15, action_autorefresh);
	add_option_item(p_ref_opt[1], TXT_30S, 30, action_autorefresh);
	add_option_item(p_ref_opt[2], TXT_1MINS, 60, action_autorefresh);
	add_option_item(p_ref_opt[3], TXT_5MINS, 300, action_autorefresh);
	add_option_item(p_ref_opt[4], TXT_10MINS, 600, action_autorefresh);
	add_option_item(p_ref_opt[5], TXT_NEVER, -1, action_autorefresh);

	p_check_img = NEXT_IMG;

	HIMAGE_CLEAR_ATTRIBUTE(p_check_img, IMAGE_ATTR_AUTO_FREE_BUF);
	HIMAGE_CLEAR_ATTRIBUTE(p_check_img, IMAGE_ATTR_AUTO_RESET);

	himage_set_support_png(p_check_img, 1);
	himage_load_frome_resource(p_check_img, CHECK_1_IMG);

	repaint_auto_refview(g_auto_refresh_time);
}

/* repaint auto refresh view page */
void repaint_auto_refview(int i_ref_time)
{
	hbutton_set_image(p_ref_opt[0], NULL);
	hbutton_set_image(p_ref_opt[1], NULL);
	hbutton_set_image(p_ref_opt[2], NULL);
	hbutton_set_image(p_ref_opt[3], NULL);
	hbutton_set_image(p_ref_opt[4], NULL);
	hbutton_set_image(p_ref_opt[5], NULL);
	switch(i_ref_time)
	{
	case 15:
		hbutton_set_image(p_ref_opt[0], p_check_img);
		hplane_set_own_focus_widget(window->get_default_plane(), (HWidget *)p_ref_opt[0]);
		gp_focus_widget = (HWidget *)p_ref_opt[0];
		break;

	case 30:
		hbutton_set_image(p_ref_opt[1], p_check_img);
		hplane_set_own_focus_widget(window->get_default_plane(), (HWidget *)p_ref_opt[1]);
		gp_focus_widget = (HWidget *)p_ref_opt[1];
		break;

	case 60:
		hbutton_set_image(p_ref_opt[2], p_check_img);
		hplane_set_own_focus_widget(window->get_default_plane(), (HWidget *)p_ref_opt[2]);
		gp_focus_widget = (HWidget *)p_ref_opt[2];
		break;

	case 300:
		hbutton_set_image(p_ref_opt[3], p_check_img);
		hplane_set_own_focus_widget(window->get_default_plane(), (HWidget *)p_ref_opt[3]);
		gp_focus_widget = (HWidget *)p_ref_opt[3];
		break;

	case 600:
		hbutton_set_image(p_ref_opt[4], p_check_img);
		hplane_set_own_focus_widget(window->get_default_plane(), (HWidget *)p_ref_opt[4]);
		gp_focus_widget = (HWidget *)p_ref_opt[4];
		break;

	case -1:
		hbutton_set_image(p_ref_opt[5], p_check_img);
		hplane_set_own_focus_widget(window->get_default_plane(), (HWidget *)p_ref_opt[5]);
		gp_focus_widget = (HWidget *)p_ref_opt[5];
		break;
	}
}

/* clean auto refresh page data */
void clean_auto_ref_data()
{
	int i;
	for(i = 0; i < 6; i ++)
		p_ref_opt[i] = NULL;

	himage_force_clean(p_check_img);
}

/* record focus widget */
void record_focus_widget(HWidget *p_widget, HFocusEvent *p_evt)
{
	if(p_evt->i_gain_focus)
		gp_focus_widget = p_widget;
	else
		gp_focus_widget = NULL;
}

/* key filter for RNK and LNK */
int key_filter(int i_evt, int key_code)
{

	if(HKEY_EVENT_UP == i_evt && (VM_KEY_LEFT == key_code || VM_KEY_RIGHT == key_code))
	{
		Page *p_cur = page_get_current();
		HWidget p_widget;
		HKeyEvent p_evt;

		if(NULL == p_cur)
			return 0;

		/* init event */
		p_evt.base.i_event_type = HKEY_EVENT_UP;
		p_evt.i_keycode = VM_KEY_OK;

		switch(p_cur->i_page_type)
		{
		case live_matches_view:
			if(VM_KEY_RIGHT == key_code)
			{
				p_widget.pv_user_data = (void *)news_view;
				switch_view(&p_widget, (HEvent *)(&p_evt), NULL);
			}
			return 1;
			break;

		case news_view:
			(VM_KEY_LEFT == key_code)?\
				(p_widget.pv_user_data = (void *)live_matches_view, switch_view(&p_widget, (HEvent *)(&p_evt), NULL)):\
				(p_widget.pv_user_data = (void *)photos_view, switch_view(&p_widget, (HEvent *)(&p_evt), NULL));
			return 1;
			break;

		case photos_view:
			(VM_KEY_LEFT == key_code)?\
				(p_widget.pv_user_data = (void *)news_view, switch_view(&p_widget, (HEvent *)(&p_evt), NULL)):\
				(p_widget.pv_user_data = (void *)teams_intl_view, switch_view(&p_widget, (HEvent *)(&p_evt), NULL));
			return 1;
			break;

		case teams_intl_view:
			(VM_KEY_LEFT == key_code)?\
				(p_widget.pv_user_data = (void *)photos_view, switch_view(&p_widget, (HEvent *)(&p_evt), NULL)):\
				(p_widget.pv_user_data = (void *)teams_ipl_view, switch_view(&p_widget, (HEvent *)(&p_evt), NULL));
			return 1;
			break;

		case teams_ipl_view:
			if(VM_KEY_LEFT == key_code)
			{
				p_widget.pv_user_data = (void *)teams_intl_view;
				switch_view(&p_widget, (HEvent *)(&p_evt), NULL);
			}
			return 1;
			break;

		case player_batting_view:
			if(VM_KEY_RIGHT == key_code)
			{
				p_widget.pv_user_data = (void *)player_bowling_view;
				switch_view(&p_widget, (HEvent *)(&p_evt), NULL);
			}
			return 1;
			break;

		case player_bowling_view:
			if(VM_KEY_LEFT == key_code)
			{
				p_widget.pv_user_data = (void *)player_batting_view;
				switch_view(&p_widget, (HEvent *)(&p_evt), NULL);
			}
			return 1;
			break;

		case match_cmtary_first_view:
			if(VM_KEY_RIGHT == key_code)
			{
				p_widget.pv_user_data = (void *)match_cmtary_second_view;
				switch_view(&p_widget, (HEvent *)(&p_evt), NULL);
			}
			return 1;
			break;

		case match_cmtary_second_view:
			if(VM_KEY_LEFT == key_code)
			{
				p_widget.pv_user_data = (void *)match_cmtary_first_view;
				switch_view(&p_widget, (HEvent *)(&p_evt), NULL);
			}
			return 1;
			break;

		case photos_detail_view:
			(VM_KEY_LEFT == key_code)?(pre_pht()):(next_pht());
			page_load_exists(p_cur);
			return 1;
			break;

		default:
			return 0;
			break;
		}
	}
	else if(HKEY_EVENT_UP == i_evt && VM_KEY_RIGHT_SOFTKEY == key_code && live_matches_view == g_current_view)
	{
		hwindow_exit();
		return 0;
	}
	else
		return 0;
}

/* draw prompt */
static void draw_prompt()
{
	p_cnt_prompt = NEXT_CNT;
	p_lab_prompt = NEXT_LAB;
	p_btn_prompt = NEXT_BTN;

	/* set attribute */
	himage_set_support_png(NEXT_IMG, 1);
	himage_load_frome_resource(CUR_IMG, PROMPT_BG_IMG);
	hcontainer_set_bgimg(p_cnt_prompt, CUR_IMG);
	ui_set_size((HWidget *)p_cnt_prompt, PROMPT_WIDHT, PROMPT_HEIGHT);
	ui_set_opaque((HWidget *)p_cnt_prompt, 0);
	ui_set_pad((HWidget *)p_cnt_prompt, PROMPT_CNT_LR_PAD, PROMPT_CNT_LR_PAD, PROMPT_CNT_LR_PAD, 0);
	ui_set_visible((HWidget *)p_cnt_prompt, 0);

	hbutton_set_image(p_btn_prompt, NEXT_IMG);
	himage_set_support_png(p_btn_prompt->p_image, 1);
	ui_set_enable((HWidget *)p_btn_prompt, 0);
	ui_set_enable_focus((HWidget *)p_btn_prompt, 0);
	ui_set_size((HWidget *)p_btn_prompt, OTA_IMG_WIDHT, OTA_IMG_HEIGHT);
	ui_set_position((HWidget *)p_btn_prompt, (MSG_CNT_WIDTH-PROMPT_CNT_LR_PAD*2-OTA_IMG_WIDHT)/2, 0);
	set_width((HWidget *)p_lab_prompt, PROMPT_WIDHT-PROMPT_CNT_LR_PAD*2);
#ifdef __LQVGA_H__
	ui_set_font((HWidget *)p_lab_prompt, FONT_MEDIUM);
#endif
	p_lab_prompt->base.c_font_size = PROMPT_FONT_SIZE;
	ui_set_color((HWidget *)p_lab_prompt, COLOR_WHITE);
	ui_set_position((HWidget *)p_lab_prompt, 0, OTA_IMG_HEIGHT);

	/* add to widget */
	hcontainer_add_widget(p_cnt_prompt, (HWidget *)p_btn_prompt);
	hcontainer_add_widget(p_cnt_prompt, (HWidget *)p_lab_prompt);
	hlayout_add_widget(gp_verlayout, (HWidget *)p_cnt_prompt);
}

/* set prompt font size */
void set_prompt_font_size(int i_font_size)
{
	p_lab_prompt->base.c_font_size = i_font_size;
}

/* set prompt */
void set_prompt(char *pc_str, char *pc_mb_left, char *pc_mb_right, ActionPerformed action_menu_bar, int i_img)
{
	hlabel_set_text(p_lab_prompt, pc_str);
	if(NULL != pc_str)
		ui_set_visible((HWidget *)p_cnt_prompt, 1);
	else
		ui_set_visible((HWidget *)p_cnt_prompt, 0);

	switch(i_img)
	{
	case 0: /* no image */
		himage_force_clean(p_btn_prompt->p_image);
		break;

	case 1: /* tick image */
		himage_load_frome_resource(p_btn_prompt->p_image, OTA_TICK);
		break;

	case 2: /* cross image */
		himage_load_frome_resource(p_btn_prompt->p_image, OTA_CROSS);
		break;
	}

	ui_notify_size_changed((HWidget *)p_btn_prompt);
	ui_notify_size_changed((HWidget *)p_lab_prompt);

	draw_menubar(pc_mb_left, pc_mb_right, action_menu_bar);

	window->repaint();
}

/* draw home page list */
static void draw_homepage_list()
{
	int x, y, height;
	HContainer *p_cnt = NEXT_CNT;
	HWidget *p_tmp = NULL;

	/* load arrow image */
	gp_temp_img = NEXT_IMG;
	himage_set_support_png(gp_temp_img, 1);
	himage_load_frome_resource(gp_temp_img, DRAW_TAB_BUTTON_UP);
	gp_list_down_img = NEXT_IMG;
	himage_set_support_png(gp_list_down_img, 1);
	himage_load_frome_resource(gp_list_down_img, DRAW_TAB_BUTTON_DOWN);

	/* set attribute */
	ui_set_pad((HWidget *)p_cnt, DRAW_LIST_MEMBER_CNT_X_GAP, DRAW_LIST_MEMBER_CNT_X_GAP, 2, 0);
	set_width((HWidget *)p_cnt, window->s_screen_width);
	ui_set_position((HWidget *)p_cnt, 0, HOME_PAGE_HEIGHT);

	x=y=height = 0;
	/* add recent matches option */
	p_tmp = (HWidget *)draw_set_list_member(switch_view, TXT_RECENT_MATCHES, COLOR_OPT_L, COLOR_MSG_ORANGE);
	p_tmp->pv_user_data = (void *)recent_matches_view;
	ui_set_position(p_tmp, x, y);
	height = ui_get_height(p_tmp);
	y += height+3;
	hcontainer_add_widget(p_cnt, p_tmp);
#ifndef __QCIF_H__
	draw_set_def_focus((HContainer *)p_tmp);
#endif

	/* add upcoming matches option */
	p_tmp = (HWidget *)draw_set_list_member(switch_view, "Upcoming matches", COLOR_OPT_L, COLOR_MSG_ORANGE);
	p_tmp->pv_user_data = (void *)upcoming_matches_view;
	ui_set_position(p_tmp, x, y);
	height = ui_get_height(p_tmp);
	y += height+3;
	hcontainer_add_widget(p_cnt, p_tmp);

	/* add on going matches option */
	p_tmp = (HWidget *)draw_set_list_member(switch_view, TXT_ONGOING_SERIES, COLOR_OPT_L, COLOR_MSG_ORANGE);
	p_tmp->pv_user_data = (void *)ongoing_matches_view;
	ui_set_position(p_tmp, x, y);
	hcontainer_add_widget(p_cnt, p_tmp);

	hplane_add_widget(window->get_default_plane(), (HWidget *)p_cnt);
}

static void draw_photo_detail_frame()
{
	short s_tp = 0;
	HContainer *c = NEXT_CNT;
	gsp_cnt_pic = NEXT_CNT;
	gsp_btn_pic = NEXT_BTN;
	gsp_lab_pic = NEXT_LAB;

	ui_set_enable((HWidget *)gsp_btn_pic, 0);

	/* set size and position */
	hcontainer_set_bgimg(gsp_cnt_pic, NEXT_IMG);
	ui_set_opaque((HWidget *)gsp_cnt_pic, 0);
	gsp_cnt_pic->base.pv_user_data = (void *)gp_default_img;
	s_tp = window->s_screen_height - TITLE_BAR_HEIGHT - MENU_BAR_HEIGHT-10;
	ui_set_size((HWidget *)gsp_cnt_pic, PHT_DETAIL_WIDTH, s_tp);
	set_max_width((HWidget *)gsp_lab_pic, MSG_CNT_WIDTH);
	ui_set_position((HWidget *)c, PHT_DETAIL_TXT_X, s_tp - PHT_TM_HEIGHT);
	ui_set_color((HWidget *)gsp_lab_pic, COLOR_WHITE);

	gsp_lab_pic->base.pv_user_data = (void *)c;
	ui_set_size((HWidget *)c, PHT_TM_WIDTH, PHT_TM_HEIGHT);
	hcontainer_add_widget(c, (HWidget *)gsp_lab_pic);
	/* add widget */
	hcontainer_add_widget(gsp_cnt_pic, (HWidget *)gsp_btn_pic);
	hcontainer_add_widget(gsp_cnt_pic, (HWidget *)c);

	/* set prev and next button */
	himage_set_support_png(NEXT_IMG, 1);
	himage_load_frome_resource(CUR_IMG, ARRAW_L_IMG);
	hbutton_set_image(NEXT_BTN, CUR_IMG);
	ui_set_position((HWidget *)CUR_BTN, ARROW_L_POS_X, ARROW_L_POS_Y);
	ui_set_opaque((HWidget *)CUR_BTN, 0);
	CUR_BTN->base.pv_user_data = (void *)VM_KEY_LEFT;
	CUR_BTN->base.action_performed = action_nxtpre_photo;
	ui_set_enable_focus((HWidget *)CUR_BTN, 0);
	hcontainer_add_widget(gsp_cnt_pic, (HWidget *)CUR_BTN);
	himage_set_support_png(NEXT_IMG, 1);
	himage_load_frome_resource(CUR_IMG, ARRAW_R_IMG);
	hbutton_set_image(NEXT_BTN, CUR_IMG);
	ui_set_position((HWidget *)CUR_BTN, ARROW_R_POS_X, ARROW_R_POS_Y);
	ui_set_opaque((HWidget *)CUR_BTN, 0);
	CUR_BTN->base.pv_user_data = (void *)VM_KEY_RIGHT;
	CUR_BTN->base.action_performed = action_nxtpre_photo;
	ui_set_enable_focus((HWidget *)CUR_BTN, 0);
	hcontainer_add_widget(gsp_cnt_pic, (HWidget *)CUR_BTN);

	hlayout_add_widget(gp_verlayout, (HWidget *)gsp_cnt_pic);
}

/* set photo detail content */
void set_photo_detail_cnt(char *pc_txt, char *pc_url)
{
	draw_limit_length(gsac_pht_title, PHT_TM_LENGHT);
	vm_chset_convert(VM_CHSET_UTF8, VM_CHSET_UCS2, gsac_pht_title, (char *)gac_wtext_buffer, MAX_TEXT_LENGTH);
	hlabel_set_ucs2_text(gsp_lab_pic, gac_wtext_buffer);
	ui_notify_size_changed((HWidget *)gsp_lab_pic);
	ui_set_position((HWidget *)gsp_lab_pic, (PHT_TM_WIDTH-ui_get_width((HWidget *)gsp_lab_pic))/2, (PHT_TM_HEIGHT-ui_get_height((HWidget *)gsp_lab_pic))/2);
	hcontainer_set_bgimg((HContainer *)gsp_lab_pic->base.pv_user_data, gp_temp_img_two);
	sprintf(gac_text_buffer, "%s%d", whether_null(get_album_id()), get_album_pos());
	bind_idurl_button(gsp_btn_pic, only_url_img, pc_url, (long long)strtod(gac_text_buffer, NULL));
}

static void auto_timer(int i_tid)
{
	switch(g_current_view)
	{
	case live_matches_view:
	case news_view:
	case photos_view:
	case teams_intl_view:
	case teams_ipl_view:
		vm_delete_timer_ex(i_tid);
		sgi_ref_timer = -1;
		page_delay_flag = 0;
		page_load_exists(page_get_current());
		break;
	default:
		vm_delete_timer_ex(i_tid);
		sgi_ref_timer = -1;
		break;
	}
}

static void load_default_img(char *pc_imag_f, char *pc_img_s)
{
	if(NULL != pc_imag_f)
	{
		gp_default_img = NEXT_IMG;
		himage_set_support_png(gp_default_img, 1);
		himage_load_frome_resource(gp_default_img, pc_imag_f);
		HIMAGE_CLEAR_ATTRIBUTE(gp_default_img, IMAGE_ATTR_AUTO_FREE_BUF);
		HIMAGE_CLEAR_ATTRIBUTE(gp_default_img, IMAGE_ATTR_AUTO_RESET);
	}

	if(NULL != pc_img_s)
	{
		gp_default_img_s = NEXT_IMG;
		himage_set_support_png(gp_default_img_s, 1);
		himage_load_frome_resource(gp_default_img_s, pc_img_s);
		HIMAGE_CLEAR_ATTRIBUTE(gp_default_img_s, IMAGE_ATTR_AUTO_FREE_BUF);
		HIMAGE_CLEAR_ATTRIBUTE(gp_default_img_s, IMAGE_ATTR_AUTO_RESET);
	}
}