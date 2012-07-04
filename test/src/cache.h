#ifndef CACHE_H
#define CACHE_H


typedef struct _CacheModel {
	char p_filename[40];
	int i_item_size;
	int i_max_items_count;
	int i_is_cache_img;
	int i_id_type;					/* 0 for long long, 1 for string */

	int i_real_items_count;
	int i_fd;
	void *p_header;
	void *p_it;

	void * (*read_txt)(int i_fd);
	int (*write_txt)(int i_fd, void *p_data);
} CacheModel;

enum {
	CM_MODE_BEGIN_INSERT,
	CM_MODE_END_INSERT
};

void cache_init(void);

int cm_open(CacheModel *p_cm);

void cm_close(CacheModel *p_cm);

int cm_update(CacheModel *p_cm, int i_idx, void *p_data);

void cm_delete(CacheModel *p_cm);

//---------txt--------------
void cm_read_txt(CacheModel *p_cm, int i_begin, int i_count, void (*cb)(void *, int));

void cm_read_txt_s(CacheModel *p_cm, char *p_id, short s_id, void (*cb)(void *, int));
void cm_read_txt_si(CacheModel *p_cm, int i_begin, int i_count, void (*cb)(void *, int));

int cm_write_txt(CacheModel *p_cm, void *p_data, int i_mode);

int cm_write_txt_s(CacheModel *p_cm, char *p_id, short s_id, void *p_data);

//---------image----------
void * cm_read_img(CacheModel *p_cm, char *p_id, int *p_len);

int cm_write_img(CacheModel *p_cm, char *p_id, void *p_data, int i_len);

/* live cache */
#define LIVE_CACHE_NUM			1
extern CacheModel g_live_cache;

/* news cache */
#define NEWS_LIST_CACHE_NUM		10
#define NEWS_DETAIL_CACHE_NUM	10
extern CacheModel g_news_list_cache;
extern CacheModel g_news_detail_cache;

/* photo cache */
#define PHOTO_LIST_CACHE_NUM	5
#define	PHOTO_PICTURE_CACHE_NUM	30
extern CacheModel g_photo_list_cache;
extern CacheModel g_photo_detail_cache;

/* team list cache */
#define TEAM_LIST_MNTL_CACHE_NUM		30
#define TEAM_LIST_IPL_CACHE_NUM			20
extern CacheModel g_team_intl_cache;
extern CacheModel g_team_ipl_cache;

/* team detail cache */
#define TEAM_DETAIL_CACHE_NUM			40
extern CacheModel g_team_detail_cache;

/* team fixtures */
#define TEAM_FIXTURES_CACHE_NUM			3
extern CacheModel g_team_fixtures_cache;

/* player list */
#define PLAYER_LIST_CACHE_NUM			40
#define PLAYER_DETAIL_CACHE_NUM			40
#define PLAYER_CAREER_CACHE_NUM			3
extern CacheModel g_player_list_cache;
extern CacheModel g_player_detail_cache;
extern CacheModel g_player_profile_cache;
extern CacheModel g_player_career_cache;
extern CacheModel g_player_batting_cache;
extern CacheModel g_player_bowling_cache;

/* recent match */
#define RCT_LIST_CACHE_NUM		3
#define RCT_DETAIL_CACHE_NUM	3
extern CacheModel g_rct_list_cache;
extern CacheModel g_rct_detail_cache;

/* score list */
#define MATCH_SCORE_CACHE_NUM	10
extern CacheModel g_score_cache;

/* score detail */
#define SCORE_DETAIL_CACHE_NUM	20
extern CacheModel g_score_detail_cache;

#define MATCH_CMTARY_CACHE_NUM	20
extern CacheModel g_cmtary_cache;

/* upcoming match */
#define UC_LIST_CACHE_NUM		3
#define UC_DETAIL_CACHE_NUM		3
extern CacheModel g_uc_list_cache;
extern CacheModel g_uc_detail_cache;

/* match head to head */
#define UC_HTH_CACHE_NUM		3
extern CacheModel g_uc_hth_cache;

/* match team player */
#define MATCH_TEAM_PLAYER_CACHE_NUM		40
extern CacheModel g_mteam_player_cache;

/* ongoing match */
#define OG_LIST_CACHE_NUM		3
#define OG_DETAIL_CACHE_NUM		3
extern CacheModel g_og_list_cache;
extern CacheModel g_og_detail_cache;

/* album cache */
#define PHOTO_FLAG_CACHE_NUM	50
extern CacheModel g_pht_flag_cache;
extern CacheModel g_img_id_url_cache;


#endif
