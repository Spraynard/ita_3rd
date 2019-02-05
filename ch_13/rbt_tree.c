#include "rbt_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

void Formatted_Preorder_RB_Tree_Walk( rbt_tree * T, rbt_node * N, int level ) {
	int i;

	if ( ! RBT_Node_Compare( N, T->null ) )
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
		else
		{
			if ( RBT_Node_Compare( N, N->parent->left ) )
			{
				printf("<-\tLEFT");
			}
			else
			{
				printf("<-\tRIGHT");
			}
		}

		level++;

		Formatted_Preorder_RB_Tree_Walk( T, N->left, level );
		Formatted_Preorder_RB_Tree_Walk( T, N->right, level );
	}

	if ( level == 0 )
	{
		printf("\n");
	}
	return;
}

void RB_Tree_Print( rbt_tree * T ) {
	printf("Trying to print tree\n");
	Print_RBT_Node( T->root );
	Print_RBT_Node( T->null );
	Formatted_Preorder_RB_Tree_Walk( T, T->root, 0 );
	printf("\n");
}

void RBT_Insert_Fixup( rbt_tree * T, rbt_node * z )
{
	rbt_node * y = malloc( sizeof( rbt_node ) );

	// printf("Initial while loop\n");
	while ( z->parent->color == 1 )
	{
		printf("While Loooooooop\n");
		if ( RBT_Node_Compare( z->parent, z->parent->parent->left ) )
		{
			printf("RBT_Node_Compare( z->parent, z->parent->parent->left )\n");
			y = z->parent->parent->right;

			if ( y->color == 1 )
			{
				printf("Y->color == 1\n");
				z->parent->color = 0;
				y->color = 0;
				z->parent->parent->color = 1;
				z = z->parent->parent;
			}
			else if ( RBT_Node_Compare( z, z->parent->right ) )
			{
				printf("Y->color != 1\n");
				z = z->parent;
				Left_Rotate( T, z );
				z->parent->color = 0;
				z->parent->parent->color = 1;
				Right_Rotate(T, z->parent->parent);
			}
		}
		else
		{
			printf("NOT RBT_Node_Compare( z->parent, z->parent->parent->left )\n");
			y = z->parent->parent->right;

			if ( y->color == 1 )
			{
				printf("Y->color == 1\n");
				z->parent->color = 0;
				y->color = 0;
				z->parent->parent->color = 1;
				z = z->parent->parent;
			}
			else if ( RBT_Node_Compare( z, z->parent->right ) )
			{
				printf("Y->color != 1\n");
				z = z->parent;
				Right_Rotate( T, z );
				z->parent->color = 0;
				z->parent->parent->color = 1;
				Left_Rotate(T, z->parent->parent);
			}
		}
		sleep(1);
	}
	T->root->color = 0;
}


void RBT_Delete_Fixup( rbt_tree * T, rbt_node * x ) {
	rbt_node * w;

	while ( ! RBT_Node_Compare( x, T->root ) && x->color == 0 )
	{
		if ( RBT_Node_Compare( x, x->parent->left ) )
		{
			w = x->parent->right;

			if ( w->color == 1 )
			{
				w->color = 0;
				x->parent->color = 1;
				Left_Rotate(T, x->parent);
				w = x->parent->right;
			}
			if ( w->left->color == 0 && w->right->color == 0 )
			{
				w->color = 1;
				x = x->parent;
			}
			else if ( w->right->color == 0 )
			{
				w->left->color = 0;
				w->color = 1;
				Right_Rotate(T, w);
				w = x->parent->right;

				w->color = x->parent->color;
				x->parent->color = 0;
				w->right->color = 0;
				Left_Rotate(T, x->parent);
				x = T->root;
			}
		}
		else
		{
			w = x->parent->left;

			if ( w->color == 1 )
			{
				w->color = 0;
				x->parent->color = 1;
				Left_Rotate(T, x->parent);
				w = x->parent->left;
			}
			if ( w->right->color == 0 && w->left->color == 0 )
			{
				w->color = 1;
				x = x->parent;
			}
			else if ( w->left->color == 0 )
			{
				w->left->color = 0;
				w->color = 1;
				Right_Rotate(T, w);
				w = x->parent->left;

				w->color = x->parent->color;
				x->parent->color = 0;
				w->left->color = 0;
				Left_Rotate(T, x->parent);
				x = T->root;
			}
		}
	}
	x->color = 0;
}

