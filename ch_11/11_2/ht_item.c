#include "ht_item.h"
#include "list.h"
#include "node.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Creates a new hash table item to be in the "items" array of ht_table
 */
ht_item * ht_item_new( char * key, int value ) {

	ht_item * item = malloc( sizeof( ht_item * ) );

	item->key = malloc( sizeof ( char * ) );
	item->key = strncpy( item->key, key, strlen( key ) );
	item->value = value;

	return item;
}

void Print_Item( ht_item * I ) {
	// printf("Item\n");
	// printf("----\n");

	if ( I == NULL )
	{
		printf("\tNULL\t");
	}
	else
	{
		printf("%s\t->\t%d\t", I->key, I->value);
	}
	// printf("\n");
}