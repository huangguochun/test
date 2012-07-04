/**********************************************************************************
*file: hlookandfeel.h
*author: yi.jiang
*date: 2011.08.29
*description: draw specific widget into specify layer by getting widget structure.
***********************************************************************************/


#ifndef _HDRAW_H_
#define _HDRAW_H_

#include <string.h>
#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmlog.h"

#include "hplane.h"
#include "hwidget.h"
#include "htextinput.h"
#include "htextarea.h"
#include "hlabel.h"
#include "hcheckbox.h"
#include "hprocessbar.h"
#include "htooltip.h"
#include "himage.h"
#include "hbutton.h"
#include "../WindowLayer/hwindow.h"

#define	TEXTINPUT_DEFAULT_TEXT_COLOR	0x8410
#define	PLANE_BLACK_TRANS	100

void look_paint_plane(HPlane* p_plane);

void look_paint_textinput(HTextInput *p_textinput, HGraphic *p_graphic);

void look_paint_textarea(HTextArea *p_textarea, HGraphic *p_graphic);

void look_paint_tooltip(HToolTip *p_tooltip, HGraphic *p_graphic);

void look_paint_processbar(HProcessBar *p_pb, HGraphic *p_graphic);

void look_paint_button(HButton *p_button, HGraphic *p_graphic);

void look_paint_label(HLabel *p_label, HGraphic *p_graphic);

void look_paint_checkbox(HCheckBox *p_checkbox, HGraphic *p_graphic);

void look_set_plane_trans(int i_trans);

void look_set_clip(HRect *p_clip_rect);

void look_paint_hover_image(HWidget *p_widget, HImage *p_image, HGraphic *p_graphic);

void look_paint_widget_style(HWidget *p_widget, struct _HGraphic *p_graphic);

void look_paint_multi_text(Array *p_node_array, HGraphic *p_graphic, short s_space, int i_color);

void look_set_widget_content_cilp(HWidget *p_widget, HGraphic *p_graphic);

void look_paint_scrollbar(HContainer *p_cnt, HGraphic *p_graphic);

void look_paint_scroll_effect(HContainer *p_cnt, HGraphic *p_graphic);


#endif
