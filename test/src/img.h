/*
 * HTTP image download.
 *
 * While request image from remote server, first http will give a
 * URL of the image, we need to cache these URLs and download them
 * in a specified point. While download complete, we repaint the related
 * widgets.
 */
#ifndef __IMG_H__
#define __IMG_H__
#include "globals.h"
/* Download the image and then paint them on the related widgets */
void download_img(unsigned char *buf, int size, short idx);
void download_img_url(unsigned char *buf, int size, short idx);

/* download next image */
void download_next_img(void);

void record_url(void);
#endif
