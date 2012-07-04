/*********************************
*file: hscrollbar.h
*author: yan.gao
*date: 2011.09.13
***********************************/

#ifndef _HSCROLLBAR_H
#define _HSCROLLBAR_H

#include "hwidget.h"

typedef struct _HScrollBar HScrollBar;

enum {
	ORIENTATION_H,
	ORIENTATION_V
};

struct _HScrollBar {
	HWidget base;
	int i_timer_id;
	int i_tick;
	short s_orientation;
	short s_block_size;

	int i_bar_offset;
	int i_rang;
	void (*scroll)(HScrollBar *p_bar, short s_distance);
};

HScrollBar *hscrollbar_new(int i_orientation);

void hscrollbar_delete(HScrollBar *p_bar);


#endif