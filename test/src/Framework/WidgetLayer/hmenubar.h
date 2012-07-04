/****************************************************************
* FILE Name: hmenubar.h
* COPYRIGHT: 
* Created on: $(2011.12.27) Author: Gao,Yan
****************************************************************/

#ifndef HMENUBAR_H
#define HMENUBAR_H

#include "hcontainer.h"
#include "hwidget.h"
#include "hbutton.h"

#define MENUBAR_ITEM_IMG "menubar.gif"
#define MENUBAR_LABEL_LEN 15

enum {
	MENUBAR_MODE_Y,	//is default
	MENUBAR_MODE_N
};

/************************************************************************
* Note: the menu bar's action performed only can get key events,
*			user can't get pen events
************************************************************************/

typedef struct _HMenuBar {
	HContainer base;
	HButton *p_btn_left;
	HButton *p_btn_right;
	int i_mode;//only can be MENUBAR_MODE_Y(default) or MENUBAR_MODE_N
	int i_space;
} HMenuBar;


/************************************************************************
* Get the unique instance of HMenuBar
************************************************************************/
HMenuBar *hmenubar_get_instance(void);

/************************************************************************
* Set the text for menu bar
* Note: if you have no left or right text, set to NULL
************************************************************************/
void hmenubar_set_text(char *p_left_text, char *p_right_text);

/************************************************************************
* Set ucs2 text for menu bar
* Note: if you have no left or right text, set to NULL
************************************************************************/
void hmenubar_set_ucs2_text(VMWCHAR *pwc_left_text, VMWCHAR *pwc_right_text);


void hmenubar_set_mode(int i_mode);

void hmenubar_set_middle_space(int i_space);

#endif