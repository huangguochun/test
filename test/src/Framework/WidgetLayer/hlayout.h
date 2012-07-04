/*---------------------------------
 * FILE Name: hlayout.h
 *
 * Description: This file describes the parrent class definition of layout manager
 *
 * COPYRIGHT
 *
 * Created on: 2011.8.31 Author: Pian,HaiSheng
 *
 * Modified by name on $(date)
 *---------------------------------------------------------------------*/
#ifndef HLAYOUT_H
#define HLAYOUT_H

#define  LAYOUT_BENCHMARK_ERROR -1
#define WIDGET_STATE_HIDE 0


/*****************INCLUDE FILES*************************/
#include "hwidget.h"
#include "../Common/array.h"

typedef struct _HLayout HLayout;

/* disable deprecation */
#ifndef _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#endif


/*auto free the layout memory*/
#define LAYOUT_ATTR_AUTO_FREE		1
/*auto reset the layout*/
#define LAYOUT_ATTR_AUTO_RESET		2
/*horizontal layout*/
#define LAYOUT_ATTR_HOR				4
/*vertical layout*/
#define LAYOUT_ATTR_VER				8
/*whether is single line mode*/
#define LAYOUT_ATTR_SINGLE_LINE		16

#define HLAYOUT_GET_ATTR(p_layout, name) ((p_layout)->s_attr & name)
#define HLAYOUT_SET_ATTR(p_layout, name) ((p_layout)->s_attr |= name)
#define HLAYOUT_CLEAR_ATTR(p_layout, name) ((p_layout)->s_attr &= ~name)


/* HLayout type declaration */
struct _HLayout
{
	/* max width and height for putting widget area */
	short s_max_width;
	short s_max_height;
	short s_attr;

	/* gap between widgets */
	short s_gap_x;
	short s_gap_y;

	/* list to save all the added widgets */
	Array elems;

	struct _HContainer *p_owner;

	/* save benchmark position*/
	short s_benchmark_x;
	short s_benchmark_y;
};

/************************************************************************
* init a layout
************************************************************************/
void hlayout_init(HLayout* p_layout);

/************************************************************************
* set the layout's attributes
* @param i_attr: eg LAYOUT_ATTR_HOR and so on
************************************************************************/
void hlayout_set_attr(HLayout* p_layout, int i_attr);


/************************************************************************
* delete a layout
* Note: 
*		The layout will be not be free memory,
*			when it has no LAYOUT_ATTR_AUTO_FREE attribute
************************************************************************/
void hlayout_delete(HLayout* p_layout);

/************************************************************************
* 
************************************************************************/
void hlayout_add_widget(HLayout* p_layout, HWidget* p_widget);

/************************************************************************
* remove widget from the layout
************************************************************************/
void hlayout_remove_widget(HLayout* p_layout, HWidget* p_widget);

/************************************************************************
* clear all widget which is in the layout
************************************************************************/
void hlayout_clear(HLayout* p_layout);


/************************************************************************
* set gap for the layout
************************************************************************/
void hlayout_set_gap(HLayout* p_layout, short s_gap_x, short s_gap_y);

/************************************************************************
* validate the layout, it will calculate all widget's position
************************************************************************/
void hlayout_validate(HLayout *p_layout, HRect *p_result);

#endif

 /*********************EOF******************************/