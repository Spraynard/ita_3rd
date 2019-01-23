#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

void Inorder_Tree_Walk( bst_node * x ) {
	if ( x != NULL )
	{
		Inorder_Tree_Walk( x->left );
		printf("%d ", x->key);
		Inorder_Tree_Walk( x->right );
	}

	return;
}

void Preorder_Tree_Walk( bst_node * x ) {
	if ( x != NULL )
	{
		printf("%d ", x->key);
		Preorder_Tree_Walk( x->left );
		Preorder_Tree_Walk( x->right );
	}

	return;
}

void Postorder_Tree_Walk( bst_node * x ) {
	if ( x != NULL )
	{
		Postorder_Tree_Walk( x->left );
		Postorder_Tree_Walk( x->right );
		printf("%d ", x->key);
	}

	return;
}


void Formatted_Preorder_Tree_Walk( bst_node * N, int level ) {
	int i;
	if ( N != NULL )
	{
		printf("\n");
		for ( i = 0; i < level; i++ )
		{
			printf("\t");
		}

		printf("%d ", N->key );

		if ( level == 0 )
		{
			printf("<-\tROOT");
		}

		level++;

		Formatted_Preorder_Tree_Walk( N->left, level );
		Formatted_Preorder_Tree_Walk( N->right, level );
	}

	if ( level == 0 )
	{
		printf("\n");
	}
	return;
}

void Print_Node( bst_node * x ) {
	printf("Node\n");

	if ( x == NULL )
	{
		printf("(NULL)\n");
		return;
	}
	printf("Key\t->\t%d\n\n", x->key);

	printf("\tParent\n");
	printf("\t");
	if ( x->parent != NULL )
	{
		printf("Key\t->\t%d\n", x->parent->key);
	}
	else
	{
		printf("(NULL)\n");
	}
	printf("\n");

	printf("\tLeft\n");
	printf("\t");
	if ( x->left != NULL )
	{
		printf("Key\t->\t%d\n", x->left->key);
	}
	else
	{
		printf("(NULL)\n");
	}
	printf("\n");

	printf("\tRight\n");
	printf("\t");
	if ( x->right != NULL )
	{
		printf("Key\t->\t%d\n", x->right->key);
	}
	else
	{
		printf("(NULL)\n");
	}

	printf("\n");
}

bst_node * bst_node_new( int key ) {
	bst_node * n = malloc( sizeof( bst_node ) );
	n->key = key;
	n->parent = NULL;
	n->left = NULL;
	n->right = NULL;

	return n;
}

bst_node * Tree_Search( bst_node * x, int key ) {
	if ( x == NULL || key == x->key )
	{
		return x;
	}

	if ( key < x->key )
	{
		return Tree_Search( x->left, key );
	}
	else
	{
		return Tree_Search( x->right, key );
	}
}

bst_node * Iterative_Tree_Search( bst_node * x, int key ) {

	while ( x != NULL && key != x->key )
	{
		if ( key < x->key )
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	return x;
}

/**
 * Binary Search Tree property guarantees that
 * we find the minimum value in the tree by iterating through
 * the "left" properties of each of the node.
 */
bst_node * Tree_Minimum( bst_node * x ) {
	while ( x->left != NULL )
	{
		x = x->left;
	}

	return x;
}

// Exercise 12.2-2
bst_node * Tree_Minimum_Recursive( bst_node * x ) {
	if ( x->left != NULL ) {
		return Tree_Minimum_Recursive( x->left );
	}

	return x;
}


/**
 * Binary Search Tree property guarantees that
 * we find the maximum value in the tree by iterating through
 * the "right" properties of each of the node.
 */

bst_node * Tree_Maximum( bst_node * x ) {
	while ( x->right != NULL )
	{
		x = x->right;
	}

	return x;
}

// Exercise 12.2-2
bst_node * Tree_Maximum_Recursive( bst_node * x ) {
	if ( x->right != NULL ) {
		return Tree_Maximum_Recursive( x->right );
	}

	return x;
}

/**
 * Finds the node with the smallest key greater
 * than x->key. Basically finds the next highest number
 * in a sorted order.
 */
bst_node * Tree_Successor( bst_node * x ) {
	if ( x->right != NULL )
	{
		return Tree_Minimum( x->right );
	}

	bst_node * y = malloc( sizeof( bst_node ) );
	y = x->parent;

	while ( y != NULL && x == y->right )
	{
		x = y;
		y = y->parent;
	}

	return y;
}

// Problem 12.2-3
bst_node * Tree_Predecessor( bst_node * x ) {
	if ( x->left != NULL )
	{
		return Tree_Maximum( x->left );
	}

	bst_node * y = malloc( sizeof( bst_node ) );
	y = x->parent;

	while ( y != NULL && x == y->left )
	{
		x = y;
		y = y->parent;
	}

	return y;
}

int Node_Compare( bst_node * x, bst_node * y ) {

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