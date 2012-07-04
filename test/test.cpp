/* ============================================================================
 * VRE demonstration application.
 *
 * Copyright (c) 2006-2009 Vogins Network Technology (China). All rights 
 * reserved.
 *
 * YOU MAY MODIFY OR DISTRIBUTE SOURCE CODE BELOW FOR PERSONAL OR 
 * COMMERCIAL PURPOSE UNDER THOSE AGGREMENTS:
 *
 * 1) VOGINS COPYRIGHT MUST BE KEPT IN REDISTRIBUTED SOURCE CODE OR
 *    BINARY FILE.
 * 2) YOU CAN REUSE THOSE SOURCE CODE IN COMMERCIAL PURPOSE WITHOUT
 *    VOGINS COMFIRMATION.
 * 3) THIS PROGRAM JUST USE TO DEMONSTRATE HOW TO WRITE A VRE BASED
 *    APPLICATION. VOGINS WON'T MAKE ANY GUARANTEE THAT IT COULD BE
 *    USED IN PRODUCTION ENVIRONMENT.
 * ========================================================================= */

/*============================================================================
 * GDI Sample show the VRE usage of GDI interface
 *
 * Copyright (c) 2006 - 2009 Vogins Network Technology (China). All rights reserved.
 * By Steven Fang Feb. 1, 2009 V1.0
 *============================================================================*/

#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "ResID.h"


/* ---------------------------------------------------------------------------
 * global variables
 * ------------------------------------------------------------------------ */

#define		SUPPORT_BG


VMINT		layer_hdl[1];				////layer handle array.

/* ---------------------------------------------------------------------------
 * local variables
 * ------------------------------------------------------------------------ */
/*
 * system events
 */
void handle_sysevt(VMINT message, VMINT param);

/*
 * key events
 */
void handle_keyevt(VMINT event, VMINT keycode);

/*
 * pen events
 */
void handle_penevt(VMINT event, VMINT x, VMINT y);

/*
 * demo
 */
static void draw_hello(void);

/**
 * entry
 */
void vm_main(void) {
	layer_hdl[0] = -1;

	vm_reg_sysevt_callback(handle_sysevt);
	vm_reg_keyboard_callback(handle_keyevt);
	vm_reg_pen_callback(handle_penevt);
}

void handle_sysevt(VMINT message, VMINT param) {
#ifdef		SUPPORT_BG	
	/* The application updates the screen when receiving the message VM_MSG_PAINT 
	*  what is sent after the application is activated. The application can skip 
	*  the process on screen when the VM_MSG_ACTIVE or VM_MSG_INACTIVE is received.
	*/
	switch (message) {
		case VM_MSG_CREATE:
			/* the GDI operation is not recommended as the response of the message*/
			break;
		case VM_MSG_PAINT:
			/* cerate base layer that has same size as the screen*/
			layer_hdl[0] = vm_graphic_create_layer(0, 0, 
				vm_graphic_get_screen_width(), 
				vm_graphic_get_screen_height(), -1);	
			
			/* set clip area */
			vm_graphic_set_clip(0, 0, 
				vm_graphic_get_screen_width(), 
				vm_graphic_get_screen_height());

			draw_hello();
			break;
		case VM_MSG_HIDE:
		case VM_MSG_QUIT:
			if( layer_hdl[0] != -1 )
			{
				vm_graphic_delete_layer(layer_hdl[0]);
				layer_hdl[0] = -1;
			}

			break;
	}
#else
	switch (message) {
		case VM_MSG_CREATE:
		case VM_MSG_ACTIVE:
			/*cerate base layer that has same size as the screen*/
			layer_hdl[0] = vm_graphic_create_layer(0, 0, 
				vm_graphic_get_screen_width(), 
				vm_graphic_get_screen_height(), -1);	
			
			/* set clip area*/
			vm_graphic_set_clip(0, 0, 
				vm_graphic_get_screen_width(), 
				vm_graphic_get_screen_height());
			break;

		case VM_MSG_PAINT:
			draw_hello();
			break;

		case VM_MSG_INACTIVE:
		case VM_MSG_QUIT:
			if( layer_hdl[0] != -1 )
				vm_graphic_delete_layer(layer_hdl[0]);

			break;	
	}
#endif
}

void handle_keyevt(VMINT event, VMINT keycode) {
	/* press any key and return*/
	if( layer_hdl[0] != -1 )
	{
		vm_graphic_delete_layer(layer_hdl[0]);
		layer_hdl[0] = -1;
	}

	vm_exit_app();
}

void handle_penevt(VMINT event, VMINT x, VMINT y)
{
	/* touch and return*/
	if( layer_hdl[0] != -1 )
	{
		vm_graphic_delete_layer(layer_hdl[0]);
		layer_hdl[0] = -1;
	}

	vm_exit_app();
}


static void draw_hello(void) {
	VMWCHAR s[50];
	VMUINT8* buf;	
	int x, y, w;
	
	vm_gb2312_to_ucs2(s, 50, "Hello, world!");
	w = vm_graphic_get_string_width(s);
	x = (vm_graphic_get_screen_width() - w) / 2;
	y = (vm_graphic_get_screen_height() - vm_graphic_get_character_height()) / 2;
	
	/* get the target buffer*/
	buf = vm_graphic_get_layer_buffer(layer_hdl[0]);		
	
	/* fill the screen*/
	vm_graphic_fill_rect(buf, 0, 0, vm_graphic_get_screen_width(), 
		vm_graphic_get_screen_height(), VM_COLOR_WHITE, VM_COLOR_BLACK);
	
	/* draw text */
	vm_graphic_textout(buf,	x, y, s, wstrlen(s), VM_COLOR_BLUE);
	
	/* flush the screen with data in the buffer*/
	vm_graphic_flush_layer(layer_hdl, 1);
}

