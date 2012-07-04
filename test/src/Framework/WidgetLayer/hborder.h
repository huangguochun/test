#ifndef _HBORDER_H
#define _HBORDER_H

#include "hwidget.h"

#define BORDER_STYLE_TOP_LINE		(1 << 1)
#define BORDER_STYLE_BOTTOM_LINE	(1 << 2)
#define BORDER_STYLE_LEFT_LINE		(1 << 3)
#define BORDER_STYLE_RIGHT_LINE		(1 << 4)
#define BORDER_STYLE_RECT			(1 << 5)

#define BORDER_ATTR_AUTO_FREE		(1 << 1)
#define BORDER_ATTR_AUTO_RESET		(1 << 2)
#define BORDER_ATTR_ENABLE			(1 << 3)
#define BORDER_ATTR_ADV				(1 << 4)

#define  HBORDER_GET_ATTRIBUTE(p_border, name)	((p_border)->c_attr & (name))
#define  HBORDER_SET_ATTRIBUTE(p_border, name)	((p_border)->c_attr |= (name))
#define  HBORDER_CLEAR_ATTRIBUTE(p_border, name)	((p_border)->c_attr &= ~(name))


/* widget border  */
typedef struct _HBorder {
	short c_attr;				/*attributes, ex: BORDER_ATTR_AUTO_FREE and so on*/
	short c_style;				/*border style*/
	int i_color;				/*default color*/
	int i_hover_color;			/*the color at hover state*/
	short s_corner_width;		/*round conner width*/
	short s_border_width;		/*border width, default is 1 pix*/
} HBorder;

HBorder * hborder_new(void);

void hborder_init(HBorder *);

void hborder_delete(HBorder *p_border);

void hborder_paint(HBorder *p_this, struct _HWidget *p_owner, struct _HGraphic *p_graphic);


#endif

