#ifndef _BST_PERSISTH_
#define _BST_PERSISTH_

#include "node.h"

struct tree {
	struct node * root;
};

struct tree * tree_insert( struct tree * T, int key );

#endif