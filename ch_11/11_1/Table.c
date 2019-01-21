#include "Table.h"
#include <stdlib.h>
#include <string.h>


Table buildTable( int * universe, int size ) {
	Table * T = ( Table * ) malloc( sizeof( Table ) );
	T->size = size;
	T->slots = malloc( T->size * sizeof( Element * ) );
	int i;

	for ( i = 0; i < T->size; i++ )
	{
		T->slots[i] = NULL;
	}

	return * T;
}

Element buildElement( int key, int * array, int size ) {
	Element * E = ( Element * ) malloc( sizeof( Element ) );
	E->key = key;
	E->dataArray = malloc( size * sizeof( int ) );
	memcpy(E->dataArray, array, size * sizeof( int ) );
	E->dataArraySize = size;

	return * E;
}

void printTable( Table * T ) {
	int i;
	printf("Table:\n");

	for ( i = 0; i < T->size; i++ ) {
		if ( ! T->slots[i] )
		{
			printf("%d\t->\tNULL\n", i);
			continue;
		}

		printf("%d\t->\t", T->slots[i]->key );
		printArray( T->slots[i]->dataArray, T->slots[i]->dataArraySize );
	}
}

void printElement( Element * E ) {
	printf("Element:\n");
	if ( E == NULL )
	{
		printf("NULL\n");
		return;
	}
	printf("Key:\t->\t%d\n", E->key);
	printf("Size:\t->\t%d\n", E->dataArraySize);
	printArray(E->dataArray, E->dataArraySize);
	printf("\n");
}

Element * Direct_Address_Search( Table * T, int key ) {
	if ( T->slots[key] == NULL )
	{
		return NULL;
	}
	return T->slots[key];
}

int Direct_Address_Insert( Table * T, Element E ) {
	if ( T->slots[E.key] )
	{
		printf("You are inserting into an already inserted area of the table\n");
		return 0;
	}

	T->slots[E.key] = malloc( sizeof ( Element ) );
	* T->slots[E.key] = E;

	return 1;
}

int Direct_Address_Delete( Table * T, Element E ) {
	if ( ! T->slots[E.key] )
	{
		printf("You are trying to delete an element that is not there\n");
		return 0;
	}

	T->slots[E.key] = NULL;
	return 1;
}