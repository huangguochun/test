/*********************************
*file: hwidget.h
*author: yan.gao
*date: 2011.08.19
*description:  base class widget
***********************************/
#ifndef _HWIDGET_H_
#define _HWIDGET_H_

#include "hplatform.h"
#include "../Common/vector.h"
#include "../Common/array.h"
#include "hborder.h"

#define H_DEBUG

/* disable deprecation */
#ifndef _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#endif

typedef struct _HWidget HWidget;
typedef struct _HWidgetOperation HWidgetOperation;


/*init HWidget*/
void hwidget_init(HWidget *p_widget);

/*init HWidget Operation*/
void hwidget_operation_init(HWidgetOperation *p_ops);


/* Font class*/
typedef enum _HFont{
	FONT_SMALL = 1,
	FONT_MEDIUM = 2,
	FONT_LAGER = 4,
	FONT_BOLD = 8,
	FONT_ITALIC = 16,
	FONT_UNDERLINE = 32
} HFont;

#define HFONT_GET_SIZE(c_font)	(((c_font) & 7) >> 1)
#define HFONT_GET_BOLD(c_font)	((c_font) & 8)
#define HFONT_GET_ITALIC(c_font)	((c_font) & 16)
#define HFONT_GET_UNDERLINE(c_font)	((c_font) & 32)

/*All event supper class */
typedef struct _HEvent{
	int i_event_type; // It's type define in platform.h    ex: HPEN_EVENT_MOVE
} HEvent;

typedef struct _HPenEvent{
	HEvent base;
	short s_x;
	short s_y;
} HPenEvent;

typedef struct _HKeyEvent{
	HEvent base;
	int i_keycode;
} HKeyEvent;

typedef struct _HFocusEvent {
	HEvent base;	  // it's base.i_event_type is HFOCUS_EVENT
	int i_gain_focus; // it value is 0 or 1, means lost or gain focus
} HFocusEvent;

typedef struct _HCancelEvent {
	HEvent base;	//it's base.i_event_type is HCLOSE_EVENT
} HCancelEvent;

typedef struct _HCloseEvent {
	HEvent base;	//it's base.i_event_type is HCANCEL_EVENT
} HCloseEvent;

typedef struct _HInputEvent {
	HEvent base;
	int i_input_type;	/* 0: call input method, 1: ok from input method, 2: cancel from input method */
} HInputEvent;

typedef struct _HScrollOverEvent {
	HEvent base;			/*HSCORLL_OVER_EVENT*/
	short s_direction;		/*1: scroll over top, 2:scroll over bottom*/
	short s_distance;		/*a container's virtual scroll real distance*/
} HScrollOverEvent;

/* Point class*/
typedef struct _HPoint {
	short s_x;
	short s_y;
} HPoint;

typedef struct _HRect {
	short s_x;
	short s_y;
	short s_width;
	short s_height;
} HRect;

typedef struct _HSize {
	short s_width;
	short s_height;
} HSize;

typedef enum _HClass {
	CLASS_WIDGET,			/*widget class*/
	CLASS_CONTAINER,		/*container class*/
	CLASS_LABEL,			/*label class*/
	CLASS_BUTTON,			/*button class*/
	CLASS_CHECKBOX,			/*check box class*/
	CLASS_POPUPMENU,		/*pop up menu class*/
	CLASS_PLANE,			/*plane class*/
	CLASS_TEXTINPUT,		/*text input class*/
	CLASS_TEXTAREA,			/*text area class*/
	CLASS_MENU_BAR,		/*status bar class*/
	CLASS_SCROLLBAR,		/*scrollbar class*/
	CLASS_PROCESSBAR,		/*process bar*/
	CLASS_TOOLTIP,			/* tooltip */
	CLASS_HTML_LABEL,		/*html label*/
	CLASS_EXPRESSION_LIST	/*expression list*/
} HClass;


typedef struct _HGraphic {
	int i_handle;
	VMUINT8 *p_buf;
	short s_screen_x;
	short s_screen_y;
	HRect clip;
} HGraphic;

typedef void (*ActionPerformed)(HWidget *, struct _HEvent *, void *);
typedef int (*KeyEventFilter)(int, int);
typedef int (*PenEventFilter)(int, int, int);

/*   class */
struct _HWidget {

	/*********************** private member*********************************/

	/*a attribute of flags ,visible, enable focus, has focus, enable bgcolor, enable drag and enable,opaque, hover */
	int i_attr;

	/*widget font, if c_font is 0, this means the widget's font inherits its parent*/
	char c_font;

	/*font size, only validate when support vector font */
	char c_font_size;

	/*foreground color*/
	int i_color;

	/*background color, default the bgcolor is not enable, you should call set_enable_bgcolor to enable it*/
	int i_bgcolor;

	int i_hover_color;

	int i_hover_bgcolor;

	struct _HBorder *p_border;

	/*padding left*/
	short s_padding_left;

	/*padding right*/
	short s_padding_right;

