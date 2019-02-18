#include "node.h"
#include "stdlib.h"
#include "stdio.h"

struct node * node_new( int value ) {
	struct node * x = malloc( sizeof( struct node ) );
	x->value = value;
	x->left = NULL;
	x->right = NULL;
	return x;
}

void print_node( struct node * N ) {
	printf("Value: %d", N->value);
}


struct node * node_copy( struct node * N ) {
	
	struct node * copy = NULL;

	if ( N != NULL )
	{
		copy = node_new( N->value );
		copy->left = N->left;
		copy->right = N->right;
	}

	return copy;	
}

struct node * search( struct node * N, int key ) {
	if ( N == NULL || N->value == key )
	{
		return N;
	}

	if ( key < N->value )
	{
		return search( N->left, key );
	}
	else
	{
		return search( N->right, key );
	}
}