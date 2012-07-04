#ifndef ADV_BORDER_H
#define ADV_BORDER_H

#include "hwidget.h"

enum {
	ADV_BORDER_SOURCE_ID1,
	ADV_BORDER_SOURCE_ID2,
	ADV_BORDER_SOURCE_ID3,
	ADV_BORDER_SOURCE_ID4,
	ADV_BORDER_SOURCE_ID5,
	ADV_BORDER_SOURCE_ID6,
	ADV_BORDER_SOURCE_ID7,
	ADV_BORDER_SOURCE_ID8,
	ADV_BORDER_SOURCE_ID9,
	ADV_BORDER_SOURCE_NUM = 10
};

enum {
	BRUSH_ATTR_COPY,
	BRUSH_ATTR_DRAW
};

typedef struct _HBrush {
	short s_attr;
	short s_width;			//the brush width
	short s_height;			//the brush height
	short s_trans_color;	//transparent color
	unsigned short *p_buf;	//the brush buffer
} HBrush;

typedef struct _HAdvBorder {
	short s_attr;
	short c_source_id;
	short c_hover_source_id;
	HBrush brash;
	HBrush hover_brash;
} HAdvBorder;

void hadvborder_init(HAdvBorder *p_adv);

void hadvborder_init_resource(void);

void hadvborder_paint(HAdvBorder *p_border, struct _HWidget *p_owner, struct _HGraphic *p_gra);


#endif