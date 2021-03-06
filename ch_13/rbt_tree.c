#include "rbt_tree.h"

rbt_node NIL;
rbt_node * NIL_Node = &NIL;

void Formatted_Preorder_RB_Tree_Walk( rbt_tree * T, rbt_node * N, int level ) {
	int i;

	if ( N != T->null ) //! RBT_Node_Compare( N, T->null ) )
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

		if ( N->color == 0 )
		{
			printf("\tBLACK");
		}
		else
		{
			printf("\tRED");
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
	printf("Tree Black Height:\t%d", T->bh);
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
			y = z->parent->parent->left; // Uncle Node

			// If uncle node is red, change ancestral colors
			if ( y->color == 1 )
			{
				// Adding in a black node here
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
	if ( T->root->color == 1 )
	{
		T->bh++;
	}
	T->root->color = 0;
}

void RBT_Delete_Fixup( rbt_tree * T, rbt_node * x ) {
	rbt_node * w;

	while ( ( x->key != T->root->key ) && x->color == 0 )//! RBT_Node_Compare( x, T->root ) && x->color == 0 )
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
		if ( x->key == T->root->key )
		{
			T->bh--;
		}
	}
	x->color = 0;
}

void RBT_Delete( rbt_tree * T, rbt_node * z ) {
	rbt_node * y = z;
	rbt_node * x = malloc( sizeof( rbt_node ) );

	int y_original_color = y->color;

	if ( z->left == T->null )// isNullNode( z->left ) )
	{
		x = z->right;
		RBT_Transplant(T, z, z->right);
	}
	else if ( z->right == T->null )//isNullNode( z->right ) )
	{
		x = z->left;
		RBT_Transplant(T, z, z->left);
	}
	else
	{
		y = RBT_Minimum( T, z->right );
		y_original_color = y->color;
		x = y->right;

		if ( y->parent->key == z->key )//RBT_Node_Compare( y->parent, z ) )
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

void RBT_Transplant( rbt_tree * T, rbt_node * u, rbt_node * v ) {
	if ( u->parent == T->null )// isNullNode( u->parent ) )
	{
		T->root = v;
	}
	else if ( u->key == u->parent->left->key ) //RBT_Node_Compare( u, u->parent->left ) )
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}

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

/**
 * Binary Search Tree property guarantees that
 * we find the minimum value in the tree by iterating through
 * the "left" properties of each of the node.
 */
rbt_node * RBT_Minimum( rbt_tree * T, rbt_node * x ) {
	while ( x->left != T->null )
	{
		x = x->left;
	}

	return x;
}

int Tree_Size( rbt_tree * T );

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

rbt_tree * rbt_tree_new() {
	printf("%s\n", "We are creating a new tree");
	rbt_tree * T = malloc( sizeof( rbt_tree ) );
	T->null = NIL_Node;
	T->root = T->null;
	T->bh = 0;
	return T;
}

void rbt_node_free(rbt_tree * T, rbt_node * N ) {
	if ( N == T->null )
	{
		return;
	}

	rbt_node_free(T, N->left);
	rbt_node_free(T, N->right);

	free(N);
	N = NULL;
	return;
}
void rbt_tree_free( rbt_tree * T ) {
	// Free all the nodes first and then free our tree;
	// Which means do a postorder traversal.
	rbt_node_free(T, T->root );
	free(T);

	T = NULL;

	return;
}