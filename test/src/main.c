/*
 * entry
 */
#include "vmtimer.h"
#include "vmres.h"

#include "htooltip.h"

#include "globals.h"
#include "parse.h"
#include "http_wrapper.h"
#include "switch_helper.h"
#include "draw_frame.h"
#include "pos.h"
#include "resources.h"
#include "framework_wrapper.h"
#include "cache.h"
static void resolution_timer(int timer_id)
{
	hwindow_exit();
}
static int is_support_png()
{
	VMINT hcanvas1 = 0;
	VMUINT8 *img_data1;
	VMINT size1;
	img_data1 = vm_load_resource("switch_to.png", &size1);
	hcanvas1 = vm_graphic_load_image(img_data1,size1);
	if(hcanvas1 < 0)
	{
		vm_free(img_data1);
		return 0;
	}
	vm_graphic_release_canvas(hcanvas1);
	vm_free(img_data1);
	return 1;
}

void app_main(void)
{
	HWidget widget;
	HEvent e;


	/* init static widget */
	if(! is_support_png())
	{
		htooltip_show("PLATFORM DECODE FAILED", TOOLTIP_TIME*2);
		vm_create_timer_ex(TOOLTIP_TIME, resolution_timer);
		return ;
	}

	if(VERSION_WIDTH == window->s_screen_width && VERSION_HEIGHT == window->s_screen_height)
	{
		/* init widget, menu_bar image, loading image */
		ui_init_static_widget();
		init_menubar();
		init_lm_s();
		cache_init();
		g_auto_refresh_time = read_config();

		window->get_default_plane()->key_event_filter = key_filter;

		e.i_event_type = HPEN_EVENT_RELEASE;
		g_current_view = -1;
		widget.pv_user_data = (void *)(live_matches_view);
		switch_view(&widget, &e, NULL);
	}
	else
	{
		htooltip_show("Resolution not Support", TOOLTIP_TIME*2);
		vm_create_timer_ex(TOOLTIP_TIME, resolution_timer);
	}


	return;
}

void app_init()
{
	/* TODO: support background run */
}
void app_exit()
{
	/* TODO: support background run */
}


