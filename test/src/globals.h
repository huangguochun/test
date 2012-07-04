/*
 * This is a lot of global definitions, all the modules need them to
 * corporate with each other.
 * XXX:
 * If you got any type of date that need to transfer through the app,
 * you can add them to here and notice all the people.
 */
#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <Common/ui.h>
#include <PageLayer/page.h>
#include <WindowLayer/hwindow.h>
#include "error_code.h"
#include "hlayout.h"
#include "htextinput.h"

/* RGB-888 To RGB-565 */
#define COLOR888_TO_COLOR565(color) ((color & 0xf8) >> 3) | ((color & 0xfc00) >> 5) | ((color & 0xf80000) >> 8)

#define view_type(cricket_view_t) cricket_view_t->base.i_page_type

typedef struct _cricket_view {
    Page base;

	/* prev page type */
	int i_prev_ptype;

	/* page data */
	int i_msg_id;

    /* may need some other view-unique fields */
    void *data;
} cricket_view_t;

enum view_type {
	live_matches_view  = 100	 ,
    recent_matches_view			 ,
    upcoming_matches_view		 ,
	ongoing_matches_view		 ,
	recnt_match_detail_view		 ,
	upcom_match_detail_view		 ,
	ongoing_match_details_view   ,
	match_score_view			 ,
	match_score_detail_view		 ,
	match_score_detail_down_view ,
	match_cmtary_first_view		 ,
	match_cmtary_second_view	 ,
	match_team_player_view		 ,
	match_hth_view				 ,

	news_view					 ,
	news_detail_view			 ,
	photos_view					 ,
	photos_detail_view			 ,

    player_details_view		     ,
    player_profile_view			 ,
	player_batting_view			 ,
	player_bowling_view			 ,
	player_career_view			 ,

	teams_intl_view				 ,
	teams_ipl_view				 ,
	teams_search_view			 ,
    team_details_view			 ,
	team_coach_captain_photo_view,
    team_player_view			 ,
	team_fixtures_view			 ,

    setting_view				 ,
    auto_refresh_setting_view	 ,
	check_for_update_view		 ,
    about_view					 ,
    help_view					 ,

    brower_view					 ,
	team_flag_img				 ,					/* round image */
	team_flag_small_img			 ,					/* small rect image */
	team_flag_big_img			 ,					/* big rect image */
	team_flag_round_img			 ,					/* small round image */
	team_flag_big_round_img		 ,					/* big round flag */
	player_pht_img				 ,
	only_url_img				 ,
	team_list_item_data
};

#define TEAM_PLAYER_NUM          40
#define HTH_NUM                  8
#define LIST_LENGTH              8
#define PLAYED_FOR_MAX_NUMBER    10
#define BATTING_BOWLING_NUM      20
#define FALL_WICKERS_NUM         15

struct _json_list_view_pool {
    char *name[2];
    unsigned int ranking;
    char *captain;
    char *coach;
};

struct team_list_item {
	int  team_id;
	char team_short_name[8];
};

struct player_list_item {
	char *player_name,
		 *head_img_url,
		 *ranking;
};

struct _list_view_data {
	enum {
		all_team_data,
		team_ranking_data,

		all_player_data,
		player_ranking_data
	} list_data_type;

	void *list_data; /* data object is TBD */
	void *next_data; /* data object is TBD */
};

struct _recent_score_batting{
    int   player_id;
	char  *player_first_name;       /*player first name of the batting score*/
	char  *player_last_name;
	char  *player_team;             /*the team of the player belong to*/
	char  *batting_c;               /*How batsman got out, such as Suresh Raina b Vinay KumarBowling */
	char  *batting_r;               /*such as 24*/
	char  *batting_b;               /*such as 25*/
	char  *batting_4s;              /*such as 3*/
	char  *batting_6s;              /*such as 14*/
	char  *batting_sr;              /*such as 94.00*/
};

