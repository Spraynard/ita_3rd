#include "node.h"
#include <stdlib.h>

Node * Init_Node( int key ) {
	Node * n = ( Node * ) malloc( sizeof( Node ) );
	n->next = NULL;
	n->prev = NULL;
	n->key = key;

	return n;
}

void Print_Node( Node * N )
{
	printf("Node:\n");
	printf("Data -> %d\n", N->key);

	if ( N->next != NULL )
	{
		printf("Next -> %d\n", N->next->key);
	}
	else
	{
		printf("Next -> NULL\n");
	}

	if ( N->prev != NULL )
	{
		printf("Prev -> %d\n", N->prev->key);
	}
	else
	{
		printf("Prev -> NULL\n");
	}
}