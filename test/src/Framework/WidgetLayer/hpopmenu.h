/*




*/

#ifndef _HPOPMENU_H
#define _HPOPMENU_H

#include "hcontainer.h"
#include "hbutton.h"

#define POPMENU_ITEMS_COUNT 8
typedef struct _HPopMenu HPopMenu;

extern HButton popmenu_item_templet; /* templet for item, the item's style is same as this button */

struct _HPopMenu {
	HContainer base;

	int i_is_showing;
	int i_item_index;
	HButton items[POPMENU_ITEMS_COUNT];
};

HPopMenu * hpopmenu_get_instance(void);

void hpopmenu_add_item(char *pc_text);

void hpopmenu_add_item_ucs2(VMWCHAR *p_ucs2);

void hpopmenu_clean_items(void);

void hpopmenu_set_gap(int i_gap);

void hpopmenu_show(void);

void hpopmenu_hide(void);

int popmenu_softkey_event_filter(int i_evt, int i_keycode);

#endif

/********************** EOF *********************/