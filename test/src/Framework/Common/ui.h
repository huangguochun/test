/*********************************
*file: ui.h
*author: yan.gao
*date: 2011.12.06
***********************************/
#ifndef _UI_H_
#define _UI_H_

#include "../WidgetLayer/hlabel.h"
#include "../WidgetLayer/hbutton.h"
#include "../WidgetLayer/hcontainer.h"
#include "../WidgetLayer/himage.h"
#include "../WidgetLayer/hplane.h"
#include "../Common/util.h"
#include "../WidgetLayer/hprocessbar.h"


/************************************************************************
*	global instance
************************************************************************/


extern HLabel		g_lab[];
extern HButton		g_btn[];
extern HContainer	g_cnt[];
extern HImage    	g_img[];
extern HLayout		g_layout[];
extern HBorder		g_border[];

extern int i_lab_idx;
extern int i_btn_idx;
extern int i_cnt_idx;
extern int i_img_idx;
extern int i_layout_idx;
extern int i_border_idx;

extern int i_lab_r_idx;
extern int i_btn_r_idx;
extern int i_cnt_r_idx;
extern int i_img_r_idx;

#define NEXT_LAB		(&g_lab[++ i_lab_idx])
#define NEXT_BTN		(&g_btn[++ i_btn_idx])
#define NEXT_CNT		(&g_cnt[++ i_cnt_idx])
#define NEXT_IMG		(&g_img[++ i_img_idx])
#define NEXT_BORDER		(&g_border[++ i_border_idx])

#define CUR_LAB			(&g_lab[i_lab_idx])
#define CUR_BTN			(&g_btn[i_btn_idx])
#define CUR_CNT			(&g_cnt[i_cnt_idx])
#define CUR_IMG			(&g_img[i_img_idx])
#define CUR_BORDER		(&g_border[i_border_idx])

#define NEXT_R_LAB		(&g_lab[-- i_lab_r_idx])
#define NEXT_R_BTN		(&g_btn[-- i_btn_r_idx])
#define NEXT_R_CNT		(&g_cnt[-- i_cnt_r_idx])
#define NEXT_R_IMG		(&g_img[-- i_img_r_idx])

#define CUR_R_LAB		(&g_lab[i_lab_r_idx])
#define CUR_R_BTN		(&g_btn[i_btn_r_idx])
#define CUR_R_CNT		(&g_cnt[i_cnt_r_idx])
#define CUR_R_IMG		(&g_img[i_img_r_idx])


/************************************************************************
* Get horizontal or vertical layout
************************************************************************/
HLayout * ui_next_hor_layout(void);

HLayout * ui_next_ver_layout(void);

/************************************************************************
* init all static widget, user should call it in app_main function
************************************************************************/
void ui_init_static_widget(void);

/************************************************************************
* reset all index(label index, button index, container index and so on) to init state
************************************************************************/
void ui_reset_index(void);
void ui_reset_r_index(void);

/************************************************************************
* backup all index
* @param i_id:  it only can be 0, 1, or 2
************************************************************************/
void ui_backup_idx(int i_id);

/************************************************************************
* restore all index
*@param i_id:  it only can be 0, 1, or 2
************************************************************************/
void ui_restore_idx(int i_id);


/************************************************************************
* open process bar 
* @param p_ac: if you don't want to it, set to NULL then it will use default action
************************************************************************/
#ifdef USE_PROCESSBAR

void ui_processbar_open(const char *p_text, ActionPerformed p_ac);

void ui_processbar_action_performed(HWidget *p_src, HEvent *p_evt, void *p_param);

void ui_processbar_cancel(const char *p_text);

#endif

/************************************************************************
* widget ops
************************************************************************/

void ui_set_visible(HWidget *p_widget, int i_visible);

void ui_set_enable_focus(HWidget *p_widget, int i_enable_focus);

void ui_set_has_focus(HWidget *p_widget, int i_focus);

void ui_set_enable(HWidget *p_widget, int i_enable);

void ui_set_enable_bgcolor(HWidget *p_widget, int i_bgcolor_enable);

void ui_set_enable_drag(HWidget *p_widget, int i_enable_drag);

void ui_set_bgcolor(HWidget *p_widget, int i_rgb);

void ui_set_enable_hover(HWidget *p_widget, int i_enable);

void ui_set_enable_hover_color(HWidget *p_widget, int i_enable);

void ui_set_enable_hover_bgcolor(HWidget *p_widget, int i_enable);

void ui_set_hover_bgcolor(HWidget *p_widget, int i_rgb);

void ui_set_hover_color(HWidget *p_widget, int i_rgb);

void ui_set_color(HWidget *p_widget, int i_rgb);

void ui_set_font(HWidget *p_widget, HFont font);

void ui_set_position(HWidget *p_widget, short s_top_x, short s_top_y);

short ui_get_width(HWidget *p_widget);

short ui_get_height(HWidget *p_widget);

void ui_set_size(HWidget *p_widget, short s_width, short s_height);

short ui_get_max_width(HWidget *p_widget);

short ui_get_max_height(HWidget *p_widget);

void ui_set_max_size(HWidget *p_widget, short s_max_width, short s_max_height);

void ui_set_opaque(HWidget *p_widget, int i_opaque);

void ui_set_border(HWidget *p_widget, HBorder *p_border);

void ui_notify_size_changed(HWidget *p_widget);

void ui_repaint(HWidget *p_widget);

void ui_validate(HWidget *p_widget);

void ui_invalidate(HWidget *p_widget);

#define ui_set_font_size(p_widget, i_size)	W(p_widget)->c_font_size = i_size


/************************************************************************
* loading ops
* Note: You must call ui_register_loading and  ui_unregister_loading matched
************************************************************************/
void ui_register_loading(HButton *p_btn);

void ui_unregister_loading(HButton *p_btn);

#endif