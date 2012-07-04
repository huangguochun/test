/**********************************************************************
* FILE Name: HCheckBox.h
* Description: Header file HCheckBox( a HWidget)
* COPYRIGHT: Hisoft
* Created on: $(8.19.2011) Author: Geng,XuanXuan
***********************************************************************/

#ifndef _HCHECKBOX_H
#define _HCHECKBOX_H

#include "hwidget.h"
#include "himage.h"

#define CHECKBOX_MAX_LEN 30				 /* max length of checkbox label text */

typedef struct _HCheckBox HCheckBox;		/* define checkbox type */


typedef struct _HCheckBox {
	HWidget base;		/* Base class */

	char c_check_state;		/* State of HCheckBox */

	short s_space;		/* space between check state and text */

	HImage *p_image;	/*framw index: 
							1: has focus and not checked
							2: has focus and checked
							3: has no focus and not checked
							4: has no focus and checked
						*/

	VMWCHAR awc_label[CHECKBOX_MAX_LEN + 1];	/* Label in HCheckBox */
	
} HCheckBox;

/*
 Function Name: hcheckbox_new
 Description: Get a New HCheckBox
 Para(in) pc_label: Label in HCheckBox
 Return: A pointer of HCheckBox
*/
HCheckBox* hcheckbox_new(char* pc_label);

/*
 Function Name: hcheckbox_destroy
 Description: Destroy a HCheckBox
 Para(in) p_checkbox: A pointer of HCheckBox
*/
void hcheckbox_delete(HCheckBox *p_checkbox);

/*
 Function Name: hcheckbox_ops_delete
 Description: delete HCheckBox global operations
*/

/*
Function Name: hcheckbox_init
Description: init a checkbox that has already assign memory
Para(in) p_checkbox: A pointer of HCheckBox
Para(in) pc_label: label text of checkbox
*/
void hcheckbox_init(HCheckBox *p_checkbox, char *pc_label);

/*
Function Name: hcheckbox_init
Description: clean checkbox label
Para(in) p_checkbox: A pointer of HCheckBox
*/
void hcheckbox_clean(HCheckBox *p_checkbox);


/* 
Function Name: set_label
Description: Callback function that set label in HCheckBox
Para(in) p_checkbox: Pointer of HCheckBox self
Para(in) pc_label: Label of HCheckBox
*/
void hcheckbox_set_label(HCheckBox *p_checkbox, char *pc_label);

/* set ucs2 string to label */
void hcheckbox_set_ucs2_label(HCheckBox *p_checkbox, VMWCHAR *pwc_label);

/* set checkbox check state image */
void hcheckbox_set_image(HCheckBox *p_checkbox, HImage *p_image);

/* set space between check state and label */
void hcheckbox_set_space(HCheckBox *p_checkbox, int i_space);

/*
Function Name: set_check_state
Description: Callback function that set check state to HCheckBox
Para(in) p_checkbox: Pointer of HCheckBox self
Para(in) c_check_state: check state of HCheckBox
HCHECKBOX_SELECTED,			Selected state of HCheckBox
HCHECKBOX_UNSELECTED,		UnSelected state of HCheckBox
*/
void hcheckbox_set_check_state(HCheckBox *p_checkbox, int i_check_state);

/*
Function Name: get_check_state
Description: Callback function that get check state of the HCheckBox
Para(in) p_checkbox: Pointer of HCheckBox self
Return: Check state of the HCheckBox
*/
int hcheckbox_get_check_state(HCheckBox *p_checkbox);

#endif
/********************************EOF***********************************/