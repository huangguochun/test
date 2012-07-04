/********************************************************
*file: hwindow.h
*author: yan.gao
*date: 2011.08.22
*description: Globally unique object in our app.
********************************************************/

#ifndef  _HWINDOW_H_
#define  _HWINDOW_H_

#include "../WidgetLayer/hplane.h"
#include "../PageLayer/page.h"
#include "vmsys.h"

typedef struct _HWindow HWindow;

/*global window instance*/
extern HWindow *window;

void hwindow_init(void);

void hwindow_exit(void);

struct _HWindow {

	/******************* private member **********************/

	/*By default, in a window has three planes. We define these names: Default plane, Popup menu plane, and Glass plane*/
	struct _HPlane *p_planes[3];

	void (*sys_event_handle)(VMINT message, VMINT param);

	void (*key_event_handle)(VMINT evt, VMINT keycode);

	 void (*pen_event_handle)(VMINT evt, VMINT x, VMINT y);
	/******************* public member **********************/

	 /************************************************************************
	 * Function: inner_event_receiver
	 * Description: framework inner event receiver
	 ************************************************************************/
	 void (*inner_event_receiver)(HWidget *p_source, InnerEvent ie);


	/************************************************************************
	* Function: get_default_plane
	* Description: get the default plane. It real is planes[0]
	************************************************************************/
	struct _HPlane * (*get_default_plane)();

	/************************************************************************
	* Function: get_popupmenu_plane
	* Description: get the popup menu plane. It real is planes[1]
	************************************************************************/
	struct _HPlane * (*get_popupmenu_plane)();

	/************************************************************************
	* Function: get_glass_plane
	* Description: get the glass plane. It real is planes[2]
	************************************************************************/
	struct _HPlane * (*get_glass_plane)();

	/************************************************************************
	* validate the window's all planes
	************************************************************************/
	void (*validate)();

	/*repaint all planes*/
	void (*repaint)();

	/************************************************************************
	* app deal the system event
	* @return 0 or 1,  1:means app deal the event, otherwise app is not deal
	************************************************************************/
	int (*app_sys_event_handle)(VMINT message, VMINT param);

	/************************************************************************
	* the screen width 
	************************************************************************/
	short s_screen_width;

	/************************************************************************
	* the screen height 
	************************************************************************/
	short s_screen_height;

	/************************************************************************
	* the device is support touch screen, yes:1 no:0
	************************************************************************/
	short s_is_support_touch_screen;

	/************************************************************************
	* whether support BG mode
	************************************************************************/
	short s_is_support_bg_mode;

	//we define default min virtual scroll dy is 45
	short s_min_virtual_scroll_dy;

	//pen is moving yes:1 no:0
	short s_pen_is_moving;

	//yes: QQVGA, QQVGA_LS, QCIF, QCIF_LS, no:HVGA, QVGA, WQVGA, WVGA
	short s_is_small_handset;

	short s_is_in_input_method;

	short s_need_repaint;

	int i_id;

};

#endif