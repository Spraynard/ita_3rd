#include "list.h"

#ifndef _HT_TABLE_H
#define _HT_TABLE_H

typedef struct {
	int size;
	int count;
	List ** items;
} ht_table;

ht_table * ht_table_new();
int hash_ascii( char * c, int m );

void ht_chained_insert( ht_table * T, char * key, int value );

void ht_table_delete( ht_table * T );

void Print_Table( ht_table * T );

#endif