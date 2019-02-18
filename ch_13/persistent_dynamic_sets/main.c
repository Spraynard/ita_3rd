#include "node.c"
#include "tree.c"

int main() {
	struct tree * t1 = tree_new();

	struct tree * t2 = tree_insert(t1, 4);
	struct tree * t3 = tree_insert(t2, 3);
	struct tree * t4 = tree_insert(t3, 2);
	struct tree * t5 = tree_insert(t4, 8);
	struct tree * t6 = tree_insert(t5, 7);
	struct tree * t7 = tree_insert(t6, 10);

	printf("Tree 1\n");
	tree_print( t1->root );
	printf("\n\n");

	printf("Tree 2\n");
	tree_print( t2->root );
	printf("\n\n");

	printf("Tree 3\n");
	tree_print( t3->root );
	printf("\n\n");

	printf("Tree 4\n");
	tree_print( t4->root );
	printf("\n\n");

	printf("Tree 7\n");
	tree_print( t7->root );
	printf("\n\n");


	struct tree * t8 = tree_delete(t7, 8);
	printf("Tree 8: Deletion\n");
	tree_print( t8->root );
	printf("\n\n");

	struct tree * t9 = tree_insert(t8, 9);
	printf("Tree 9: Insertion after deletion\n");
	tree_print( t9->root );
	printf("\n\n");

	struct tree * t10 = tree_delete(t9, 10);
	printf("Tree 10: Deletion After Insertion\n");
	tree_print( t10->root );
	printf("\n\n");
}