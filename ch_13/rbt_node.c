#include "bst_node.h"
#include "rbt_node.h"
#include "rbt_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

rbt_node * rbt_node_new( int value ) {
	rbt_node * N = malloc( sizeof( rbt_node ) );
	N->color = 0;
	N->left = NULL;
	N->right = NULL;
	N->parent = NULL;
	N->key = value;
	return N;
};

void Print_RBT_Node( rbt_node * x ) {
	if ( ! x )
	{
		printf("NODE IS NULL\n");
		return;
	}

	printf("Key: %d\n", x->key);
	printf("Color: %d\n\n", x->color);

	printf("Parent\n");
	printf("------\n");
	if ( x->parent == NULL )
	{
		printf("\t%s\n", "NULL");
	}
	else
	{
		printf("\tKey: %d\n", x->parent->key);
		printf("\tColor: %d\n", x->parent->color);
	}

	printf("Left\n");
	printf("----\n");
	if ( x->left == NULL )
	{
		printf("\t%s\n", "NULL");
	}
	else
	{
		printf("\tKey: %d\n", x->left->key);
		printf("\tColor: %d\n", x->left->color);
	}

	printf("Right\n");
	printf("----\n");
	if ( x->right == NULL )
	{
		printf("\t%s\n", "NULL");
	}
	else
	{
		printf("\tKey: %d\n", x->right->key);
		printf("\tColor: %d\n", x->right->color);
	}

	printf("\n");
}

rbt_node * RBT_Search( rbt_tree * T, rbt_node * x, int key ) {
	if ( x == T->null || key == x->key )
	{
		return x;
	}

	if ( key < x->key )
	{
		return RBT_Search( T, x->left, key );
	}
	else
	{
		return RBT_Search( T, x->right, key );
	}
}
