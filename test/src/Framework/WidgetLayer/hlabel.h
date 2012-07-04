/****************************************************************
* FILE Name: hlabel.h
* Description: a text widget, show multi text to view
* COPYRIGHT: 
* Created on: $(12.14.2011) Author: Geng,XuanXuan
****************************************************************/
#ifndef				_HLABEL_H
#define				_HLABEL_H

#include "hwidget.h"
#include "himage.h"

#include "../Common/array.h"
#include "../Common/vector.h"

typedef struct _HLabel HLabel;


struct _HLabel {
	HWidget base;

	char c_line_space;		/* space between two lines */
	VMWCHAR *pwc_text;
	int i_words_len;		/*the length of pwc_text*/
	Array lines;			/* lines node array */
};

/* create a new label, the para is default string */
HLabel *hlabel_new(char *pc_str);

/* init a exist label */
void hlabel_init(HLabel *p_this);

/* clean text of label */
void hlabel_clean(HLabel *p_this);

/* delete label, release memory by attr flag */
void hlabel_delete(HLabel *p_this);

/* set char * string to label */
void hlabel_set_text(HLabel *p_this, char *pc_text);

/* set unicode string to label */
void hlabel_set_ucs2_text(HLabel *p_this, VMWCHAR *pwc_ucs2);

/* set line space value */
void hlabel_set_line_space(HLabel *p_this, int i_space);


#endif



/******************************* EOF ***********************************/