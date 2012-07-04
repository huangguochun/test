/*
 * Here defines all the position related details
 */
#ifndef __POS_H__
#define __POS_H__

/* 320*480 */
//#ifdef __HVGA_H__

#define TXT_UPCOMING_MATCHES		"Upcoming matches"
#define TXT_NO_UPDATE				"                     No Update"
#define TXT_GET_VERSION_FAILED		"               get version failed"
#define VERSION_WIDTH				320
#define VERSION_HEIGHT				480
#define	OTA_IMG_WIDHT				52
#define OTA_IMG_HEIGHT				52

/* view top position data */
#define VIEW_TOP_HEIGHT			39
#define HOME_PAGE_HEIGHT		240
#define VIEW_TOP_FONT			FONT_LAGER
#define HELP_ABOUT_FONT			FONT_MEDIUM

/* title bar position data */
#define TITLE_BAR_HEIGHT		50
#define TITLE_BAR_HEIGHT_S		35
#define CMTARY_TITLE_BAR_HEIGHT	48//40
#define CMTARY_TITLEBAR_LR_PAD	10//0
#define CMTARY_TXT_Y			4//6
#define CMTARY_TXT_SPACE		4

/* search position data */
#define SEARCH_BAR_HEIGHT		40
#define SEARCH_HEIGHT			30
#define SEARCH_WIDTH			280
#define SEARCH_POSITION_X		20
#define SEARCH_POSITION_Y		5
#define SEARCH_TEXT_SIZE		30

/* option position data */
#define OPT_ITEM_HEIGHT			50
#define OPT_ITEM_WIDTH			200
#define OPT_TXT_IMG_SPACE		270
#define MENU_BAR_HEIGHT			34
#define SETTING_ITEM_HEIGHT		50

/* player detail */
#define LEFT_PAD				5
#define UP_PAD					10
#define MSG_PAD					4
#define PD_LEFT_PAD				40
#define PD_NAME_FONT			FONT_MEDIUM
#define PD_CNT_WIDTH			280
#define PD_PHT_WIDTH			64//40
#define PD_PHT_HEIGHT			64//40
#define PD_FLG_WIDTH			32
#define PD_FLG_HEIGTH			32
#define PD_MAX_WIDTH			(window->s_screen_width - DRAW_LIST_MEMBER_CNT_X_GAP*2)
#define PD_ICC_PAD				35
#define PD_ICC_HEIGHT			20
#define PD_STAT_HEIGHT			25
#define PD_STAT_ITEM_WIDTH		110
#define PD_STAT_TEST_WIDTH		70
#define PD_STAT_ODI_WIDTH		70
#define PD_STAT_T20_WIDTH		70
#define PD_STAT_ITEM_TB_PAD		9
#define PD_MAX_WIDTH_GAP		10
#define PD_STAT_LPAD			5
#define PD_FLG_IMG				team_flag_img

/* player profile and team BIO data */
#define PP_PHT_WIDTH			40
#define PP_PHT_HEIGHT			40
#define PP_LEFT_PAD				70
#define TB_FLG_WIDTH			80
#define TB_FLG_HEIGHT			50
#define TEAM_TYPE_HEIGHT_INTL	34
#define TEAM_TYPE_WIDHT_INTL	155
#define TEAM_TYPE_HEIGHT_IPL	34
#define TEAM_TYPE_WIDHT_IPL		153
#define TEAM_TYPE_HEIGHT		34
#define TEAM_TYPE_POSITION_X	165
#define TEAM_TYPE_POSITION_Y	3

/* news data */
#define NEWS_TITLE_WIDTH		300
#define NEWS_WRITER_WDTH		300
#define NEWS_TITLE_FONT			15

