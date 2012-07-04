/*********************************
*file: hcontainer.h
*author: yan.gao
*date: 2011.08.22
*description: a container
***********************************/

#ifndef _HCONTAINER_H_
#define _HCONTAINER_H_

#include "hwidget.h"
#include "himage.h"
#include "HLayout.h"
#include "../Common/vector.h"
#include "../Common/array.h"
#include "hscrollbar.h"

typedef struct _HContainer HContainer;
typedef struct _HContainerOperation HContainerOperation;

/************************************************************************
* Function: hcontainer_new                                                              
* Description: create a new HContainer
************************************************************************/
HContainer * hcontainer_new(void);

/************************************************************************
* Function: hcontainer_delete                                                              
* Description: destroy a  HContainer
* Para(in) p_container : it is a HContainer
************************************************************************/
void hcontainer_delete(HContainer *p_container);

/************************************************************************
* clean the container's all content, and reset it to original state
************************************************************************/
void hcontainer_clean(HContainer *p_container);

/************************************************************************
* Function: hcontainer_init                                                            
* Description: init a  HContainer
************************************************************************/
void hcontainer_init(HContainer *p_container);


/************************************************************************
* Function : hcontainer_operation_init                                                             
* Description : init the container operation
************************************************************************/
void hcontainer_operation_init(HContainerOperation *p_container_ops);

void hcontainer_ops_delete(void);

HContainer *find_scroll_effect(HWidget *p_from);

struct _HContainer {

	/*********************** private member ***************************/
	
	HWidget base;

	/*virtual scroll dy*/
	short s_virtual_dy;

	/*a translate coordinate of x*/
	short s_translate_x;

	/*a translate coordinate of y*/
	short s_translate_y;

	/* children widgets */
	Array *p_children;

	Array _children;

	/*background image*/
	HImage *p_bgimg;

	/*the container's layout*/
	HLayout *p_layout;

	HScrollBar *p_vbar;

	/********************** public member *************************/
	
	/*container operations*/
	HContainerOperation *p_container_ops;

};

struct _HContainerOperation {
	HWidgetOperation base;

	/************************************************************************
	* Paint the container itself, default it is NULL
	************************************************************************/
	void (*paint_container)(HContainer *p_container, HGraphic *p_graphic);
};

/************************************************************************
* Function : add_widget
* Description: add a widget to a container   
* Para(in) p_container :
* Para(in) p_widget : the will added widget
************************************************************************/
void hcontainer_add_widget(HContainer *p_container, HWidget *p_widget);


/************************************************************************
* Function : remove_widget
* Description:  remove a widget from a container,and free the widget memory
* Para(in) p_container :
* Para(in) p_widget : the will removed widget
************************************************************************/
void hcontainer_remove_widget(HContainer *p_container, HWidget *p_widget);


/************************************************************************
* Function: remove_all
* Description: remove all widget in the container, and free its children widgets memory
* Para(in) p_container : the needed clear container 
************************************************************************/
void hcontainer_remove_all(HContainer *p_container);


/************************************************************************
* Function: scroll
* Description :  scroll the container
* Para(in) s_dx : horizontal scroll value
* Para(in) s_dy : vertical scroll value
************************************************************************/
void hcontainer_scroll(HContainer *p_container, short s_dx, short s_dy);

/************************************************************************
* whether the container can be scroll, return yes(1), or no(0)
************************************************************************/
int hcontainer_can_scroll(HContainer *p_container);

/************************************************************************
* set the container's background image
************************************************************************/
void hcontainer_set_bgimg(HContainer *p_container, HImage *p_img);

/************************************************************************
* set the container's layout
************************************************************************/
void hcontainer_set_layout(HContainer *p_container, HLayout *p_layout);

/************************************************************************
* paint function
************************************************************************/
void hcontainer_paint(HWidget *p_widget, HGraphic *p_graphic);

#define C(p) ((HContainer *)p)

#endif