struct _player_details_batting{
	char  *Matches;                 /*batting match*/
	char  *Innings;                 /*batting Innings*/
	char  *Runs;                    /*batting Runs*/
	char  *NotOuts;                 /*batting NO*/
	char  *Average;                 /*batting Avg*/
	char  *StrikeRate;              /*batting SR*/
	char  *Hundreds;                /*batting 100S*/
	char  *Fifties;                 /*batting 50S*/
	char  *content;                 /*batting HS*/
};

struct _player_details_bowling{
	char  *Matches;                 /*bowling match*/
	char  *Innings;                 /*bowling Innings*/
	char  *Runs;                    /*bowling Runs*/
	char  *Balls;                   /*bowling Balls*/
	char  *Average;                 /*bowling Average*/
	char  *Wickets;                 /*bowling Wickets*/
	char  *BBI_WT;                  /*bowling BBI WicketsTaken Such as 5/31 like 5*/
	char  *BBI_RG;                  /*bowling BBI RunsGiven    Such as 5/31 like 31*/
	char  *BBM;                     /*bowling BBM*/
	char  *EconomyRate;             /*bowling EconomyRate*/
	char  *FourWickets;             /*bowling 4*/
	char  *FiveWickets;             /*bowling 5*/
	char  *TenWickets;              /*bowling 10*/
	char  *Extra;
};

struct _json_parse_pool {
	/*the result is have or not*/
	int    data_flag;
	/*the result number*/
	int    data_count;
	/* */
	void   *p_private;

	/* live match */
	int    live_match_id;                 /*the id of live now*/
	char   *live_match_place;             /*the place of live now match, such as mumbai*/
	char   *live_match_mn;                /*the mn of live match, such as 2nd Test*/
	char   *left_team_name;               /*one team name*/
	char   *right_team_name;              /*another team name*/
	char   *left_team_logo;               /*one team logo*/
	char   *right_team_logo;              /*another team logo*/
	char   *live_match_date;              /*the live match data */
	char   *live_match_sn_team;           /*batting team ,such as WI*/ 
	char   *live_match_runs;              /*current runs. such as 346*/
	char   *live_match_wickets;           /*Wickets down. such as 3*/
	char   *live_match_overs;             /*Overs bowled. such as 110*/

	/*  recent match */
	int    recent_match_id;               /*the id of match*/
	int    recent_left_team_id;           /*the id of left team*/
	int    recent_right_team_id;          /*the id of right team*/
	int    recent_winner_team_id;         /*the id of winner team*/
	char   *recent_match_place;           /*the place of recent match, such as Dhabi*/
	char   *recent_match_mn;              /*the mn of  recent , such as 2nd Test*/
	char   *recent_left_team_short_name;  /*one team short name*/
	char   *recent_right_team_short_name; /*another team short name*/
	char   *recent_left_team_name;        /*one team name*/
	char   *recent_right_team_name;       /*another team logo*/
	char   *recent_left_team_logo;        /*one team logo*/
	char   *recent_right_team_logo;       /*another team logo*/
	char   *recent_winner_team;           /*the win team*/
	char   *recent_match_score;           /*the score. such as 3*/
	char   *recent_match_type;            /*the win type, such as wickets and runs*/
	char   *recent_date;                  /*the date of recent match*/

	/* recent match details, you can use recent match member such as recent_match_id,recent_match_score and so on*/
	char   *recent_details_man_match;     /*such as Patrick Cummins*/
	char   *recent_details_man_series;
	char   *recent_1st_innings_team;      /*such as SL*/
	char   *recent_1st_innings_runs;      /*such as 218*/
	char   *recent_1st_innings_wickets;   /*such as 9*/
	char   *recent_1st_innings_overs;     /*such as 50*/
    char   *recent_1st_innings_rr;        /*such as 4.36*/
	char   *recent_2nd_innings_team;      /*such as PAK*/
	char   *recent_2nd_innings_runs; 
	char   *recent_2nd_innings_wickets;
	char   *recent_2nd_innings_overs;
	char   *recent_2nd_innings_rr;

	/* recent match score, you can use the recent and recent details member */