/* photo data */
#define PHT_COVER_WIDTH			50
#define PHT_COVER_HEIGHT		50
#define PHT_TITLE_WIDTH			240
#define PHT_DETAIL_WIDTH		308
#define PHT_DETAIL_HEIGHT		100
#define PHT_TITLE_FONT			18//20
#define PHT_NUM_FONT			15
#define PHT_DETAIL_POS_X		85
#define PHT_DETAIL_POS_Y		100
#define PHT_DETAIL_TXT_X		0
#define PHT_DETAIL_TXT_Y		340
#define ARROW_L_POS_X			10
#define ARROW_L_POS_Y			150
#define ARROW_R_POS_X			279
#define ARROW_R_POS_Y			150
#define PHT_TM_WIDTH			PHT_DETAIL_WIDTH
#define PHT_TM_HEIGHT			48
#define PHT_TM_LENGHT			38

/* prompt data */
#define PROMPT_HEIGHT			200
#define	PROMPT_WIDHT			300
#define PROMPT_LAYOUT_LR_PD		10
#define PROMPT_CNT_LR_PAD		30
#define PROMPT_CNT_TOP_PAD		200
#define PROMPT_FONT_SIZE		20
#define PROMPT_FONT_SIZE_TMP	20

/* common data */
#define MSG_CNT_WIDTH			308
#define MSG_CNT_TOP_PAD			10

/* loading data */
#define LOADING_WIDTH			185
#define LOADING_WIDTH_L			80
#define LAODING_HEIGHT			68
#define LOADING_POSITION_X		85
#define LOADING_POSITION_Y		100
#define LOADING_POSITION_NO_TITILE_Y	LOADING_POSITION_Y+ TITLE_BAR_HEIGHT
#define LOADING_POSITION_TEAM_Y	LOADING_POSITION_Y - TEAM_TYPE_HEIGHT

#define CMTARY_TITLE_TEXT_LENGTH 32
#define NEWS_LIST_TEXT_LENGTH	 75
#define PHOTO_LIST_TEXT_LEGTH	 40

//#endif

/* 240*320 */
#ifdef __QVGA_H__

#define TXT_UPCOMING_MATCHES		"  Upcoming matches"
#define TXT_NO_UPDATE				"              No Update"
#define TXT_GET_VERSION_FAILED		"         get version failed"
#define VERSION_WIDTH				240
#define VERSION_HEIGHT				320
#define	OTA_IMG_WIDHT				39
#define OTA_IMG_HEIGHT				39

/* view top position data */
#define VIEW_TOP_HEIGHT			29
#define HOME_PAGE_HEIGHT		200
#define VIEW_TOP_FONT			FONT_MEDIUM
#define HELP_ABOUT_FONT			FONT_MEDIUM

/* title bar position data */
#define TITLE_BAR_HEIGHT		38
#define TITLE_BAR_HEIGHT_S		25
#define CMTARY_TITLE_BAR_HEIGHT	38//40
#define CMTARY_TITLEBAR_LR_PAD	10//0
#define CMTARY_TXT_Y			0//4//6
#define CMTARY_TXT_SPACE		1

/* search position data */
#define SEARCH_BAR_HEIGHT		35
#define SEARCH_HEIGHT			30
#define SEARCH_WIDTH			210
#define SEARCH_POSITION_X		20
#define SEARCH_POSITION_Y		2
#define SEARCH_TEXT_SIZE		30

/* option position data */
#define OPT_ITEM_HEIGHT			38
#define OPT_ITEM_WIDTH			150
#define OPT_TXT_IMG_SPACE		200
#define MENU_BAR_HEIGHT			25
#define SETTING_ITEM_HEIGHT		50

/* player detail */
#define LEFT_PAD				5
#define UP_PAD					10
#define MSG_PAD					4
#define PD_LEFT_PAD				10
#define PD_NAME_FONT			FONT_SMALL
#define PD_CNT_WIDTH			200
#define PD_PHT_WIDTH			40
#define PD_PHT_HEIGHT			40
#define PD_FLG_WIDTH			32
#define PD_FLG_HEIGTH			32
#define PD_MAX_WIDTH			150
#define PD_ICC_PAD				15
#define PD_ICC_HEIGHT			20
#define PD_STAT_HEIGHT			25
#define PD_STAT_ITEM_WIDTH		80
#define PD_STAT_TEST_WIDTH		50
#define PD_STAT_ODI_WIDTH		50
#define PD_STAT_T20_WIDTH		50
#define PD_STAT_ITEM_TB_PAD		9
#define PD_MAX_WIDTH_GAP		10
#define PD_STAT_LPAD			0
#define PD_FLG_IMG				team_flag_round_img

