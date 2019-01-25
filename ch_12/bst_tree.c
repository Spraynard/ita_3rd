#include "bst_tree.h"
#include "bst_node.h"
#include <stdlib.h>
#include <stdio.h>

bst_tree * bst_tree_new() {
	bst_tree * n = malloc( sizeof( bst_tree ) );
	n->root = NULL;

	return n;
}

void Tree_Print( bst_tree * T ) {
	Formatted_Preorder_Tree_Walk( T->root, 0 );
	printf("\n");
}

void Size_Tree( bst_node * N, int count ) {
	while ( N ) {
		count++;
		Size_Tree( N->left, count);
		Size_Tree( N->right, count);
	}
}

int Tree_Size( bst_tree * T ) {
	int count = 0;
	Size_Tree( T->root, count );
	return count;
}

void Tree_Insert_Recursive( bst_tree * T, bst_node * insert, bst_node * path, bst_node * trailing ) {

	// Insert case if Tree is empty.
	if ( ! T->root )
	{
		T->root = insert;
		return;
	}

	// Initialize our path
	if ( ! path && ! trailing )
	{
		path = T->root;
	}

	// Path Traversal Recursive Case
	if ( path )
	{
		trailing = path;

		if ( insert->key < path->key )
		{
			Tree_Insert_Recursive( T, insert, path->left, trailing );
		}
		else
		{
			Tree_Insert_Recursive( T, insert, path->right, trailing );
		}
	}

	// Insert Case if we're at the end of a tree search
	if ( ! path && trailing )
	{
		if ( insert->key < trailing->key )
		{
			trailing->left = insert;
		}
		else
		{
			trailing->right = insert;
		}

		insert->parent = trailing;
	}

	return;
}

void Tree_Insert( bst_tree * T, bst_node * z ) {
	bst_node * y = malloc( sizeof( bst_node ) );
	bst_node * x = malloc( sizeof( bst_node ) );

	y = NULL;
	x = T->root;

	while ( x != NULL )
	{
		y = x;

		if ( z->key < x->key )
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	z->parent = y;

	if ( y == NULL )
	{
		T->root = z; // tree T empty
	}
	else if ( z->key < y->key )
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
}

/*
	Replaces subtree rooted at node 'u' with the subtree rooted at node v
	Node u's paren't becomes node v's parent, and u's parent has v as its appropriate child
 */
void Transplant( bst_tree * T, bst_node * u, bst_node * v ) {
	// Case if we're transplanting the root node
	if ( ! u->parent )
	{
		T->root = v;
	}
	else if ( Node_Compare( u, u->parent->left ) )
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}

	if ( v )
	{
		v->parent = u->parent;
	}
}

void Tree_Delete( bst_tree * T, bst_node * z ) {
	// Z has no left child
	if ( z->left == NULL )
	{
		Transplant( T, z, z->right );
	}
	// Z has no right child
	else if ( z->right == NULL )
	{
		Transplant( T, z, z->left );
	}
	// Z has two children
	else
	{
		bst_node * y = malloc( sizeof( bst_node ) );
		y = Tree_Minimum( z->right);//Tree_Successor( z );

		if ( ! Node_Compare( y->parent, z ) )
		{
			Transplant( T, y, y->right );
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant( T, z, y );
		y->left = z->left;
		y->left->parent = y;
	}
}