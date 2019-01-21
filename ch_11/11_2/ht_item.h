#include "list.h"

#ifndef _HT_ITEM_H
#define _HT_ITEM_H

typedef struct {
	char * key;
	int value;
} ht_item;

ht_item * ht_item_new( char * key, int value );
void Print_Item( ht_item * I );

#endif