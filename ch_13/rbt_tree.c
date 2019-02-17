#include "rbt_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

void Formatted_Preorder_RB_Tree_Walk( rbt_tree * T, rbt_node * N, int level ) {
	int i;

	if ( N != T_Nil ) //! RBT_Node_Compare( N, T->null ) )
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
			if ( N->key == N->parent->left->key ) //RBT_Node_Compare( N, N->parent->left ) )
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
	Formatted_Preorder_RB_Tree_Walk( T, T->root, 0 );
	printf("\n");
}

void RBT_Insert( rbt_tree * T, rbt_node * z ) {
	rbt_node * y = T->null;
	rbt_node * x = T->root;

	while ( x != T->null )
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

	if ( y == T->null )
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

	RBT_Insert_Fixup( T, z );
}

void RBT_Insert_Fixup( rbt_tree * T, rbt_node * z )
{
	rbt_node * y = malloc( sizeof( rbt_node ) );

	while ( z->parent->color == 1 )
	{
		if ( z->parent->key == z->parent->parent->left->key )// RBT_Node_Compare( z->parent, z->parent->parent->left ) )
		{
			y = z->parent->parent->right;

			if ( y->color == 1 )
			{
				z->parent->color = 0;
				y->color = 0;
				z->parent->parent->color = 1;
				z = z->parent->parent;
			}
			else
			{
				if ( z->key == z->parent->right->key )//RBT_Node_Compare( z, z->parent->right ) )
				{
					z = z->parent;
					Left_Rotate( T, z );
				}

				z->parent->color = 0;
				z->parent->parent->color = 1;
				Right_Rotate(T, z->parent->parent);
			}
		}
		else
		{
			y = z->parent->parent->left;
			if ( y->color == 1 )
			{
				z->parent->color = 0;
				y->color = 0;
				z->parent->parent->color = 1;
				z = z->parent->parent;
			}
			else
			{
				if ( z->key == z->parent->left->key )// RBT_Node_Compare( z, z->parent->left ) )
				{
					z = z->parent;
					Right_Rotate( T, z );
				}

				z->parent->color = 0;
				z->parent->parent->color = 1;
				Left_Rotate(T, z->parent->parent);
			}
		}
	}
	T->root->color = 0;
}

void RBT_Delete_Fixup( rbt_tree * T, rbt_node * x ) {
	rbt_node * w;

	while ( x->key != T->root->key && x->color == 0 )//! RBT_Node_Compare( x, T->root ) && x->color == 0 )
	{
		if ( x->key == x->parent->left->key )//RBT_Node_Compare( x, x->parent->left ) )
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
			else
			{
				if ( w->right->color == 0 )
				{
					w->left->color = 0;
					w->color = 1;
					Right_Rotate(T, w);
					w = x->parent->right;
				}
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
				Right_Rotate(T, x->parent);
				w = x->parent->left;
			}
			if ( w->left->color == 0 && w->right->color == 0 )
			{
				w->color = 1;
				x = x->parent;
			}
			else
			{
				if ( w->left->color == 0 )
				{
					w->right->color = 0;
					w->color = 1;
					Left_Rotate(T, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = 0;
				w->left->color = 0;
				Right_Rotate(T, x->parent);
				x = T->root;
			}
		}
	}
	x->color = 0;
}

void RBT_Delete( rbt_tree * T, rbt_node * z ) {
	rbt_node * y = z;
	rbt_node * x = malloc( sizeof( rbt_node ) );

	int y_original_color = y->color;

	printf("Deleting\n");
	if ( z->left == T->null || z->left == NULL )// isNullNode( z->left ) )
	{
		printf("Z->left == T->null\n");
		x = z->right;
		RBT_Transplant(T, z, z->right);
	}
	else if ( z->right == T->null || z->right == NULL)//isNullNode( z->right ) )
	{
		printf("Z->right == T->null\n");
		x = z->left;
		RBT_Transplant(T, z, z->left);
	}
	else
	{
		printf("Children nodes are not null\n");
		y = RBT_Minimum( z->right );
		y_original_color = y->color;
		x = y->right;

		printf("making it to rbt_node_compare\n");
		Print_RBT_Node( y->parent );
		Print_RBT_Node( z );
		if ( y->parent->key == z->key )//RBT_Node_Compare( y->parent, z ) )
		{
			printf("y->paretn == z\n");
			x->parent = y;
		}
		else
		{
			printf("y->parent != z\n");
			RBT_Transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		printf("Making it to rbt_transplant\n");
		RBT_Transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if ( y_original_color == 0 )
	{
		printf("Delete Fixup\n");
		RBT_Delete_Fixup( T, x );
	}
}

void RBT_Transplant( rbt_tree * T, rbt_node * u, rbt_node * v ) {
	printf("First Compare outside any statements\n");
	Print_RBT_Node(u);
	Print_RBT_Node(v);
	if ( u->parent == T->null || u->parent == NULL )// isNullNode( u->parent ) )
	{
		printf("First Compare\n");
		T->root = v;
	}
	else if ( u->key == u->parent->left->key ) //RBT_Node_Compare( u, u->parent->left ) )
	{
		printf("Second Compare\n");
		u->parent->left = v;
	}
	else
	{
		printf("First and second compare are not equal\n");
		u->parent->right = v;
	}

	printf("Successfully making it through, setting v->parent == u->parent\n");
	v->parent = u->parent;
}

void Left_Rotate( rbt_tree * T, rbt_node * x ) {
	rbt_node * y = x->right; // set y
	x->right = y->left; // turn y's left subtree into x's right subtree

	if ( y->left != T->null )//! isNullNode( y->left ) )
	{
		y->left->parent = x;
	}

	y->parent = x->parent; // link x's parent to y

	if ( x->parent == T->null )// isNullNode( x->parent ) )
	{
		T->root = y;
	}
	else if ( x->key == x->parent->left->key )// RBT_Node_Compare( x, x->parent->left) )
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

	if ( y->right != T->null )// ! isNullNode( y->right ) )
	{
		y->right->parent = x;
	}

	y->parent = x->parent;

	if ( x->parent == T->null )// isNullNode( x->parent ) )
	{
		T->root = y;
	}
	else if ( x->key == x->parent->right->key )// RBT_Node_Compare( x, x->parent->right) )
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
	T->null = T_Nil;
	T->root = T->null;
	return T;
}