/****************************************************************
* FILE Name: himage.h
* Description: image that load picture from app resource or memory buffer
* COPYRIGHT: 
* Created on: $(12.14.2011) Author: Geng,XuanXuan
****************************************************************/

#ifndef _HIMAGE_H
#define _HIMAGE_H

#include "vmsys.h"
#include "hwidget.h"

enum {
	IMAGE_ATTR_AUTO_FREE,
	IMAGE_ATTR_AUTO_RESET,
	IMAGE_ATTR_HOR_FILL,
	IMAGE_ATTR_VER_FILL,
	IMAGE_ATTR_AUTO_FREE_BUF,
	IMAGE_ATTR_SUPPORT_PNG
};

#define  HIMAGE_GET_ATTRIBUTE(p_image, name)	((p_image)->s_attr & (1 << name))
#define  HIMAGE_SET_ATTRIBUTE(p_image, name)	((p_image)->s_attr |= (1 << name))
#define  HIMAGE_CLEAR_ATTRIBUTE(p_image, name)	((p_image)->s_attr &= ~(1 << name))

typedef struct _HImage HImage;

/************************************************************************
* Now, HImage support two mode: support PNG mode and default mode
*	you can use himage_set_support_png to change its mode
************************************************************************/
struct _HImage {
	int i_canvas;//canvas
	short s_x;
	short s_y;
	short s_width;
	short s_height;
	unsigned char uc_frame;//default is 1
	short s_attr;//image attribute
	unsigned char *p_png_buf;
	int i_png_size;
};

/* paint image, the default frame if the first one, your can set the frame index by function himage_set_paint_frame */
void himage_paint(HImage *p_this, HGraphic *p_graphic);

/* paint image by the frame index */
void himage_paint_frame(HImage *p_this, HGraphic *p_graphic, int i_frame_index);

/* set image position relative it's owner */
void himage_set_position(HImage *p_this, short x, short y);

/* get image frame count */
int	 himage_get_frame_count(HImage *p_this);

/* load image from app resource */
int himage_load_frome_resource(HImage *p_this, char *p_path);

/* load image from memory buffer, if p_size is NULL, image size is default size, else load image resize by p_size */
int	himage_load_from_buffer(HImage *p_this, VMUINT8 *p_buf, VMINT i_size, HSize *p_size);

int himage_is_support_png(HImage *p_this);

/************************************************************************
* If yes:  this image is support png , and its real a png file/buffer
************************************************************************/
int himage_is_real_png(HImage *p_this);

/************************************************************************
* set whether is support png
* @param i_is_support:  1: support png   0:not support
* Note: You must call this function before the two function:
*		himage_load_image_from_buffer , himage_load_image_from_resource
************************************************************************/
void himage_set_support_png(HImage *p_this, int i_is_support);

/* image is loaded or not */
int	himage_is_validate(HImage *p_this);

/* get image width and height */
HSize himage_get_size(HImage *p_this, unsigned char uc_frame_num);

/* set image current paint frame index, the default  */
void himage_set_paint_frame(HImage *p_this, unsigned char uc_frame_num);

/* set image attr flag by int var */
void himage_set_attr(HImage *p_this, int i_attr);

/* create a new image */
extern HImage *himage_new(void);

/* initialize a image */
extern void	himage_init(HImage *p_this);

/* clean a image by attr flag */
extern void	himage_clean(HImage *p_this);

/* delete a image by attr flag */
extern void	himage_delete(HImage *p_this);

/* delete a image ignore of the attr flag, framework should not call this */
extern void himage_force_delete(HImage *p_this);

/* clean a image ignore of the attr flag, framework should not call this */
extern void himage_force_clean(HImage *p_this);

#endif

/******************************* EOF ***********************************/