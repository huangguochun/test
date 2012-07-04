/********************************************************
*file: hplane.h
*author: yan.gao
*date: 2011.08.22
*description: a plane, the root container
********************************************************/

#ifndef _HPLANE_H_
#define  _HPLANE_H_

#include "hwidget.h"
#include "hcontainer.h"
#include "../Common/hashtable.h"

typedef struct _HPlane HPlane;
typedef struct _KeyFocusNode KeyFocusNode;

/*new a HPlane*/
HPlane * hplane_new(void);

void hplane_delete(HPlane *p_plane);


struct _HPlane {

	/********************** private member *************************/

	/*base class*/
	HContainer base;
	
	short s_event_lock;

	/* the top widget of the plane */
	HWidget *p_top_widget;

	/* the bottom widget of the plane*/
	HWidget *p_bottom_widget;
	
	/* the content container of the plane*/
	HContainer *p_content;

	/* MRE paint handle */
	int i_handle;

	/*enable/disable transparent the plane's background*/
	short i_enable_transparent_bg;

	/*the plane's layer trans color*/
	short s_transparent_color;

	/*the index in  window*/
	short s_plane_index;

	/*store all enable focus widget at this plane, it is used for direction key, to find next widget*/
	HashTable *p_table;

	/*the cur own focus widget*/
	HWidget *p_own_focus_widget;

	KeyFocusNode *p_key_down_head;

	KeyFocusNode *p_key_right_head;

	
	/********************** public member **************************/

	/************************************************************************
	* key event filter
	* @i_evt is the key event type. ex: HKEY_EVENT_DOWN and so on
	* @i_keycode
	* @return 1: means has handled this event; 0: means has no handled,then the framework will process this event
	************************************************************************/
	int (*key_event_filter)(int i_evt, int i_keycode);

	int (*pen_event_filter)(int i_evt, int i_x, int i_y);
};

/************************************************************************
* add widget to plane's content container
************************************************************************/
void hplane_add_widget(HPlane *p_plane, HWidget *p_widget);

/************************************************************************
* remove widget from plane's content container
************************************************************************/
void hplane_remove_widget(HPlane *p_plane, HWidget *p_widget);

/************************************************************************
* remove all widget from plane's content container, and free there's memory
************************************************************************/
void hplane_remove_all(HPlane *p_plane);

/************************************************************************
* Function: set_top_widget
* Description: set the top widget of the plane
************************************************************************/
void hplane_set_top_widget(HPlane *p_plane, HWidget *p_widget);

/************************************************************************
* Function: set_top_widget
* Description: set the bottom widget of the plane
************************************************************************/
void hplane_set_bottom_widget(HPlane *p_plane, HWidget *p_widget);

/************************************************************************
* when user press down key, figure the focus how to change
************************************************************************/
void hplane_add_key_down(HPlane *p_plane, HWidget *p_from_widget, HWidget *p_to_widget);

/************************************************************************
* when user press right key, figure the focus how to change
************************************************************************/
void hplane_add_key_right(HPlane *p_plane, HWidget *p_from_widget, HWidget *p_to_widget);

/************************************************************************
* clean HPlane's p_key_down_head and p_key_right_head list
************************************************************************/
void hplane_clean_key_list(HPlane *p_plane);

/************************************************************************
* set the plane's current own focus widget, p_widget can be null
************************************************************************/
void hplane_set_own_focus_widget(HPlane *p_plane, HWidget *p_widget);

void hplane_add_to_hashtable(HPlane *p_plane, HWidget *p_widget);

void hplane_remove_from_hashtable(HPlane *p_plane, HWidget *p_widget);

/************************************************************************
* lock or unlock all event(pen/key event), it is a recursive lock
* @param i_locked , it only can be 1(lock event) or 0 (unlock event)
************************************************************************/
void hplane_lock_event(HPlane *p_plane, int i_locked);

/************************************************************************
* try inertia scroll
************************************************************************/
void try_inertia_scroll(HPlane *p_plane, HWidget *p_from);

struct _KeyFocusNode {
	HWidget *p_from_widget;
	HWidget *p_to_widget;
	KeyFocusNode *p_next;
};

#endif