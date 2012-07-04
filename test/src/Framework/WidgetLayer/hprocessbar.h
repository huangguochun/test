/*********************************
*file: hprocessbar.h
*author: yan.gao
*date: 2011.12.16
***********************************/
#ifndef _HPROCESS_BAR_H
#define _HPROCESS_BAR_H

#include "hwidget.h"
#include "himage.h"

#define PB_MAX_TEXT_LEN	50
#define PB_LINE_SPACE 5

/************************************************************************
* Note:
*	(1). If user click any where on the screen, then the process bar will 
			emit a HCancelEvent(it's type is HCANCEL_EVENT). 
			And now if you want to hide the process bar, 
			please call hprocessbar_hide
*	(2). When the process bar hide, then it will emit a HCloseEvent(it's type is HCLOSE_EVENT)
************************************************************************/


typedef struct _HProcessBar {
	HWidget base;
	VMWCHAR pwc_text[PB_MAX_TEXT_LEN + 1];
	HImage *p_bgimg;
	HImage *p_loading_img;
	short s_frame_idx;
	short s_attr;
	short s_status;
	short s_locked;
	int i_tid;
	short s_text_x;
	short s_text_y;
	int i_timeout;
	Array text_lines;
} HProcessBar;

/************************************************************************
* Name : hprocessbar_get_instance
* Description : get the global unique HProcessBar instance
************************************************************************/
HProcessBar *hprocessbar_get_instance(void);

/************************************************************************
* Name : hprocessbar_set_bgimg
* Description : set the process bar's background image
************************************************************************/
void hprocessbar_set_bgimg(HImage *p_bgimg);

/************************************************************************
* Name : hprocessbar_set_loading_img
* Description : set the process bar's loading image
************************************************************************/
void hprocessbar_set_loading_img(HImage *p_img);

/************************************************************************
* Name : hprocessbar_set_text
* Description : set the process bar's message text
************************************************************************/
void hprocessbar_set_text(const char *p_text);

/************************************************************************
* Name : hprocessbar_set_ucs2_text
* Description : set the process bar's message text
************************************************************************/
void hprocessbar_set_ucs2_text(const VMWCHAR *pwc_text);

/************************************************************************
* Name : hprocessbar_hide
* Description : hide the process bar
************************************************************************/
void hprocessbar_hide(void);

/************************************************************************
* Name : hprocessbar_show
* Description : show the process bar. 
*	If the process bar is showing, you still allow call this function, 
*		and this will do nothing
************************************************************************/
void hprocessbar_show(void);

/************************************************************************
* Name : hprocessbar_hide_later
* Description : auto hide the process bar after special milliseconds
************************************************************************/
void hprocessbar_hide_later(int i_milliseconds);


#endif