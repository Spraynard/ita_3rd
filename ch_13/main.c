#include "rbt_node.c"
#include "rbt_tree.c"
#include <stdio.h>
#include <unistd.h>
#include <time.h>

/**
 * RED - BLACK Trees
 *
 * Description:
 * Binary search tree with one extra bit of "color"
 * storage per node.
 *
 * By constraining the node colrs on any simple path from
 * root to leaf, red-black trees ensure that no such path
 * is more than twice as long as any other, so the tree is approxiamtely balanced.
 *
 * Red-Black Properties
 * 1. Every Node is either red ( 1 ) or black ( 0 )
 * 2. The Root node of our tree is black
 * 3. Every Leaf ( NULL ) is black
 * 4. If a node is red, then both its children are black
 * 5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
 */

int main() {
	srand(time(NULL));
	// A
	rbt_tree * tree_a = rbt_tree_new();
	int array_a[6] = {41, 38, 31, 12, 19, 8};
	int a_length = 6;
	/**
	 * As a first test, I'll attempt to send
	 * a sorted array of inputs into our tree to
	 * test its self, balancing behavior
	 */
	for ( int i = 1; i < 5000; i++ )
	{
		rbt_node * node_a = rbt_node_new( i );
		RBT_Insert( tree_a, node_a );
	}

	// RB_Tree_Print( tree_a );
	int i = 0;

	while ( i < 1000 )
	{
		int randomNumber = rand() % 5000;
		printf("Random Number: %d\n", randomNumber);
		// Search for a random number
		rbt_node * searchedNodeA = RBT_Search( tree_a, tree_a->root, randomNumber );

		// If our searched node is null, it was already deleted
		if ( searchedNodeA == tree_a->null )
		{
			continue;
		}
		Print_RBT_Node(searchedNodeA);
		RBT_Delete( tree_a, searchedNodeA);
		i++;
	}
	printf("Printing Tree");
	RB_Tree_Print( tree_a );
}