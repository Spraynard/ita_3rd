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

/**
 * Binary Search Tree property guarantees that
 * we find the minimum value in the tree by iterating through
 * the "left" properties of each of the node.
 */
rbt_node * RBT_Minimum( rbt_node * x ) {
	printf("RBT Minimum Start\n");
	Print_RBT_Node( x );
	while ( x->left != NULL )
	{
		x = x->left;
	}

	return x;
}

rbt_node * RBT_Search( rbt_tree * T, rbt_node * x, int key ) {
	if ( x == T_Nil || key == x->key )
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

// int RBT_Node_Compare( rbt_node * x, rbt_node * y ) {

// 	printf("Comparing Nodes: \n");
// 	Print_RBT_Node( x );
// 	Print_RBT_Node( y );
// 	if ( isNullNode( x ) && isNullNode( y ) )
// 	{
// 		return 1;
// 	}

// 	// Cases where we're not equal.
// 	if (
// 		( isNullNode( x ) && ! isNullNode( y ) ) ||
// 		( ! isNullNode( x ) && isNullNode( y ) ) ||
// 		( ( ! isNullNode( x ) && ! isNullNode( y ) ) && x->key != y->key  )
// 	)
// 	{
// 		return 0;
// 	}

// 	RBT_Node_Compare( x->left, y->left );

// 	RBT_Node_Compare( x->right, y->right );

// 	return 0;
// }
