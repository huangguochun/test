/*****************************************************************
* File Name: draw_frame.c
*
* Description: draw every page's frame
*
* COPYRIGHT:
*
* Create on: 2011-12-30 Author: Liu,Heng
*
*Modified by name on $(Date)
*****************************************************************/

#ifndef __ACTION_CRICKET_H__
#define __ACTION_CRICKET_H__

/**********************INCLUDE FILES******************************/
#include "hwidget.h"

/*****************************************************************
* Function Name: action_menu_bar
*
* Description: menu bar action
*
* Parameters:
*
* Return:
*****************************************************************/
void action_menu_bar(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_menubar_back
*
* Description: menu bar: no left action, only right-key-back action
*
* Parameters:
*
* Return:
*****************************************************************/
void action_menubar_back(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_menubar_autorefresh
*
* Description: menu bar for auto refresh: LSK for select, RSK for back
*
* Parameters:
*
* Return:
*****************************************************************/
void action_menubar_autorefresh(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_autorefresh
*
* Description: set auto refresh time
*
* Parameters:
*
* Return:
*****************************************************************/
void action_autorefresh(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_menubar_okrefresh
*
* Description: action of ok and refresh
*
* Parameters:
*
* Return:
*****************************************************************/
void action_menubar_okrefresh(HWidget *p_source, HEvent *p_evt, void *p_param);

/* action of refresh */
void action_menubar_refresh(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_menubar_ok
*
* Description: action of ok
*
* Parameters:
*
* Return:
*****************************************************************/
void action_menubar_ok(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_menubar_nxtref
*
* Description: action of next and refresh
*
* Parameters:
*
* Return:
*****************************************************************/
void action_menubar_nxtref(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_menubar_pretref
*
* Description: action of prev and refresh
*
* Parameters:
*
* Return:
*****************************************************************/
void action_menubar_pretref(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_menubar_search
*
* Description: action of menu bar's search
*
* Parameters:
*
* Return:
*****************************************************************/
void action_menubar_search(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_search_bar
*
* Description: action of search bar
*
* Parameters:
*
* Return:
*****************************************************************/
void action_search_bar(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_whether_download
*
* Description: action whether download
*
* Parameters:
*
* Return:
*****************************************************************/
//void action_whether_download(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_whether_update
*
* Description: action whether update
*
* Parameters:
*
* Return:
*****************************************************************/
//void action_whether_update(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_whether_launch
*
* Description: action whether launch
*
* Parameters:
*
* Return:
*****************************************************************/
//void action_whether_launch(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_view_more
*
* Description: action of view more
*
* Parameters:
*
* Return:
*****************************************************************/
void action_view_more(HWidget *p_source, HEvent *p_evt, void *p_param);

/*****************************************************************
* Function Name: action_next_photo
*
* Description: action next or prev photo
*
* Parameters:
*
* Return:
*****************************************************************/
void action_nxtpre_photo(HWidget *p_source, HEvent *p_evt,void *p_param);

#endif