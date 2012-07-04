/****************************************************************
* FILE Name: hbutton.h
* Description: button widget, that can show text and picture to screen.
* COPYRIGHT: 
* Created on: $(12.14.2011) Author: Geng,XuanXuan
****************************************************************/
#ifndef _WIDGET_BUTTON_H
#define _WIDGET_BUTTON_H

#include "hwidget.h"

#include "himage.h"

#define BUTTON_MAX_LEN 30

typedef struct _HButton HButton;


struct _HButton {
	HWidget base;

	char c_text_align;		/* text align relative to image */

	char c_align;			/* image and text align relative to button */
	short s_space;		/* space between text and image */

	short s_text_x;		/* text position relative to button*/
	short s_text_y;

	HImage *p_image;		/* image of button */

	VMWCHAR awc_text[BUTTON_MAX_LEN + 4];	/* text of button, 4 is memory for "..." */
};

/************************************************************************
* create a new button with default text, the text can be NULL
************************************************************************/
HButton * hbutton_new(char *pc_str);

/************************************************************************
* initialize a exist button with default text, the text can be NULL
************************************************************************/
void hbutton_init(HButton *p_this);

/************************************************************************
* clean button text and image by attr flag
************************************************************************/
void hbutton_clean(HButton *p_this);

/************************************************************************
* delete button by attr flag
************************************************************************/
void hbutton_delete(HButton *p_this);

/************************************************************************
* set text of button
************************************************************************/
void hbutton_set_text(HButton *p_this, char *pc_str);

/************************************************************************
* set ucs2 text of button
************************************************************************/
void hbutton_set_ucs2_text(HButton *p_this, VMWCHAR *p_ucs2);

/************************************************************************
* set image of button
************************************************************************/
void hbutton_set_image(HButton *p_this, HImage *p_img);

/************************************************************************
* set text align relative to image
************************************************************************/
void hbutton_set_text_align(HButton *p_this, int i_align);

/************************************************************************
* set text and image align relative to button
************************************************************************/
void hbutton_set_align(HButton *p_this, int i_align);

/************************************************************************
* set space between image and text
************************************************************************/
void hbutton_set_space(HButton *p_this, int i_space);

/************************************************************************
* set global default style for button
* the colors are RGB, example: 0xffffff is white
************************************************************************/
void hbutton_set_default_style(HBorder *p_border, int i_bgcolor, int i_hover_bgcolor, int i_color, int i_hover_color);


#endif
/********************* EOF ***********************/