	/* recent match score details*/
	char   *score_details_innings_team;      /*such as IND draw the head*/
	char   *score_details_innings_runs;      /*such as 218*/
	char   *score_details_innings_wickets;   /*such as 9*/
	char   *score_details_innings_overs;     /*such as 50*/
	char   *score_details_innings_rr;        /*such as 4.36*/
	char   *recent_score_details_extras_b;               /*such as 0*/
	char   *recent_score_details_extras_lb;              /*such as 1*/
	char   *recent_score_details_extras_w;               /*such as 2*/
	char   *recent_score_details_extras_nb;              /*such as 0*/
	char   *recent_score_details_innings_team;           /*can be cancel*/
	struct _recent_score_batting  recent_score_batting[BATTING_BOWLING_NUM]; 

	/* recent match commentary*/
	int    recent_comary_up_left_number;  /*such as 79*/
	int    recent_comary_up_right_number; /*such as 6*/
	char   *recent_comary_up_number;      /*such as 79.6*/
	char   *recent_comary_down_number;    /*such as 0*/
	char   *recent_comary_shc;            /*such as F Edwards to Lawman*/
	char   *recent_comary_content;        /*the content of recent match commentary*/

	/* upcoming match*/
	int    upcoming_match_id;
	int    upcoming_left_team_id;          /*the id of left team*/
	int    upcoming_right_team_id;         /*the id of right team*/
	char   *upcoming_left_team_name;       /*one team name*/
	char   *upcoming_left_team_short_name; /*one team short name*/
    char   *upcoming_right_team_name;      /*another team name*/
	char   *upcoming_right_team_short_name;/*another team short name*/
	char   *upcoming_match_mn;             /*the mn of  upcoming , such as 1st, ODI*/
	char   *upcoming_match_place;          /*the place of upcoming match, such as Mirpur*/
	char   *upcoming_match_start_time;     /*the time of the match begin, such as 04:00 PM GMT*/
	char   *upcoming_data;                 /*the date of upcoming match*/
	char   *upcoming_type;                 /*the type of upcoming*/

	/* upcoming match details*/
	/* you can use the all upcoming match member*/

	/* match team player*/
	int    upcoming_match_team_play_id;          /*the id of player*/
	char   *upcoming_match_team_play_frist_name;  /*the first name of player*/
	char   *upcoming_match_team_play_last_name;   /*the first name of player*/
	char   *upcoming_match_team_play_match;       /*the match of player*/
	char   *upcoming_match_team_play_avg;         /*the avg of player*/
	char   *upcoming_match_team_coach_frist_name; /*the coach of team*/
	char   *upcoming_match_team_coach_last_name;  /*the coach of team*/
	char   *upcoming_match_team_caption_frist_name; /*the caption of the team*/
	char   *upcoming_match_team_caption_last_name;  /*the caption of the team*/

	/* upcoming head to head*/
	int    upcoming_hth_result[2][HTH_NUM];       /*the left team list of hth*/
	char   *upcoming_hth_left_short_name;         /*such as IND*/
	char   *upcoming_hth_right_short_name;        /*such as WI*/

	/* ongoing match*/
	int    ongoing_match_id;                       /* the id of the match*/
	int    ongoing_match_Partnership_up_player_id;          
	int    ongoing_match_Partnership_down_player_id;
	char   *ongoing_match_place;                   /*the place of live now match, such as mumbai*/
	char   *ongoing_match_mn;                      /*the mn of live match, such as 2nd Test*/
	char   *ongoing_left_short_team_name;          /*one team short name*/
	char   *ongoing_right_short_team_name;         /*another team short name*/
	char   *ongoing_left_team_name;                /* one team name*/  
	char   *ongoing_right_team_name;               /*another team name*/
	char   *ongoing_left_team_logo;                /*one team logo*/
	char   *ongoing_right_team_logo;               /*another team logo*/
	char   *ongoing_match_date;                    /*the live match data */
	char   *ongoing_match_sn_team;                 /*batting team ,such as WI*/ 
	char   *ongoing_match_runs;                    /*current runs. such as 346*/
	char   *ongoing_match_wickets;                 /*Wickets down. such as 3*/
	char   *ongoing_match_overs;                   /*Overs bowled. such as 110*/
	char   *ongoing_match_1st_sn_team;             /*batting team ,such as WI*/ 
	char   *ongoing_match_1st_runs;                /*current runs. such as 346*/
	char   *ongoing_match_1st_wickets;             /*Wickets down. such as 3*/
	char   *ongoing_match_1st_overs;               /*Overs bowled. such as 110*/