/* player profile and team BIO data */
#define PP_PHT_WIDTH			40
#define PP_PHT_HEIGHT			40
#define PP_LEFT_PAD				40
#define TB_FLG_WIDTH			80
#define TB_FLG_HEIGHT			50
#define TEAM_TYPE_HEIGHT_INTL	34//30
#define TEAM_TYPE_WIDHT_INTL	114//155//145
#define TEAM_TYPE_HEIGHT_IPL	34//30
#define TEAM_TYPE_WIDHT_IPL		114//153//145
#define TEAM_TYPE_HEIGHT		34
#define TEAM_TYPE_POSITION_X	120
#define TEAM_TYPE_POSITION_Y	3

/* news data */
#define NEWS_TITLE_WIDTH		225
#define NEWS_WRITER_WDTH		225
#define NEWS_TITLE_FONT			15

/* photo data */
#define PHT_COVER_WIDTH			50
#define PHT_COVER_HEIGHT		50
#define PHT_TITLE_WIDTH			170
#define PHT_DETAIL_WIDTH		228
#define PHT_DETAIL_HEIGHT		145
#define PHT_TITLE_FONT			18//20
#define PHT_NUM_FONT			15
#define PHT_DETAIL_POS_X		35
#define PHT_DETAIL_POS_Y		25
#define PHT_DETAIL_TXT_X		0
#define PHT_DETAIL_TXT_Y		210
#define ARROW_L_POS_X			5
#define ARROW_L_POS_Y			100
#define ARROW_R_POS_X			204
#define ARROW_R_POS_Y			100
#define PHT_TM_WIDTH			PHT_DETAIL_WIDTH
#define PHT_TM_HEIGHT			48
#define PHT_TM_LENGHT			38

/* prompt data */
#define PROMPT_HEIGHT			180
#define PROMPT_WIDHT			220
#define PROMPT_LAYOUT_LR_PD		10
#define PROMPT_CNT_LR_PAD		15
#define PROMPT_CNT_TOP_PAD		60
#define PROMPT_FONT_SIZE		20
#define PROMPT_FONT_SIZE_TMP	20

/* common data */
#define MSG_CNT_WIDTH			230
#define MSG_CNT_TOP_PAD			10

/* loading data */
#define LOADING_WIDTH			160
#define LOADING_WIDTH_L			40
#define LAODING_HEIGHT			50
#define LOADING_POSITION_X		45
#define LOADING_POSITION_Y		50
#define LOADING_POSITION_NO_TITILE_Y	LOADING_POSITION_Y+ TITLE_BAR_HEIGHT
#define LOADING_POSITION_TEAM_Y	LOADING_POSITION_Y- TEAM_TYPE_HEIGHT

#define CMTARY_TITLE_TEXT_LENGTH 30
#define NEWS_LIST_TEXT_LENGTH	 55
#define PHOTO_LIST_TEXT_LEGTH	 30

#endif

/* 240*400 */
#ifdef __WQVGA_H__

#define TXT_UPCOMING_MATCHES		"  Upcoming matches"
#define TXT_NO_UPDATE				"              No Update"
#define TXT_GET_VERSION_FAILED		"         get version failed"
#define VERSION_WIDTH				240
#define VERSION_HEIGHT				400
#define	OTA_IMG_WIDHT				39
#define OTA_IMG_HEIGHT				39

/* view top position data */
#define VIEW_TOP_HEIGHT			29
#define HOME_PAGE_HEIGHT		200
#define VIEW_TOP_FONT			FONT_MEDIUM
#define HELP_ABOUT_FONT			FONT_MEDIUM