	/*padding top*/
	short s_padding_top;

	/*padding bottom*/
	short s_padding_bottom;

	/* The x coordinates relative to the parent container */
	short s_top_x;

	/* The y coordinates relative to the parent container */
	short s_top_y;

	/*the widget's real width*/
	short s_width;

	/*the widget's real height*/
	short s_height;

	/*the widget's preferred width*/
	short s_prefered_width;

	/*the widget's preferred height*/
	short s_prefered_height;

	/*the widget's max width*/
	short s_max_width;

	/*the widget's max height*/
	short s_max_height;

#ifdef H_DEBUG
	char *p_class_name;
#endif

	/*********************** public member *********************************/

	/*the widget's parent container*/
	struct _HContainer *p_parent;

	/*operation*/
	HWidgetOperation *p_widget_ops;

	/*user data*/
	void *pv_user_data;

	/*event action performed callback*/
	void (*action_performed)(HWidget *p_source, HEvent *p_evt, void *p_param);
};

/* Base widget operation*/
struct _HWidgetOperation {
	/*get the widget width*/
	short (*get_width)(HWidget *p_widget);

	/*get the widget height*/
	short (*get_height)(HWidget *p_widget);

	/*[pure abstract function] get the widget preferred width*/
	short (*get_prefered_width)(HWidget *p_widget);

	/*[pure abstract function]get the widget preferred height*/
	short (*get_prefered_height)(HWidget *p_widget);

	/*get the widget max width*/
	short (*get_max_width)(HWidget *p_widget);

	/*get the widget max height*/
	short (*get_max_height)(HWidget *p_widget);

	/*[pure abstract function] paint the widget*/
	void (*paint)(HWidget *p_widget, HGraphic *p_graphic);

	/*only repaint the widget itself*/
	void (*repaint)(HWidget *p_widget);
 
	/*validate the widget preferred size, size , and max size*/
	void (*validate)(HWidget *p_widget);

	/*invalidate the widget preferred size, size , and max size*/
	void (*invalidate)(HWidget *p_widget);

	/*[abstract function] pen press event callback*/
	void (*pen_press)(HWidget *p_widget, short s_x, short s_y);

	/*[abstract function] pen release event callback*/
	void (*pen_release)(HWidget *p_widget, short s_x, short s_y);

	/*[abstract function] pen move event callback*/
	void (*pen_move)(HWidget *p_widget, short s_x, short s_y);

	/*[abstract function] pen double click callback*/
	void (*pen_double_click)(HWidget *p_widget, short s_x, short s_y);

	/*[abstract function] pen long tap callback*/
	void (*pen_long_tap)(HWidget *p_widget, short s_x, short s_y);

	/*the focus has changed to another widget or this widget. i_gain_focus is 0 means the widget lost focus, 1 means gain focus*/
	void (*focus_changed)(HWidget *p_widget, int i_gain_focus);

	/*[abstract function] keyboard press event callback.*/
	void (*key_press)(HWidget *p_widget, int keycode);

	/*[abstract function] keyboard release event callback.*/
	void (*key_release)(HWidget *p_widget, int keycode);

	/*[abstract function] keyboard repeat event callback.*/
	void (*key_repeat)(HWidget *p_widget, int keycode);

	/*[abstract function] keyboard long press event callback.*/
	void (*key_long_press)(HWidget *p_widget, int keycode);

	/*[abstract function] get the widget class info*/
	HClass (*get_class)(HWidget *p_widget);

	/*[abstract function] whether the direction key can travel in the widget. if not , focus will goto next widget*/
	int (*can_travel)(HWidget *p_widget, int keycode);

	/*[abstract function] destroy a widget*/
	void (*destroy)(HWidget *p_widget);
};

enum {
	ATTR_VISIBLE,
	ATTR_ENABLE_FOCUS,
	ATTR_HAS_FOCUS,
	ATTR_ENABLE,
	ATTR_ENABLE_BGCOLOR,
	ATTR_ENABLE_DRAG,
	ATTR_OPAQUE,
	ATTR_ENABLE_HOVER,
	ATTR_HOVER,
	ATTR_ENABLE_HOVER_COLOR,
	ATTR_ENABLE_HOVER_BGCOLOR,

	ATTR_WIDTH_FLAG,
	ATTR_HEIGHT_FLAG,
	ATTR_MAX_WIDTH_FLAG,
	ATTR_MAX_HEIGHT_FLAG,

	ATTR_IS_CONTAINER,
	ATTR_IS_PLANE,

	ATTR_AUTO_FREE,
	ATTR_AUTO_RESET,
	ATTR_IN_HASHTABEL,

	//framework inner event
	ATTR_ACCEPT_DELETE_EVENT,

	//scroll over
	ATTR_ENABLE_SCROLL_EFFECT,
	ATTR_RICH_SCROLL_EFFECT,

	//char attr
	ATTR_CUT_STR,	//cut 'ABCDEFG' to 'ABCD...', only used for button
	ATTR_KEEP_WORD_WHOLE //when split a label's text, keep the world whole
};

