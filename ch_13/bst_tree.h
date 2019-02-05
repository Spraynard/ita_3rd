#include "bst_node.h"

#ifndef BST_TREEH
#define BST_TREEH

typedef struct {
	bst_node * root;
} bst_tree;

void Tree_Print( bst_tree * T );

void Tree_Insert( bst_tree * T, bst_node * z );

void Tree_Delete( bst_tree * T, bst_node * z );

void Transplant( bst_tree * T, bst_node * u, bst_node * v );

int Tree_Size( bst_tree * T );

bst_tree * bst_tree_new();
#endif