/* title bar position data */
#define TITLE_BAR_HEIGHT		38
#define TITLE_BAR_HEIGHT_S		25
#define CMTARY_TITLE_BAR_HEIGHT	38//40
#define CMTARY_TITLEBAR_LR_PAD	10//0
#define CMTARY_TXT_Y			0//4//6
#define CMTARY_TXT_SPACE		1

/* search position data */
#define SEARCH_BAR_HEIGHT		35
#define SEARCH_HEIGHT			30
#define SEARCH_WIDTH			210
#define SEARCH_POSITION_X		20
#define SEARCH_POSITION_Y		2
#define SEARCH_TEXT_SIZE		30

/* option position data */
#define OPT_ITEM_HEIGHT			38
#define OPT_ITEM_WIDTH			150
#define OPT_TXT_IMG_SPACE		200
#define MENU_BAR_HEIGHT			25
#define SETTING_ITEM_HEIGHT		50

/* player detail */
#define LEFT_PAD				5
#define UP_PAD					10
#define MSG_PAD					4
#define PD_LEFT_PAD				10
#define PD_NAME_FONT			FONT_SMALL
#define PD_CNT_WIDTH			200
#define PD_PHT_WIDTH			40
#define PD_PHT_HEIGHT			40
#define PD_FLG_WIDTH			32
#define PD_FLG_HEIGTH			32
#define PD_MAX_WIDTH			150
#define PD_ICC_PAD				15
#define PD_ICC_HEIGHT			20
#define PD_STAT_HEIGHT			25
#define PD_STAT_ITEM_WIDTH		80
#define PD_STAT_TEST_WIDTH		50
#define PD_STAT_ODI_WIDTH		50
#define PD_STAT_T20_WIDTH		50
#define PD_STAT_ITEM_TB_PAD		9
#define PD_MAX_WIDTH_GAP		10
#define PD_STAT_LPAD			0
#define PD_FLG_IMG				team_flag_round_img

/* player profile and team BIO data */
#define PP_PHT_WIDTH			40
#define PP_PHT_HEIGHT			40
#define PP_LEFT_PAD				40
#define TB_FLG_WIDTH			80
#define TB_FLG_HEIGHT			50
#define TEAM_TYPE_HEIGHT_INTL	34//30
#define TEAM_TYPE_WIDHT_INTL	114//155//145
#define TEAM_TYPE_HEIGHT_IPL	34//30
#define TEAM_TYPE_WIDHT_IPL		114//153//145
#define TEAM_TYPE_HEIGHT		34
#define TEAM_TYPE_POSITION_X	120
#define TEAM_TYPE_POSITION_Y	3

/* news data */
#define NEWS_TITLE_WIDTH		225
#define NEWS_WRITER_WDTH		225
#define NEWS_TITLE_FONT			15

/* photo data */
#define PHT_COVER_WIDTH			50
#define PHT_COVER_HEIGHT		50
#define PHT_TITLE_WIDTH			170
#define PHT_DETAIL_WIDTH		228
#define PHT_DETAIL_HEIGHT		145
#define PHT_TITLE_FONT			18//20
#define PHT_NUM_FONT			15
#define PHT_DETAIL_POS_X		35
#define PHT_DETAIL_POS_Y		25
#define PHT_DETAIL_TXT_X		0
#define PHT_DETAIL_TXT_Y		290
#define ARROW_L_POS_X			5
#define ARROW_L_POS_Y			140
#define ARROW_R_POS_X			204
#define ARROW_R_POS_Y			140
#define PHT_TM_WIDTH			PHT_DETAIL_WIDTH
#define PHT_TM_HEIGHT			48
#define PHT_TM_LENGHT			38

/* prompt data */
#define PROMPT_HEIGHT			180
#define PROMPT_WIDHT			220
#define PROMPT_LAYOUT_LR_PD		10
#define PROMPT_CNT_LR_PAD		30
#define PROMPT_CNT_TOP_PAD		150
#define PROMPT_FONT_SIZE		20
#define PROMPT_FONT_SIZE_TMP	20

