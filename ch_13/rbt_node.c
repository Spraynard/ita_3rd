#include "bst_node.h"
#include "rbt_node.h"
#include <stdlib.h>
#include <stdio.h>

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
	printf("Key: %d\n", x->key);
	printf("Color: %d\n\n", x->color);

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

/**
 * Binary Search Tree property guarantees that
 * we find the minimum value in the tree by iterating through
 * the "left" properties of each of the node.
 */
rbt_node * RBT_Minimum( rbt_node * x ) {
	while ( x->left != NULL )
	{
		x = x->left;
	}

	return x;
}

int RBT_Node_Compare( rbt_node * x, rbt_node * y ) {

	// Checking for null pointer compared to non null pointer.
	if ( x != NULL && y == NULL )
	{
		return 0;
	}
	else if ( x == NULL && y != NULL )
	{
		return 0;
	}

	// Case if both null
	if ( x == NULL && y == NULL )
	{
		return 1;
	}

	// Extracting Data from A
	int key_x = -1;//`x->key;
	int key_y = -1;//`y->key;

	if ( x->key )
	{
		key_x = x->key;
	}

	if ( y->key )
	{
		key_y = y->key;
	}

	if ( key_x != key_y )
	{
		return 0;
	}

	int key_x_parent = -1;
	int key_y_parent = -1;

	if ( x->parent != NULL )
	{
		key_x_parent = x->parent->key;
	}

	if ( y->parent != NULL )
	{
		key_y_parent = y->parent->key;
	}

	if ( key_x_parent != key_y_parent )
	{
		return 0;
	}

	int key_x_left = -1;
	int key_y_left = -1;

	if ( x->left != NULL )
	{
		key_x_left = x->left->key;
	}
	if ( y->left != NULL )
	{
		key_y_left = y->left->key;
	}

	if ( key_x_left != key_y_left )
	{
		return 0;
	}

	int key_x_right = -1;
	int key_y_right = -1;

	if ( x->right != NULL )
	{
		key_x_right = x->right->key;
	}
	if ( y->right != NULL )
	{
		key_y_right = y->right->key;
	}

	if ( key_x_right != key_y_right )
	{
		return 0;
	}

	// Inequal if the last test didn't work.
	return 1;
}