	/* ongoing details, also you can use some variable in ongoing match */
	char   *ongoing_match_button_sn_team;         /*batting team ,such as WI*/ 
	char   *ongoing_match_button_runs;            /*current runs. such as 346*/
	char   *ongoing_match_button_wickets;         /*Wickets down. such as 3*/
	char   *ongoing_match_button_overs;           /*Overs bowled. such as 110*/
	char   *ongoing_match_Partnership_up_palyer_frist_name;
	char   *ongoing_match_Partnership_down_palyer_frist_name;
	char   *ongoing_match_Partnership_up_palyer_photo;       /*the url of the player photo*/
	char   *ongoing_match_Partnership_down_palyer_photo;     /*the url of the player photo*/
	char   *ongoing_match_state;                             /*such as play in process*/
	char   *ongoing_match_Partnership_cp;                    /*such as 9*/
	char   *ongoing_match_Partnership_bls;                   /*such as 12*/
	char   *ongoing_match_Partnership_up_r;                  /*such as 12*/
	char   *ongoing_match_Partnership_up_b;                  /*such as 12*/
	char   *ongoing_match_Partnership_up_six;                /*such as 12*/
	char   *ongoing_match_Partnership_up_four;               /*such as 12*/
	char   *ongoing_match_Partnership_up_sr;                 /*such as 12*/
	char   *ongoing_match_Partnership_down_r;                /*such as 12*/
	char   *ongoing_match_Partnership_down_b;                /*such as 12*/
	char   *ongoing_match_Partnership_down_six;              /*such as 12*/
	char   *ongoing_match_Partnership_down_four;             /*such as 12*/
	char   *ongoing_match_Partnership_down_sr;               /*such as 12*/


	/* upcoming match details*/
	/* you can use the all upcoming match member*/

	/* teams */
	int    team_id;                       /*the team id*/
	int    team_coach_id;                  /*the id of team coach*/
	int    team_caption_id;                /*the id of team caption*/
	char   *team_name;                    /*the name of one team*/
	char   *team_logo;                    /*the logo url of one team*/

	/* team detail*/
	/* you can use the teams member like team_id, team_name and team_logo*/
	char   *team_ranking_odi;              /*the ranking of odi type, like 6,if the team do not
													   join in this match, it is null*/
	char   *team_ranking_test;             /*the ranking of test type,like 5,if the team do not
													   join in this match, it is null*/
	char   *team_caption_first_name;       /*the caption first name, like Graeme*/
	char   *team_caption_last_name;        /*the caption last name, like Swann*/
	char   *team_coach_first_name;         /*the coach first name, like Andy*/
	char   *team_coach_last_name;          /*the coach last name,like Flower*/
	char   *team_caption_photo;            /*the url of the caption photo */
	char   *team_coach_photo;              /*the url of the coach photo  */
	char   *team_coach_name;
	char   *team_type;

	/* team fixtures*/
	int    team_fixtures_match_id;
	int    team_fixtures_left_team_id;
	int    team_fixtures_right_team_id;
	char   *team_fixtures_match_type;
	char   *team_fixtures_left_short_name;
	char   *team_fixtures_right_short_name;
	char   *team_fixtures_mn;
	char   *team_fixtures_place;
	char   *team_fixtures_data;

	/* player list */
	int    player_id;                      /*the player id*/
	int    player_belong_team_id;          /*the id of the team that the player belong*/
	char   *player_first_name;             /* player first name; */
	char   *player_last_name;              /* player first name; */
	char   *player_photo;                  /* the photo of players*/

