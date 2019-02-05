#ifndef BST_NODEH
#define BST_NODEH

typedef struct BST_NODE bst_node;

struct BST_NODE {
	int key;
	bst_node * parent;
	bst_node * left;
	bst_node * right;
};

void Inorder_Tree_Walk( bst_node * x );
void Formatted_Preorder_Tree_Walk( bst_node * N, int level );

bst_node * bst_node_new( int key );
bst_node * Tree_Search( bst_node * x, int key );
bst_node * Iterative_Tree_Search( bst_node * x, int key );
bst_node * Tree_Minimum( bst_node * x );
bst_node * Tree_Maximum( bst_node * x );
bst_node * Tree_Successor( bst_node * x );
bst_node * Tree_Predecessor( bst_node * x );

int Node_Compare( bst_node * x, bst_node * y );

#endif