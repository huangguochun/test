/*
 * Request HTTP data based on difference view type.
 */


#define HTTP_TIMEOUT 12000		/* old value is 8000 */

#define HTTP_HEAD_SIZE		52
//#define HTTP_YQL_HEAD		"http://mtk-mobile.query.yahooapis.com/v1/public/yql?"
#define HTTP_YQL_HEAD		"http://mtk-mobile.query.yahooapis.com/v1/yql?diagnostics=false&env=store%3A%2F%2Fng6U4PoINiRNNF51oAL7fn&format=json&"
#define HTTP_YQL_HEAD_XML	"http://mtk-mobile.query.yahooapis.com/v1/yql?diagnostics=false&env=store%3A%2F%2Fng6U4PoINiRNNF51oAL7fn&"
#define HTTP_YQL_FORMAT		"&format=json&env=store%3A%2F%2Fng6U4PoINiRNNF51oAL7fn"
#define HTTP_YQL_FORMAT_XML	"&env=store%3A%2F%2Fng6U4PoINiRNNF51oAL7fn"
#define POST_BODY_SIZE 1024
extern char gac_post_body[];
#define GET_BUF_SIZE	255
extern char gac_get_buff[];

typedef void (*http_callback_fp)(unsigned char* puc_buff, int i_size, short s_id);

void http_post(short view_type, http_callback_fp http_cb_func, int url_type);

void stop_http_request(void);
void stop_ota_load(void);

/* OTA design */
void http_ota_check(void);

/* OTA callback function */
void http_ota_cb(VMINT ota_hdl, void *ota_para);

/* get version number */
char* get_version_number(void);