	/*player profile*/
	char   *player_profile;                /*the profile of the player*/
	char   *player_role;                   /*the role of player, such as Skipper-T20 | Bowler*/
	
	/* player detail */
	char   *player_batting_style;
	char   *player_bowling_style;
	char   *player_played_for[PLAYED_FOR_MAX_NUMBER];             /*the played for of player,such as England, England Under-19*/
	char   *player_born_time;              /*the time of player born, such as 1977-03-02T00:00:00+05:30*/
	char   *player_born_place;             /*the place of player born, such as Johannesburg, Transvaal, South Africa*/
	char   *player_batting_score_T20;      /*the batting score of batting of t20*/
	char   *player_bowling_score_T20;      /*the bowling score of batting of t20*/
	char   *player_batting_score_ODI;      /*the batting score of batting of ODI*/
	char   *player_bowling_score_ODI;      /*the bowling score of batting of ODI*/
	char   *player_batting_score_Test;     /*the batting score of batting of Test*/
	char   *player_bowling_score_Test;     /*the bowling score of batting of Test*/

	/*player debut*/
	char   *player_rank_type;              /*such as test odi*/
	char   *player_debut_left_team_name;   /*such as England*/
	char   *player_debut_right_team_name;  /*such as India*/
	char   *player_debut_date;             /*such as Dec 11, 2008*/
	char   *player_debut_place;
	char   *player_lastplayed_left_team_name;  /*such as England*/
	char   *player_lastplayed_right_team_name; /*such as Pakistan*/
	char   *player_lastplayerd_date;           /*such as Jan 25, 2012*/
	char   *player_lastplayerd_place;

	/*player batting*/
	struct _player_details_batting       Batting_Test;
	struct _player_details_batting       Batting_T20;
	struct _player_details_batting       Batting_ODI;
	struct _player_details_bowling       Bowling_Test;
	struct _player_details_bowling       Bowling_T20;
	struct _player_details_bowling       Bowling_ODI;

	/* news */
	char   *new_id;                       /*the id of new*/
	char   *new_author;                   /*the author of new*/
	char   *new_title;                    /*the title of new*/
	char   *new_date;                     /*the date of new*/

	/* new details*/
	char   *new_details;                  /*the details of new, it is a xml buff*/

	/* photo album */
	int    photo_album_photocount;        /*the number of photo int the album,such as 10*/
	char   *photo_album_id;                /*the id of the photo album*/
	char   *photo_album_title;            /*the title of photo album, such as South Africa vs Sri Lanka 1st ODI*/
	char   *photo_album_thumb_url;        /*the thumb url of the photo album, if the photo count is 0, he is null*/

	/*photo details*/
	char   *photo_id;                     /*the id of photo*/
	char   *photo_details_description;    /*the PhotoDescription*/
	char   *photo_details_url;            /*the url of photo*/
};