/* common data */
#define MSG_CNT_WIDTH			230
#define MSG_CNT_TOP_PAD			10

/* loading data */
#define LOADING_WIDTH			160
#define LOADING_WIDTH_L			40
#define LAODING_HEIGHT			50
#define LOADING_POSITION_X		45
#define LOADING_POSITION_Y		100
#define LOADING_POSITION_NO_TITILE_Y	LOADING_POSITION_Y+ TITLE_BAR_HEIGHT
#define LOADING_POSITION_TEAM_Y	LOADING_POSITION_Y- TEAM_TYPE_HEIGHT

#define CMTARY_TITLE_TEXT_LENGTH 30
#define NEWS_LIST_TEXT_LENGTH	 50
#define PHOTO_LIST_TEXT_LEGTH	 30

#endif

/* 480*800 */
#ifdef __QCIF_H__

#define TXT_UPCOMING_MATCHES		"  Upcoming matches"
#define TXT_NO_UPDATE				"     No Update"
#define TXT_GET_VERSION_FAILED		"get version failed"
#define VERSION_WIDTH				176
#define VERSION_HEIGHT				220
#define	OTA_IMG_WIDHT				28
#define OTA_IMG_HEIGHT				28

/* view top position data */
#define VIEW_TOP_HEIGHT			21
#define HOME_PAGE_HEIGHT		180
#define VIEW_TOP_FONT			FONT_MEDIUM
#define HELP_ABOUT_FONT			FONT_SMALL

/* title bar position data */
#define TITLE_BAR_HEIGHT		28
#define TITLE_BAR_HEIGHT_S		18
#define CMTARY_TITLE_BAR_HEIGHT	38//40
#define CMTARY_TITLEBAR_LR_PAD	10//0
#define CMTARY_TXT_Y			3//4//6
#define CMTARY_TXT_SPACE		0

/* search position data */
#define SEARCH_BAR_HEIGHT		30
#define SEARCH_HEIGHT			25
#define SEARCH_WIDTH			150
#define SEARCH_POSITION_X		10
#define SEARCH_POSITION_Y		2
#define SEARCH_TEXT_SIZE		30

/* option position data */
#define OPT_ITEM_HEIGHT			28
#define OPT_ITEM_WIDTH			110
#define OPT_TXT_IMG_SPACE		140
#define MENU_BAR_HEIGHT			18
#define SETTING_ITEM_HEIGHT		30

/* player detail */
#define LEFT_PAD				5
#define UP_PAD					10
#define MSG_PAD					4
#define PD_LEFT_PAD				0
#define PD_NAME_FONT			FONT_SMALL
#define PD_CNT_WIDTH			140
#define PD_PHT_WIDTH			40
#define PD_PHT_HEIGHT			40
#define PD_FLG_WIDTH			32
#define PD_FLG_HEIGTH			32
#define PD_MAX_WIDTH			105
#define PD_ICC_PAD				5
#define PD_ICC_HEIGHT			40
#define PD_STAT_HEIGHT			20
#define PD_STAT_ITEM_WIDTH		55
#define PD_STAT_TEST_WIDTH		40
#define PD_STAT_ODI_WIDTH		40
#define PD_STAT_T20_WIDTH		40
#define PD_STAT_ITEM_TB_PAD		9
#define PD_MAX_WIDTH_GAP		10
#define PD_STAT_LPAD			0
#define PD_FLG_IMG				team_flag_round_img

/* player profile and team BIO data */
#define PP_PHT_WIDTH			40
#define PP_PHT_HEIGHT			40
#define PP_LEFT_PAD				10
#define TB_FLG_WIDTH			80
#define TB_FLG_HEIGHT			50
#define TEAM_TYPE_HEIGHT_INTL	28//34//30
#define TEAM_TYPE_WIDHT_INTL	82//155//145
#define TEAM_TYPE_HEIGHT_IPL	28//34//30
#define TEAM_TYPE_WIDHT_IPL		82//153//145
#define TEAM_TYPE_HEIGHT		28//34
#define TEAM_TYPE_POSITION_X	85
#define TEAM_TYPE_POSITION_Y	3

