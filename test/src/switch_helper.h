/*
 * This interface help you switch to other view without any details
 * of the view.
 */
#ifndef __SWITCH_HELPER_H__
#define __SWITCH_HELPER_H__
#include "globals.h"

enum button_action_selection {
    tbd = 0
};

extern void switch_view(HWidget *src, HEvent *e, void *param);
extern void switch_view_msg(HWidget *src, HEvent *e, void *param);

void cache_or_http(void);
#endif
