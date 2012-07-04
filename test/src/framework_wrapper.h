/*****************************************************************
* File Name: framework_wrapper.h
*
* Description: framework interface's wrapper
*
* COPYRIGHT:
*
* Create on: 2011-01-11 Author: Liu,Heng
*
*Modified by name on $(Date)
******************************************************************/

#ifndef __FRAMEWORK_WRAPPER_H__
#define __FRAMEWORK_WRAPPER_H__

/**********************INCLUDE FILES******************************/
#include "hwidget.h"
#include "hbutton.h"

/* app exit */
void app_exit(void);

/* show tooltip */
void ui_show_tooltip(char *pc_prompt, int i_millisec);
void parse_string_s(const char *str);

/*****************************************************************
* Function Name: ui_set_pad
*
* Description: set widget pad: left, right, up, down
*
* Parameters:
* p_widget: HWidget instance pointer
* i_lpad: left pad value
* i_rpad: right pad value
* i_tpad: up pad value
* i_bpad: down pad value
*
* Return:
*****************************************************************/
void ui_set_pad(HWidget *p_widget, int i_lpad, int i_rpad, int i_tpad, int i_bpad);

/*****************************************************************
* Function Name: ui_show_loading
*
* Description: show loading
*
* Parameters:
* p_btn_load: button for loading
* x: loading position x
* y: loading position y
*
* Return:
*****************************************************************/
void ui_show_loading(HButton *p_btn_load, char *pc_str, int x, int y);

/*****************************************************************
* Function Name: ui_hide_loading
*
* Description: hide loading
*
* Parameters:
* p_btn_load: button for loading
*
* Return:
*****************************************************************/
void ui_hide_loading(HButton *p_btn_load);

/*****************************************************************
* Function Name: is_blank, trunc_blank
*
* Description: parse string whether is blank, truncation bland of the string's head and tail
*
* Parameters:
* pc_str: parsed char string
*
* Return:
*****************************************************************/
int is_blank(char *pc_str);
void trunc_blank(char *pc_str);


/* parse news detail xml */
void parse_news_body(char *pc_news);
void parse_news_detail_xml(char *pc_buff);

/* string to int number */
int h_atoi(char *pc_num);

/* judge string is null */
char* whether_null(char *pc_str);

/* compare two char string ignore capitalization */
int h_strncmpi(char *pc_str1, char *pc_str2, int len);

/* read config */
int read_config(void);

/* write config */
int save_config(int i_time);

/* loading widget */
void init_lm_s(void);
void ui_register_loading_s(HButton *p_btn);
void ui_unregister_loading_s(HButton *p_btn);
void ui_free_loading_img(void);
void ui_notify_loading_position();

#endif