/* static text, added by lh */
#define TXT_CRICKET					"Cricket"
#define	TXT_OPTIONS					"Options"
#define TXT_SELECT					"Select"
#define TXT_BACK					"Back"
#define TXT_CANCEL					"Cancel"
#define TXT_OK						"Ok"
#define TXT_YES						"Yes"
#define TXT_NO						"No"
#define TXT_MATCHES					"Matches"
#define TXT_NEWS					"News"
#define TXT_LATEST_NEWS				"Latest News"
#define TXT_PHOTOS					"Photos"
#define TXT_LATEST_PHOTOS			"Latest Photos"
#define TXT_PLAYERS					"Players"
#define TXT_TEAMS					"Teams  "
#define TXT_REFRESH					"Refresh"
#define TXT_REFRESH_INTERVAL		"Refresh Interval"
#define TXT_REFRESHING				"Refreshing"
#define TXT_SETTING					"Settings"
#define TXT_CHECK_FOR_UPDATE		"Check for update"
#define TXT_PREV					"Prev"
#define TXT_NEXT					"Next"
#define TXT_LIVE_NOW				"Live Now"
#define TXT_RECENT_MATCHES			"Recent matches"
#define TXT_ONGOING_SERIES			"Ongoing series"
#define TXT_ALL						"All"
#define TXT_RANKING					"Ranking"
#define	TXT_SEARCH					"Search"
#define TXT_AUTO_REFRESH_SET		"Auto refresh set"
#define TXT_HELP					"Help"
#define TXT_ABOUT					"About"
#define TXT_LOADING					"Loading...."
#define TXT_SCORE					"Score"
#define TXT_COMMENTARY				"Commentary"
#define TXT_HEAD2HEAD				"Head 2 Head"
#define TXT_PROFILE					"Profile"
#define TXT_STATISTICS				"Statistics"
#define TXT_CAREER					"Career"
#define TXT_BATTING					"Batting"
#define TXT_BOWLING					"Bowling"
#define TXT_END_PLAYERS				"END Players"
#define TXT_END_BIO					"END Bio"
#define TXT_FIXTURES				"Fixtures"
#define TXT_END_FIXTURES			"END Fixtures"
#define TXT_TEAM_RECORDS			"Team Records"
#define TXT_MENS_INTL				"Mens Intl."
#define TXT_SWITCH_TO_IPL			"IPL"
#define TXT_15S						"15 s    "
#define TXT_30S						"30 s    "
#define TXT_1MINS					"1 min  "
#define TXT_5MINS					"5 min  "
#define TXT_10MINS					"10 min "
#define TXT_NEVER					"Never"
#define TXT_WHETHER_DOWNLOAD		"A latest version is available.Do you want to download?"
#define TXT_ALREADY_DOWNLOAD		"The latest version is already downloaded."
#define TXT_DOWNLOAD_SUCESS			"Download successful."
#define TXT_WHETHER_INSTALL			"Do you want to update application now?It will exit running app."
#define TXT_WHETHER_LAUNCH			"Update success.Launch application now?"
#define TXT_INNINGS					"Innings"
#define TXT_RUNS					"Runs"
#define TXT_NOO						"NO"
#define TXT_AVG						"Avg."
#define TXT_SR						"SR"
#define TXT_100S					"100's"
#define TXT_50S						"50's"
#define TXT_HS						"HS"
#define TXT_TEST					"Test"
#define TXT_ODI						"ODI"
#define TXT_T20						"T20"
#define TXT_BALLS					"Balls"
#define TXT_WRICKETS				"Wickets"
#define TXT_BBM						"BBM"
#define TXT_ECON					"Econ."
#define TXT_4W						"4w"
#define TXT_5W						"5w"
#define TXT_10W						"10w"
#define TXT_EXTRAS					"Extras"
#define TXT_DEBUT					"Debut:"
#define TXT_LAST_PLAYED				"Last played:"
#define TXT_LIVE_NO_DATA			"No live matches in progress."
#define TXT_LIVE_NO_DATA			"No live matches in progress."
#define TXT_RANGKINGS				"Rankings"
#define TXT_COACH					"(Coach)"
#define TXT_COACH_					"Coach"
#define TXT_CAPTAIN					"(Captain)"
#define TXT_IND						"IND"
#define TXT_WI						"WI"
#define TXT_VIEW_MORE				"view more"
#define TXT_TOTAL_SCORE				"Total Score"
#define TXT_FALL_WICKETS			"Fall of Wickets"
#define TXT_ICC_RANK				"ICC Rank"
#define TXT_NET_FAILED				"Network connection failed"
#define TXT_DATA_FAILED				"Data parse failed"

/* end add */

/* color value, added by lh */
#define COLOR_WHITE					0xffffff
#define COLOR_OPT_ITEM				0x1f1f1f
#define COLOR_OPT_L					0x4e4e4e
#define COLOR_BLK					0x000000
#define COLOR_RED					0xff0000
#define COLOR_GREEN					0x00ff00
#define COLOR_BLUE					0x0000ff
#define COLOR_GRAY					0xcccccc
#define COLOR_TOP_GRAY				0x404040
#define COLOR_BAR_GRAY				0x8C8C8C
#define COLOR_MSG_ORANGE			0xE68900
#define COLOR_MAIN_HUE				0x002C52
#define COLOR_LOADING_BG			0x5D5D5F
#define COLOR_OPT_BORDER			0xbababa
#define COLOR_LIST_BG_ONE			0xf9f9f9
#define COLOR_LIST_BG_TWO			0xececec