void RBT_Insert( rbt_tree * T, rbt_node * z ) {
	rbt_node * y = T->null;
	rbt_node * x = T->root;

	// printf("Starting while loop in Insert\n");
	while ( ! RBT_Node_Compare( x, T->null ) )
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

	// printf("Setting insert node parent to y\n");
	z->parent = y;

	if ( RBT_Node_Compare( y, T->null ) )
	{
		T->root = z;
	}
	else if ( z->key < y->key )
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}

	z->left = T->null;
	z->right = T->null;
	z->color = 1;

	// printf("Handling any issues with insertion\n");
	RBT_Insert_Fixup( T, z );
}
void RBT_Transplant( rbt_tree * T, rbt_node * u, rbt_node * v ) {

	if ( RBT_Node_Compare( u->parent, T->null ) )
	{
		T->root = v;
	}
	else if ( RBT_Node_Compare( u, u->parent->left ) )
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}

	v->parent = u->parent;
}

void RBT_Delete( rbt_tree * T, rbt_node * z ) {
	rbt_node * y = z;
	rbt_node * x = malloc( sizeof( rbt_node ) );
	int y_original_color = y->color;

	if ( RBT_Node_Compare( z->left, T->null ) )
	{
		x = z->right;
		RBT_Transplant(T, z, z->right);
	}
	else if ( RBT_Node_Compare( z->right, T->null ) )
	{
		x = z->left;
		RBT_Transplant(T, z, z->left);
	}
	else
	{
		y = RBT_Minimum( z->right );
		y_original_color = y->color;
		x = y->right;

		if ( RBT_Node_Compare( y->parent, z ) )
		{
			x->parent = y;
		}
		else
		{
			RBT_Transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		RBT_Transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if ( y_original_color == 0 )
	{
		RBT_Delete_Fixup( T, x );
	}
}

void Left_Rotate( rbt_tree * T, rbt_node * x ) {
	rbt_node * y = x->right; // set y
	x->right = y->left; // turn y's left subtree into x's right subtree

	if ( !RBT_Node_Compare(y->left, T->null) )
	{
		y->left->parent = x;
	}

	y->parent = x->parent; // link x's parent to y

	if ( RBT_Node_Compare(x->parent, T->null) )
	{
		T->root = y;
	}
	else if ( RBT_Node_Compare( x, x->parent->left) )
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}

	y->left = x; // put x on y's left
	x->parent = y;
}

void Right_Rotate( rbt_tree * T, rbt_node * x ) {
	rbt_node * y = x->left; // set y;
	x->left = y->right;

	if ( !RBT_Node_Compare(y->right, T->null) )
	{
		y->right->parent = x;
	}

	y->parent = x->parent;

	if ( RBT_Node_Compare(x->parent, T->null) )
	{
		T->root = y;
	}
	else if ( RBT_Node_Compare( x, x->parent->right) )
	{
		x->parent->right = y;
	}
	else
	{
		x->parent->left = y;
	}

	y->right = x; // put x on y's right
	x->parent = y;
}

int Tree_Size( rbt_tree * T );

rbt_tree * rbt_tree_new() {
	printf("%s\n", "We are creating a new tree");
	rbt_tree * T = malloc( sizeof( rbt_tree ) );
	T->null = rbt_node_new( INT_MIN );
	T->root = T->null;
	return T;
}