/* news data */
#define NEWS_TITLE_WIDTH		150
#define NEWS_WRITER_WDTH		150
#define NEWS_TITLE_FONT			15

/* photo data */
#define PHT_COVER_WIDTH			50
#define PHT_COVER_HEIGHT		50
#define PHT_TITLE_WIDTH			100
#define PHT_DETAIL_WIDTH		164
#define PHT_DETAIL_HEIGHT		145
#define PHT_DETAIL_POS_X		32
#define PHT_TITLE_FONT			15
#define PHT_NUM_FONT			15
#define PHT_DETAIL_POS_Y		0
#define PHT_DETAIL_TXT_X		0
#define PHT_DETAIL_TXT_Y		116//120
#define ARROW_L_POS_X			2
#define ARROW_L_POS_Y			70
#define ARROW_R_POS_X			150
#define ARROW_R_POS_Y			70
#define PHT_TM_WIDTH			PHT_DETAIL_WIDTH
#define PHT_TM_HEIGHT			48
#define PHT_TM_LENGHT			38

/* prompt data */
#define PROMPT_HEIGHT			100
#define PROMPT_WIDHT			150
#define PROMPT_LAYOUT_LR_PD		13
#define PROMPT_CNT_LR_PAD		2
#define PROMPT_CNT_TOP_PAD		60
#define PROMPT_FONT_SIZE		15
#define PROMPT_FONT_SIZE_TMP	15

/* common data */
#define MSG_CNT_WIDTH			170
#define MSG_CNT_TOP_PAD			10

/* loading data */
#define LOADING_WIDTH			160
#define LOADING_WIDTH_L			40
#define LAODING_HEIGHT			50
#define LOADING_POSITION_X		27
#define LOADING_POSITION_Y		50
#define LOADING_POSITION_NO_TITILE_Y	LOADING_POSITION_Y+ TITLE_BAR_HEIGHT
#define LOADING_POSITION_TEAM_Y	LOADING_POSITION_Y- TEAM_TYPE_HEIGHT

#define CMTARY_TITLE_TEXT_LENGTH 25
#define NEWS_LIST_TEXT_LENGTH	 35
#define PHOTO_LIST_TEXT_LEGTH	 20

#endif

#ifdef __LQVGA_H__

#define TXT_UPCOMING_MATCHES		"Upcoming matches"
#define TXT_NO_UPDATE				"           No Update"
#define TXT_GET_VERSION_FAILED		"             get version failed"
#define VERSION_WIDTH				320
#define VERSION_HEIGHT				240
#define	OTA_IMG_WIDHT				30
#define OTA_IMG_HEIGHT				30

/* view top position data */
#define VIEW_TOP_HEIGHT			39
#define HOME_PAGE_HEIGHT		235
#define VIEW_TOP_FONT			FONT_LAGER
#define HELP_ABOUT_FONT			FONT_MEDIUM

/* title bar position data */
#define TITLE_BAR_HEIGHT		32
#define TITLE_BAR_HEIGHT_S		35
#define CMTARY_TITLE_BAR_HEIGHT	48//40
#define CMTARY_TITLEBAR_LR_PAD	10//5
#define CMTARY_TXT_Y			4//6
#define CMTARY_TXT_SPACE		2

/* search position data */
#define SEARCH_BAR_HEIGHT		40
#define SEARCH_HEIGHT			30
#define SEARCH_WIDTH			280
#define SEARCH_POSITION_X		20
#define SEARCH_POSITION_Y		5
#define SEARCH_TEXT_SIZE		30

/* option position data */
#define OPT_ITEM_HEIGHT			30
#define OPT_ITEM_WIDTH			200
#define OPT_TXT_IMG_SPACE		270
#define MENU_BAR_HEIGHT			34
#define SETTING_ITEM_HEIGHT		50