#define TOOLTIP_TIME				2000

/* struct data for message */
typedef struct MSG_DATA
{
	int i_id;
	char pc_id[64];
	char *pc_msg;
	int i_msg;
	int i_page_type;

	HWidget *p_widget;
} Msg_data;

/* struct image data */
typedef struct IMG_DATA
{
	/* widget for repaint */
	long long i_id;
	char *pc_url;
	char *p_tmp;
	int i_img_type;
	/* data for image request */
	HButton *p_btn;
} Img_data;

/* global widget, global data, added by lh */
extern HLayout *gp_verlayout;
extern HTextInput *gp_textinput;
extern HBorder *gp_bot_border;
extern HWidget *gp_focus_widget;
extern HBorder *gp_temp_border;
extern HBorder *gp_popmenu_border;
extern HBorder *gp_loading_border;
extern int g_auto_refresh_time;
extern HContainer *gp_cnt_content;
extern HButton *gp_btn_load;
extern HButton *gp_btn_load_r;
extern HContainer *gp_cnt_load;
extern HImage *gp_loading_bg;
extern HImage *gp_mb_img_n;
extern HImage *gp_mb_img_nl;
extern HImage *gp_mb_img_p;
extern HImage *gp_list_down_img;
extern HImage *gp_top_img;

extern HImage *gp_default_img;
extern HImage *gp_default_img_s;

extern HImage *gp_img_cricket_bg;
extern HImage *gp_img_cricket_home_bg;
extern HImage *gp_img_opt_item;

extern int team_search_flag;
extern int cache_or_http_flag;  /* 0 for cache, 1 for http */

#define MAX_TEXT_LENGTH				1024
#define MAX_HTTP_MSG_NUM			60
#define MAX_IMG_DATA_NUM			60
extern char gac_search_team[];				/* search team */	
extern char gac_text_buffer[];				/* text buffer for join http data */
extern VMWCHAR gac_wtext_buffer[];
extern Msg_data g_msg_data[];				/* message data for every message's storage */
extern int gi_msg_data_cur;					/* position of current message data */
extern int gi_msg_data_num;					/* message data number */
extern char *gpc_http_buf;					/* buf for save http buffer */
extern char *gpc_http_buf_sec;				/* buf second for save http buffer */
extern Img_data g_img_data[];				/* image data for image storage */
extern int gi_img_data_cur;					/* position of current image data */
extern int gi_img_data_num;					/* image data number */
extern int page_delay_flag;					/* 0 for request, 1 for delay, 2 for read cache */

/* image for page */
extern HImage	*gp_temp_img;
extern HImage	*gp_temp_img_two;
extern HImage	*gp_msg_img;
extern void *gp_private_data;
/* end add */

struct _img_url {
	char *player_head_img_url;
	char *coach_head_img_url;
	char *captain_head_img_url;
	char *team1_flag_url;
	char *team2_flag_url;
};

struct _remote_image_urls {
	void *owner;
    char *url;
};

extern int g_current_view;
extern int g_pre_page_type;
#define MAX_IMAGE_URL_NUM 64
extern struct _remote_image_urls g_img_urls[MAX_IMAGE_URL_NUM];
extern struct _json_parse_pool g_parse_pool;
extern struct _img_url g_img_url;
#define REFRESH_TIME_LEN 25
extern char gac_refresh_time[REFRESH_TIME_LEN];
extern char gc_current_profile;
#define CURRENT_TIME_LEN 64
extern char gac_current_time[CURRENT_TIME_LEN];
extern struct team_list_item g_team_list[TEAM_PLAYER_NUM];

/* bind url or id with button */
void bind_idurl_button(HButton *p_btn, int i_img_type, char *pc_url, long long i_id);

/* get team abbreviation */
char* get_team_abbre(int tid);
#endif


 