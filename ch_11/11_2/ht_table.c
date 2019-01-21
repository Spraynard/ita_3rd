#include "ht_table.h"
#include "ht_item.h"
#include "list.h"
#include "node.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#define BASE_TABLE_SIZE 20000

void Print_Table( ht_table * T ) {
	int i;

	printf("Printing Table\n");
	printf("--------------\n");

	for ( i = 0; i < T->size; i++ )
	{
		printf("Index: %d\n", i);

		Print_List( T->items[i] );
	}

	printf("------------------\n");
	printf("End Printing Table\n");
	printf("\n");
}

ht_table * ht_table_new() {
	ht_table * t = malloc( sizeof( ht_table ) );
	t->size = BASE_TABLE_SIZE;
	t->count = 0;
	t->items = calloc( BASE_TABLE_SIZE, sizeof( List * ) );

	if ( t->items == NULL )
	{
		printf("Unable to provide enough memory for t->items\n");
	}

	return t;
}

// Delete a hash table and free up the memory used by it.
void ht_table_delete( ht_table * T ) {
	int i;

	for ( i = 0; i < T->size; i++ )
	{
		Delete_List( T->items[i] );
	}

	free( T->items );
	free( T );
}

int hash_ascii( char * c, int m ) {
	unsigned long long int hash = 0;
	int str_len = strlen( c ), i;

	for ( i = 0; i < str_len; i++ )
	{
		hash += pow( 128, str_len - i - 1 ) * c[i];
	}

	return hash % m;
}

// Inserts an item in the table inside a list given at the specific
// table index obtained by our hash function.

void ht_chained_insert( ht_table * T, char * key, int value ) {
	Node * searchedNode;
	Node * newNode;
	int searchedNodeValue;

	int table_index = hash_ascii( key, T->size ); // Obtain index in the table based on key given.
	List * L = T->items[table_index];

	// Null slot means we don't have a list initialized in that slot yet.
	if ( L == NULL )
	{
		L = T->items[table_index] = Init_List();
	}

	// Search for a duplicate value
	searchedNode = List_Search( L, key );

	// Chained Insert
	if ( searchedNode == NULL )
	{
		// Insert a new node in the list.
		newNode = Init_Node( key, value );
		List_Insert( L, newNode );
	}
	// Update
	else
	{
		searchedNodeValue = searchedNode->item->value;

		if ( searchedNodeValue != value )
		{
			searchedNode->item->value = value;
		}
	}
}

// Returns a Node pointer that has such a key.
// Should be pretty fast. O(1 + m) where m is the length of our Linked List
Node * ht_search( ht_table * T, char * key ) {
	int table_index = hash_ascii( key, T->size );
	Node * N = malloc( sizeof( Node * ) );
	List * L = T->items[table_index];

	N = List_Search( L, key );

	return N;
}