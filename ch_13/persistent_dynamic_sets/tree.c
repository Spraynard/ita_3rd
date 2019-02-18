#include "tree.h"
#include "node.h"
#include "stdlib.h"
#include "stdio.h"

struct tree * tree_new() {
	struct tree * x = malloc( sizeof( struct tree ) );
	x->root = NULL;

	return x;
}

void tree_print( struct node * n ) {
	if ( n == NULL )
	{
		return;
	}
	printf("\nNode\n");
	printf("Value: %d", n->value);
	tree_print( n->left );
	tree_print( n->right );
}

struct tree * tree_insert( struct tree * T, int key )
{
	struct node * z = node_new( key );
	struct node * new_root = node_copy(T->root);
	struct node * y = NULL;
	struct node * x = new_root;
	struct tree * new_tree = tree_new();

	while ( x != NULL )
	{
		y = x;

		if ( z->value < x->value )
		{
			x = node_copy(x->left);
			y->left = x;
		}
		else
		{
			x = node_copy(x->right);
			y->right = x;
		}
	}

	if ( y == NULL )
	{
		new_root = z; // tree T empty
	}
	else if ( z->value < y->value )
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}

	new_tree->root = new_root;
	return new_tree;
};

struct tree * tree_delete( struct tree * T, int key ) {
	struct tree * new_tree = tree_new();
	struct node * new_root = node_copy( T->root );

	struct node * y = NULL;
	struct node * x = new_root;
	
	while ( x != NULL && x->value != key )
	{
		y = x;

		if ( key < x->value )
		{
			x = node_copy(x->left);
			y->left = x;
		}
		else
		{
			x = node_copy(x->right);
			y->right = x;
		}
	}

	// Should now be at our key we want deleted.
	if ( x == NULL )
	{
		return T;
	}

	// If no children
	if ( x->left == NULL && x->right == NULL )
	{
		x = NULL;
	}
	// Next two are for if only one child is filled
	else if( x->left == NULL )
	{
		x->value = x->right->value;
		x->left = x->right->left;
		x->right = x->right->right;
	}
	else if ( x->right == NULL )
	{
		x->value = x->left->value;
		x->right = x->left->right;
		x->left = x->left->left;
	}
	// Both children filled
	else
	{
		x->value = x->right->value;
		x->right = x->right->right;
	}

	new_tree->root = new_root;
	return new_tree;
}
