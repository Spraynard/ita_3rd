#include "bst_node.c"
#include "bst_tree.c"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

int inArray( int * array, int key, int size ) {
	for ( int i = 0; i < size; i++ )
	{
		if ( array[i] == key )
		{
			return 1;
		}
	}
	return 0;
}

int main() {
	srand(time(NULL));
	bst_node * a = bst_node_new( 6 );
	bst_node * b = bst_node_new( 5 );
	bst_node * c = bst_node_new( 7 );
	bst_node * d = bst_node_new( 2 );
	bst_node * e = bst_node_new( 5 );
	bst_node * f = bst_node_new( 8 );

	a->left = b;
	a->right = c;
	b->parent = a;
	c->parent = a;

	b->left = d;
	b->right = e;
	d->parent = b;
	e->parent = b;

	c->right = f;
	f->parent = c;

	printf("\nSearching\n");
	bst_node * searched = Tree_Search( a, 8 );
	Print_Node( searched );

	printf("\nSearching Again\n");
	bst_node * searched_2 = Iterative_Tree_Search( a, 6 );
	Print_Node( searched_2 );

	printf("\nSearching for Minimum\n");
	bst_node * minimum = Tree_Minimum( a );
	Print_Node( minimum );

	printf("\nSearching for Minimum Recursively\n");
	bst_node * minimum_r = Tree_Minimum_Recursive( a );
	Print_Node( minimum_r );

	printf("\nSearching for Maximum\n");
	bst_node * maximum = Tree_Maximum( a );
	Print_Node( maximum );

	printf("\nSearching for Maximum Recursively\n");
	bst_node * maximum_r = Tree_Maximum_Recursive( a );
	Print_Node( maximum_r );

	printf("\nSearching for Successor\n");
	bst_node * successor = Tree_Successor( d );
	Print_Node( successor );

	printf("\nSearching for Predecessor\n");
	bst_node * predecessor = Tree_Predecessor( a );
	Print_Node( predecessor );

	printf("Inorder\t->\t");
	Inorder_Tree_Walk( a );
	printf("\n");

	printf("Preorder\t->\t");
	Preorder_Tree_Walk( a );
	printf("\n");

	printf("Postorder\t->\t");
	Postorder_Tree_Walk( a );
	printf("\n");

	bst_tree * T = malloc( sizeof( bst_tree ) );
	T->root = a;

	Tree_Print( T );

	int test_set[500];
	int count = 0;
	int test_num;

	for ( int z = 0; z < 500; z++ )
	{
		test_num = rand() % 5000;

		while ( inArray( test_set, test_num, count ) )
		{
			test_num = rand() % 5000;
		}

		test_set[z] = test_num;

		count++;
	}

	bst_tree * test_set_tree = bst_tree_new();
	bst_node * test_set_node;

	for ( int i = 0; i < 500; i++ ) {
		test_set_node = bst_node_new( test_set[i] );
		Tree_Insert( test_set_tree, test_set_node );
	}

	Tree_Print( test_set_tree );

	for ( int j = 250; j < 500; j++ ) {
		test_set_node = Tree_Search( test_set_tree->root, test_set[j] );
		Tree_Delete( test_set_tree, test_set_node );
	}

	// Check if deleted
	// Our tree search will return null if that's the case
	for ( int k = 250; k < 500; k++ ) {
		test_set_node = Tree_Search( test_set_tree->root, test_set[k] );
		assert( test_set_node == NULL );
	}

	Tree_Print( test_set_tree );
/*
Exercises
12.2-1
Suppose that we have numbers between 1 and 1000 in a binary search tree,
and we want to search for the number 363. Which of the following sequences could not be the sequence of nodes examined?
a. 2,252,401,398,330,344,397,363.
b. 924, 220, 911, 244, 898, 258, 362, 363.
c. 925, 202, 911, 240, 912, 245, 363.
d. 2,399,387,219,266,382,381,278,363.
e. 935, 278, 347, 621, 299, 392, 358, 363.
 */

// Solution
// C because we run into 912 from 911 even though we
// 	go through the left node of 911.
// D because we run to the 299 node from 347 even though we take
// 	our right node from 347
}