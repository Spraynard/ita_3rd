#include "rbt_node.h"

#ifndef RBT_TREEH
#define RBT_TREEH

typedef struct {
	rbt_node * root;
	rbt_node * null;
} rbt_tree;

void RBT_Insert( rbt_tree * T, rbt_node * z );
void RBT_Insert_Fixup( rbt_tree * T, rbt_node * z );

void Left_Rotate( rbt_tree * T, rbt_node * x );

void Right_Rotate( rbt_tree * T, rbt_node * x );

void RB_Delete_Fixup( rbt_tree * T, rbt_node * z );
void RBT_Delete( rbt_tree * T, rbt_node * z );

void RBT_Transplant( rbt_tree * T, rbt_node * u, rbt_node * v );

int Tree_Size( rbt_tree * T );

rbt_node * RBT_Minimum( rbt_tree * T, rbt_node * x );

rbt_tree * rbt_tree_new();
#endif