/* player detail */
#define LEFT_PAD				5
#define UP_PAD					10
#define MSG_PAD					15//4
#define PD_LEFT_PAD				40
#define PD_NAME_FONT			FONT_MEDIUM
#define PD_CNT_WIDTH			280
#define PD_PHT_WIDTH			64//40
#define PD_PHT_HEIGHT			64//40
#define PD_FLG_WIDTH			32
#define PD_FLG_HEIGTH			32
#define PD_MAX_WIDTH			(window->s_screen_width - DRAW_LIST_MEMBER_CNT_X_GAP*2)
#define PD_ICC_PAD				35
#define PD_ICC_HEIGHT			20
#define PD_STAT_HEIGHT			25
#define PD_STAT_ITEM_WIDTH		110
#define PD_STAT_TEST_WIDTH		70
#define PD_STAT_ODI_WIDTH		70
#define PD_STAT_T20_WIDTH		70
#define PD_STAT_ITEM_TB_PAD		9
#define PD_MAX_WIDTH_GAP		10
#define PD_STAT_LPAD			5
#define PD_FLG_IMG				team_flag_img

/* player profile and team BIO data */
#define PP_PHT_WIDTH			40
#define PP_PHT_HEIGHT			40
#define PP_LEFT_PAD				70
#define TB_FLG_WIDTH			80
#define TB_FLG_HEIGHT			50
#define TEAM_TYPE_HEIGHT_INTL	34
#define TEAM_TYPE_WIDHT_INTL	155
#define TEAM_TYPE_HEIGHT_IPL	34
#define TEAM_TYPE_WIDHT_IPL		153
#define TEAM_TYPE_HEIGHT		34
#define TEAM_TYPE_POSITION_X	165
#define TEAM_TYPE_POSITION_Y	3

/* news data */
#define NEWS_TITLE_WIDTH		300
#define NEWS_WRITER_WDTH		300
#define NEWS_TITLE_FONT			15

/* photo data */
#define PHT_COVER_WIDTH			50
#define PHT_COVER_HEIGHT		50
#define PHT_TITLE_WIDTH			240
#define PHT_DETAIL_WIDTH		308
#define PHT_DETAIL_HEIGHT		100
#define PHT_TITLE_FONT			18//20
#define PHT_NUM_FONT			15
#define PHT_DETAIL_POS_X		85
#define PHT_DETAIL_POS_Y		40
#define PHT_DETAIL_TXT_X		0
#define PHT_DETAIL_TXT_Y		150
#define ARROW_L_POS_X			10
#define ARROW_L_POS_Y			60
#define ARROW_R_POS_X			279
#define ARROW_R_POS_Y			60
#define PHT_TM_WIDTH			PHT_DETAIL_WIDTH
#define PHT_TM_HEIGHT			48
#define PHT_TM_LENGHT			64

/* prompt data */
#define PROMPT_HEIGHT			150
#define	PROMPT_WIDHT			300
#define PROMPT_LAYOUT_LR_PD		10
#define PROMPT_CNT_LR_PAD		10
#define PROMPT_CNT_TOP_PAD		10
#define PROMPT_FONT_SIZE		20
#define PROMPT_FONT_SIZE_TMP	25

/* common data */
#define MSG_CNT_WIDTH			308
#define MSG_CNT_TOP_PAD			10

/* loading data */
#define LOADING_WIDTH			185
#define LOADING_WIDTH_L			60
#define LAODING_HEIGHT			68
#define LOADING_POSITION_X		85
#define LOADING_POSITION_Y		35
#define LOADING_POSITION_NO_TITILE_Y	LOADING_POSITION_Y+ TITLE_BAR_HEIGHT
#define LOADING_POSITION_TEAM_Y	LOADING_POSITION_Y - TEAM_TYPE_HEIGHT

#define CMTARY_TITLE_TEXT_LENGTH 32
#define NEWS_LIST_TEXT_LENGTH	 75
#define PHOTO_LIST_TEXT_LEGTH	 40

#endif

#endif