typedef enum _InnerEvent {
	IE_REMOVE_EVENT,//(not implement)
	IE_DELETE_EVENT
} InnerEvent;

HRect calc_intersect_clip(HRect *r1, HRect *r2);

void try_scroll(HWidget *p_widget, short s_dx, short s_dy);

void bubble_event(HWidget *p_source, HEvent *p_evt, void *p_param);

struct _HContainer *find_scrollable(HWidget *p_widget);

/*get the widget default bgcolor, inherit from its ancestor*/
int get_default_bgcolor(HWidget *p_widget);

/*translate the widget point to screen point, if the p_widget is not in a HPlane, then return Point{-1,-1}*/
HPoint get_screen_point(HWidget *p_widget, short s_x, short s_y);

/*when the widget size(width/height) change call it to notify parent recalculate its size*/
void notify_size_changed(HWidget *p_widget);

/*get the widget root widget(its a HPlane), if the widget not in a plane, NULL will be returned*/
struct _HPlane* get_root(HWidget *p_widget);

/*get the paint handle. if the p_widget is not in a HPlane, then will return -1*/
int get_paint_handle(HWidget *p_widget);

void fire_visible(HWidget *p_widget, short s_x, short s_y, short s_width, short s_height);

void set_border(HWidget *p_widget, struct _HBorder *p_border);

/*flush the screen*/
void flush_screen(void);

/*set widget's width*/
void set_width(HWidget *p_widget, short s_width);

/*set widget's height*/
void set_height(HWidget *p_widget, short s_height);

/*set the widget max width*/
void set_max_width(HWidget *p_widget, short s_max_width);

/*set the widget max height*/
void set_max_height(HWidget *p_widget, short s_max_height);

void _repaint(HWidget *);

void _invalidate(HWidget *);

void _validate(HWidget *);

void pen_leave(HWidget *p_widget, short s_x, short s_y);

void pen_enter(HWidget *p_widget, short s_x, short s_y);


typedef enum _ScrollDir {
	SCROLL_UP = 1,
	SCROLL_DOWN = 2,
	SCROLL_LEFT = 4,
	SCROLL_RIGHT = 8
} ScrollDir;

int scrollable_distance(struct _HContainer *p_cnt, ScrollDir dir);

typedef enum _RectVisble {
	RECT_VISIBLE_NO,
	RECT_VISIBLE_FULL,
	RECT_VISIBLE_PART
} RectVisible;

RectVisible rect_visible(HWidget *p_widget, HRect rect, ScrollDir sd, int i_zoom);

typedef enum _Where{
	WHERE_NONE,
	WHERE_TOP,
	WHERE_CONTENT,
	WHERE_BOTTOM
} Where;

Where where_is(HWidget *p_widget);

#define  _max_(a,b) ((a) > (b) ? (a) : (b))
#define  _min_(a,b) ((a) < (b) ? (a) : (b))
#define _abs_(a) ((a) > 0 ? (a) : (-(a)))

#define  HWIDGET_GET_ATTRIBUTE(p_widget, name)	((p_widget)->i_attr & (1 << name))
#define  HWIDGET_SET_ATTRIBUTE(p_widget, name)	((p_widget)->i_attr |= (1 << name))
#define  HWIDGET_CLEAR_ATTRIBUTE(p_widget, name)	((p_widget)->i_attr &= ~(1 << name))


#define is_hover(p_widget) (HWIDGET_GET_ATTRIBUTE((HWidget *)p_widget, ATTR_ENABLE_HOVER) && HWIDGET_GET_ATTRIBUTE((HWidget *)p_widget, ATTR_HOVER))
#define has_focus(p_widget) (HWIDGET_GET_ATTRIBUTE((HWidget *)p_widget, ATTR_ENABLE_FOCUS) && HWIDGET_GET_ATTRIBUTE((HWidget *)p_widget, ATTR_HAS_FOCUS))

enum {
	ALIGN_LEFT		= (1 << 0),
	ALIGN_RIGHT		= (1 << 1),
	ALIGN_TOP		= (1 << 2),
	ALIGN_BOTTOM	= (1 << 3),
	ALIGN_H_CENTER	= (1 << 4),
	ALIGN_V_CENTER	= (1 << 5),
	ALIGN_H_MASK	= (ALIGN_LEFT | ALIGN_RIGHT | ALIGN_H_CENTER),
	ALIGN_V_MASK	= (ALIGN_TOP | ALIGN_BOTTOM | ALIGN_V_CENTER),

	ALIGN_SPACE_TEXT_LEFT = (1 << 6),	//it is default
	ALIGN_SPACE_TEXT_RIGHT = (1 << 7)
};

#define W(p) ((HWidget *)p)

#define is_support_vec(f)	(f > 0 && vm_graphic_is_use_vector_font())

void apply_font(HFont font, int i_font_size);

void apply_font2(HWidget *p);

#endif
