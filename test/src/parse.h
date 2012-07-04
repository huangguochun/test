/*
 * parse json
 */
#ifndef __PARSE_H__
#define __PARSE_H__
#include "json.h"
/* actually this is the http's callbak */
void parse(unsigned char *buf, int size, short id);
void parse_team_item_data(unsigned char *buf, int size, short id);
#endif
