/*
	
*/
#ifndef _HTEXTAREA_H
#define _HTEXTAREA_H

#include "hwidget.h"
#include "../Common/array.h"
#include "himage.h"

#define TEXTAREA_DEFAULT_TEXT_LEN 30

typedef struct _HTextArea HTextArea;

struct _HTextArea {
	HWidget base;

	VMWCHAR *pwc_text;

	VMWCHAR awc_default_text[TEXTAREA_DEFAULT_TEXT_LEN + 1];		/* default text, it will be show when the pwc_text is empty */

	char c_show_cursor;

	char c_line_space;

	char c_input_method;

	char c_cursor_is_heightlight;		/* draw cursor when c_cursor_is_heightlight is 1 */

	int i_move_offset;		/* offset on y axis */

	int i_cursor_position;		/* cursor current position */

	int i_words_len;			/* current text length */

	int i_words_capacity;		/* memory size of pwc_text(double) */

	int i_max_length;		/* max length for input method limit, the default length is 140 */

	int i_cursor_timer;		/* timer id for cursor */

	HImage *p_bgimg;	/* hover image */

	Array lines;		/* line nodes array */
};

/* create a new HTextArea */
HTextArea *htextarea_new(void);

/* initialized a exist HTextArea */
void htextarea_init(HTextArea *p_this);

/* clean HTextArea text, image */
void htextarea_clean(HTextArea *p_this);

/* destroy a HTextArea */
void htextarea_delete(HTextArea *p_this);

/* set HTextArea content text */
void htextarea_set_text(HTextArea *p_this, char *pc_text);

/* set UCS2 text */
void htextarea_set_ucs2_text(HTextArea *p_this, VMWCHAR *pwc_text);

/* insert text by current cursor position, if return 1, insert success, else insert failed */
int htextarea_insert_text(HTextArea *p_this, char *pc_text);

/* insert ucs2 text by current cursor position, if return 1, insert success, else insert failed */
int htextarea_insert_ucs2_text(HTextArea *p_this, VMWCHAR *p_ucs2);

/* return gb2312 text, this memory should release by your self */
char * htextarea_get_text(HTextArea *p_this);

/* return UCS2 text, this memory will be released by HTextArea it self */
VMWCHAR * htextarea_get_ucs2_text(HTextArea *p_this);

void htextarea_clear_text(HTextArea *p_this);

/* if textarea content is empty, default text will be show */
void htextarea_set_default_text(HTextArea *p_this, char *pc_text);

/* if textarea content is empty, default text will be show */
void htextarea_set_default_ucs2_text(HTextArea *p_this, VMWCHAR *p_ucs2);

/* set input method , the default input method is PinYin */
void htextarea_set_inputmethod(HTextArea *p_this, int i_input_method);

/* set space between two lines */
void htextarea_set_space(HTextArea *p_this, int i_space);

/* get length of HTextArea's text */
int htextarea_get_len(HTextArea *p_this);

/* set HTextArea HOVER image */
void htextarea_set_image(HTextArea *p_this, HImage *p_image);

void htextarea_call_input(HTextArea *p_this);









#endif
/********************* EOF ********************/