/************************************************************************
* Name : htooltip.h
* Copyright : Hisoft
* Modify : Gao,Yan 2011.12.14
************************************************************************/
#ifndef				_HTOOLTIP_H
#define				_HTOOLTIP_H

#include				"../WindowLayer/hwindow.h"
#include				"hwidget.h"
#include				"hplane.h"

#define TP_LINE_SPACE 5

typedef struct _HToolTip HToolTip;

struct _HToolTip {
	HWidget		base;
	VMINT		tid;
	VMWCHAR		tip_msg[80];
	Array		lines;
};

/************************************************************************
* show tooltip , use default color and bgcolor
************************************************************************/
void htooltip_show(const char *p_tip_msg,  int i_millisec);

void htooltip_ucs2_show(const VMWCHAR *p_tip_msg,  int i_millisec);


/************************************************************************
* Name : htooltip_show
* Description : show the tooltip int the popupmenu plane
* Description :  and repaint,it will hide many millisecond later
* @para(in) p_Me : the tooltip structure
* @para(in) p_tip_msg : the status string
* @para(in) i_color : the string color
* @para(in) bg_color : the bg color
* @para(in) millisec : the unit of interval is millisecond 
************************************************************************/
void htooltip_show2(const char *p_tip_msg, int i_rgb_color, int i_rgb_bgcolor,  int millisec);

void htooltip_ucs2_show2(const VMWCHAR *p_tip_msg, int i_rgb_color, int i_rgb_bgcolor,  int millisec);


/************************************************************************
* Name : htooltip_hide
* Description : hide the tooltip int the popupmenu plane, and repaint
* @para(in) p_Me : the tooltip structure
************************************************************************/
void htooltip_hide(void);

/************************************************************************
* Name : htooltip_get_instance
* Description : get the global unique HTooltip instance
************************************************************************/
HToolTip * htooltip_get_instance(void);


#endif

/******************************* EOF ***********************************/