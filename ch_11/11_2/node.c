#include "node.h"
#include <stdlib.h>
#include <stdio.h>


Node * Init_Node( char * key, int value ) {
	Node * n = ( Node * ) malloc( sizeof( Node ) );
	n->next = NULL;
	n->prev = NULL;
	n->item = ht_item_new( key, value );
	return n;
}

void Delete_Node( Node * N ) {
	free( N->next );
	free( N->prev );
	free( N );
}

void Print_Node( Node * N )
{
	printf("Node:\n");

	if ( N == NULL )
	{
		printf("NULL NODE\n");
		return;
	}

	printf("Node Item\n");
	Print_Item(N->item);
	printf("\n");

	if ( N->next != NULL )
	{
		printf("Next Node Item\n");
		Print_Item(N->next->item);
		printf("\n");
	}
	else
	{
		printf("Next -> NULL\n");
	}

	if ( N->prev != NULL )
	{
		printf("Prev Node Item\n");
		Print_Item(N->prev->item);
		printf("\n");
	}
	else
	{
		printf("Prev -> NULL\n");
	}
}