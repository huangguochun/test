/****************************************************************
* FILE Name: HTextInput.h
* Description: Header file HTextInput( a HWidget). HTextInput is a single line text editor, it can use as password text editor.
* COPYRIGHT: Hisoft
* Created on: $(8.24.2011) Author: Geng,XuanXuan
****************************************************************/

#ifndef _HTEXTINPUT_H
#define _HTEXTINPUT_H

#include "hwidget.h"
#include "himage.h"

#define TEXTINPUT_DEFAULT_TEXT_LEN 50		/* max length of default text */

typedef struct _HTextInput HTextInput;		/* define HTextInput type */

struct _HTextInput {
	HWidget base;		/* Base class */

	VMWCHAR *pwc_text;

	VMWCHAR awc_default_text[TEXTINPUT_DEFAULT_TEXT_LEN + 1];		/* Default text show in HTextInput when text is empty */
	
	char c_is_password;		/* Flag of password model */
	
	char c_input_method;		/* Default input method */
	
	short s_move_offset;		/* x axis move offset */

	int i_length;				/* text length */

	int i_max_len;			/* max length of HTextInput's text */

	HImage *p_bgimg;		/* background image of HTextInput */ 
};

/*
 Function Name: htextinput_new
 Description: Get a new HTextInput
 Return: Pointer of new HTextInput
*/
HTextInput * htextinput_new(void);

/*
 Function Name: htextinput_new
 Description: Get a new HTextInput
 Para(in) p_htextinput: Pointer of HTextInput self
*/
void htextinput_delete(HTextInput *p_textinput);

/*
Function Name: htextinput_init
Description: init a HTextInput that has already been assigned memory
Para(in) p_htextinput: Pointer of HTextInput self
*/
void htextinput_init(HTextInput *p_textinput);

/*
Function Name: htextinput_clean
Description: clean a HTextInput
Para(in) p_htextinput: Pointer of HTextInput self
*/
void htextinput_clean(HTextInput *p_textinput);

/*
Function Name: set_text
Description: Set text of HTextInput
Para(in) p_textinput: Pointer of HTextInput self
Para(in) pc_text: GB2312 Text of HTextInput
*/
void htextinput_set_text(HTextInput *p_textinput, char *pc_text);

/*
Function Name: htextinput_set_ucs2_text
Description: Set UCS2 text for HTextInput
Para(in) p_textinput: Pointer of HTextInput self
Para(in) p_ucs2: UCS2 string
*/
void htextinput_set_ucs2_text(HTextInput *p_textinput, VMWCHAR *p_ucs2);

/*
Function Name: set_dedault_text
Description: Set default text of HTextInput,  the default text will disappear when the text is empty
Para(in) p_textinput: Pointer of HTextInput self
Para(in) pc_text: Text of HTextInput
*/
void htextinput_set_dedault_text(HTextInput *p_textinput, char *pc_text);

/*
Function Name: set_dedault_text
Description: Set default ucs2 text of HTextInput,  the default text will disappear when the text is empty
Para(in) p_textinput: Pointer of HTextInput self
Para(in) p_ucs2: Text of HTextInput
*/
void htextinput_set_dedault_ucs2_text(HTextInput *p_textinput, VMWCHAR *p_ucs2);

/*
Function Name: set_max_len
Description: set max length of HTextInput's text
Para(in) p_textinput: Pointer of HTextInput self
Para(in) i_max_length: max length of HTextInput text
*/
void htextinput_set_max_len(HTextInput *p_textinput, int i_max_length);

/*
Function Name: get_text
Description: Get text of HTextInput, you need to release the memory by your self
Para(in) p_htextinput: Pointer of HTextInput self
Return: Text of HTextInput
*/
char* htextinput_get_text(HTextInput *p_textinput);

/*
Function Name: get_len
Description: Get length of HTextInput's Text.
Para(in) p_htextinput: Pointer of HTextInput self
Return: GB2312 Text of HTextInput
*/
int htextinput_get_len(HTextInput *p_textinput);

/*
Function Name: set_input_method
Description: Set default input method of HTextInput
Para(in) p_htextinput: Pointer of HTextInput self
Para(in) i_input_method: Default input method of HTextInput
*/
void htextinput_set_input_method(HTextInput *p_textinput, int i_input_method);

/*
Function Name: set_is_password
Description: Set password flag of HTextInput
Para(in) p_htextinput: Pointer of HTextInput self
Para(in) i_password: password flag of HTextInput 
0 false;  1 true
*/
void htextinput_set_is_password(HTextInput *p_textinput, int i_password);

/*
Function Name: set_share_bgimg
Description: set background image
Para(in) p_textinput: Pointer of HTextInput self
Para(in) p_bgimage: background image
*/
void htextinput_set_image(HTextInput *p_textinput, HImage *p_bgimage);

/*
Function Name: clear
Description: clear text in HTextInput, the widget will repaint themselves
Para(in) p_textinput: Pointer of HTextInput self
*/
void htextinput_clear_text(HTextInput *p_textinput);

void htextinput_call_input(HTextInput *p_this);

#endif

/********************************EOF***********************************/