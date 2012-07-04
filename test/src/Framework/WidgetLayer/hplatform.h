#ifndef HPLATFORM_H
#define HPLATFORM_H

#include "vmgraph.h"
#include "vmio.h"

/************************************************************************
* pen event define
************************************************************************/

#define H_TR_PEN_EVENT(evt)			evt

#define HPEN_EVENT_PRESS		VM_PEN_EVENT_TAP
#define HPEN_EVENT_MOVE			VM_PEN_EVENT_MOVE
#define HPEN_EVENT_RELEASE		VM_PEN_EVENT_RELEASE
#define HPEN_EVENT_REPEAT		VM_PEN_EVENT_REPEAT
#define HPEN_EVENT_LONG_PRESS	VM_PEN_EVENT_LONG_TAP
#define HPEN_EVENT_DOUBLE_CLICK VM_PEN_EVENT_DOUBLE_CLICK


/************************************************************************
* key event define
************************************************************************/
#define HTRANSLATE_KEY_EVENT	50
#define H_TR_KEY_EVENT(evt)		(evt + HTRANSLATE_KEY_EVENT)

#define HKEY_EVENT_UP			(VM_KEY_EVENT_UP  + HTRANSLATE_KEY_EVENT)
#define HKEY_EVENT_DOWN			(VM_KEY_EVENT_DOWN + HTRANSLATE_KEY_EVENT)
#define HKEY_EVENT_LONG_PRESS	(VM_KEY_EVENT_LONG_PRESS + HTRANSLATE_KEY_EVENT)
#define HKEY_EVENT_REPEAT		(VM_KEY_EVENT_REPEAT + HTRANSLATE_KEY_EVENT)


/************************************************************************
* focus event define
************************************************************************/
#define HFOCUS_EVENT 100
#define HCLOSE_EVENT 101
#define HCANCEL_EVENT 102
#define HINPUT_EVENT 103
#define HSCORLL_OVER_EVENT	104
#define HPEN_LEAVE_EVENT	105

#endif