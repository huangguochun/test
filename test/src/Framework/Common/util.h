#ifndef _COMMON_UTIL_H
#define _COMMON_UTIL_H

#include "../WidgetLayer/hwidget.h"
#include "vmstdlib.h"



/* cal the word num in text, pi_char_num is single byte words number, pi_wchar_num is double byte words number */
void get_text_words_num(char *pc_text, int *pi_char_num, int *pi_wchar_num);

/* get ucs2 text single byte words number and double byte words number */
void get_ucs2_words_num(VMWCHAR *p_ucs2, int *pi_char_num, int *pi_wchar_num);

/* convert multi gb2312 text to ucs2 text */
VMWCHAR * gb2312_to_ucs2_multi(char *pc_src, int *pi_wstr_len);

VMWCHAR *gb2312_to_ucs2(char *p_char_str);

char *ucs2_to_gb2312(VMWCHAR *p_ucs2_string);

/* get font character height */
#define  get_font_height vm_graphic_get_character_height

short get_str_font_height(VMWCHAR *p_wstr);

/*
* split text to muti line
* @param p_text: the need to split text
* @param p_result: the split result store in the array
* @param s_max_width: each row's max width
* @param font: the font for the text
* @param i_wstr_len: the wchar length of p_text, if you don't give it ,set to -1
*/
void split_text(VMWCHAR *p_text, Array *p_result, short s_max_width, HFont font, int i_wstr_len, int i_keep_word);


/* judge the pen event type is the i_event_type or not */
int is_pen_event(HEvent *p_event, int i_event_type);

/* judge the key event type is the i_event_type and keycode or not */
int is_key_event(HEvent *p_event, int i_event_type, int i_keycode);

/* judge the focus event type is the i_event_type and changed flag or not */
int is_focus_event(HEvent *p_event, int i_event_type, int i_change);

/*make 'ABCDEFG' to 'ABCD...'*/
void cut_wstr(VMWCHAR *p_wstr, int i_max_width, HFont font);


#define mk_r(i)	((i >> 16) & 0xff)
#define mk_g(i)	((i >> 8) & 0xff)
#define mk_b(i) (i & 0xff)

#define color_rgb_to_565(rgb) VM_COLOR_888_TO_565(mk_r(rgb), mk_g(rgb), mk_b(rgb))

#endif