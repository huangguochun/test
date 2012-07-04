/****************************************************************
* FILE Name: hexpressionlst.h
* Description: popuo a expression list, select 
* COPYRIGHT: Hisoft
* Created on: $(10.12.2011) Author: Geng,XuanXuan
****************************************************************/

#ifndef _HEXPRESSIONLST_H
#define _HEXPRESSIONLST_H

#include "hcontainer.h"
#include "himage.h"

typedef struct _HExpressionLst HExpressionLst;		/* define HExpressionlst type */
typedef struct _HExpressionLstOperation HExpressionLstOperation;	/* define HExpressionlst Operations type */

struct _HExpressionLst{
	HContainer base;				/* base class */

	unsigned char uc_row_count;        /* expression images' rows count */

	unsigned char uc_column_count;		/* expression images' columns count */

	short s_lst_width;				/* expression list width */

	short s_lst_height;				/* expression list height */

	short s_index;					/* selected index */

	short s_max_count;     /* max number of expression images */

	HImage *p_mask_img;				/* mask image of expression */

	HImage *p_close_img;			/* close button image */

	HExpressionLstOperation *p_expresslst_ops;	/* HExpressionlst operations */
};

struct _HExpressionLstOperation {
	/* 
	Function Name: set_lst_count
	Description: set expression list row and column count
	Para(in) p_expresslst: Pointer of HExpression self
	Para(in) i_row_count: expression images' rows count
	Para(in) i_col_count: expression images' columns count
	*/
	void (*set_lst_count)(HExpressionLst *p_expresslst, int i_row_count, int i_col_count);

	/* 
	Function Name: set_lst_max_count
	Description: set expression list max images count
	Para(in) p_expresslst: Pointer of HExpression self
	Para(in) i_max_count: max expression images count
	*/
	void (*set_lst_max_count)(HExpressionLst *p_expresslst, int i_max_count);

	/* 
	Function Name: set_lst_size
	Description: set expression list width and height
	Para(in) p_expresslst: Pointer of HExpression self
	Para(in) i_width: expressionlst image area width
	Para(in) i_height: expressionlst image area height
	*/
	void (*set_lst_size)(HExpressionLst *p_expresslst, int i_width, int i_height);

	/* 
	Function Name: set_lst_padding
	Description: set expression list padding, using padding instead of border.
	Para(in) p_expresslst: Pointer of HExpression self
	Para(in) i_left: padding left
	Para(in) i_right: padding right
	Para(in) i_top: padding top
	Para(in) i_bottom: padding bottom
	*/
	void (*set_lst_padding)(HExpressionLst *p_expresslst, int i_left, int i_right, int i_top, int i_bottom);

	/* 
	Function Name: set_lst_share_img
	Description: set expression list expression image
	Para(in) p_expresslst: Pointer of HExpression self
	Para(in) p_img: pointer of background image
	*/
	void (*set_lst_share_img)(HExpressionLst *p_expresslst, HImage *p_img);

	/* 
	Function Name: set_mask_share_img
	Description: set expression list expression mask image
	Para(in) p_expresslst: Pointer of HExpression self
	Para(in) p_img: pointer of expression mask image
	*/
	void (*set_mask_share_img)(HExpressionLst *p_expresslst, HImage *p_img);

	/* 
	Function Name: show
	Description: show expression list
	Para(in) p_expresslst: Pointer of HExpression self
	*/
	void (*show)(HExpressionLst *p_expresslst);

	/* 
	Function Name: hide
	Description: hide expression list
	Para(in) p_expresslst: Pointer of HExpression self
	*/
	void (*hide)(HExpressionLst *p_expresslst);
};

/* 
Function Name: hexpressionlst_new
Description: create a new HExpressionLst
Return: pointer of HExpressionlst
*/
extern HExpressionLst * hexpressionlst_new(void);

/* 
Function Name: hexpressionlst_delete
Description: delete a new HExpressionLst
Para(in): pointer of HExpressionlst
*/
extern void hexpressionlst_delete(HExpressionLst *p_expresslst);

/* this function will be delete */
extern void hexpressionlst_ops_delete(void);

/* 
Function Name: hexpressionlst_init
Description: init HExpressionlst that already assign memory
Para(in): pointer of HExpressionlst
*/
extern void hexpressionlst_init(HExpressionLst *p_expresslst);

/* 
Function Name: hexpressionlst_init
Description: clean hexpressionlst
Para(in): pointer of HExpressionlst
*/
extern void hexpressionlst_clean(HExpressionLst *p_expresslst);

#endif

/************************EOF************************/