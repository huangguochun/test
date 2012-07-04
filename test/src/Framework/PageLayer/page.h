/*********************************
*file: page.h
*author: yan.gao
*date: 2011.08.19
*description: 
***********************************/
#ifndef _PAGE_H_
#define _PAGE_H_

typedef struct _Page Page;
typedef struct _PageControl PageControl;

#include "../Common/array.h"

#define PAGE_ROOT_TYPE	-1


extern PageControl g_ctrl;

struct _Page {
	/*user defined a unique id*/
	int i_page_id;

	/*the page type. user should define it*/
	int i_page_type;

	/* flag of pages always live, if i_live is 1, page always lives, else is 0. default is 0. */
	int i_live;

	/*flag of whether this Page will in history*/
	int i_no_history;

	/*show this page */
	void (*fire_visible)(Page *p_this);

	/* hide this page */
	void (*fire_hidden)(Page *);

	/*destroy the page , free its memory, its not necessary*/
	void (*destroy)(Page *p_this);
};

struct _PageControl {
	/* save all pages*/
	Array pages;

	/*current page index in pages*/
	int i_cursor;

	int i_will_page;	/*will goto the page*/
};


/* load a new page */
void page_load_new(Page *p_new_page);

/*load page find from switch controller*/
void page_load_exists(Page *p_exist_page);

/* load page that don't know existing */
void page_load(Page *p_page);

/*delete a page from the pages, and will free its memory*/
void page_delete(Page *p_page);

/*find a page by  page type*/
Page * page_find_by_type(int i_page_type);

/*find a page by  page id*/
Page * page_find_by_id(int i_page_id);

/* get current page */
Page * page_get_current(void);

/*show back page*/
void page_go_back(void);

/*return the will goto a page's type*/
int page_get_will_goto(void);



#endif