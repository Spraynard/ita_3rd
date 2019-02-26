#ifndef _RBTNODEH_
#define _RBTNODEH_

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct rbt_node rbt_node;

struct rbt_node {
	int key;
	rbt_node * parent;
	rbt_node * left;
	rbt_node * right;
	unsigned color: 1; // 0 - Black, 1 - Red
};

void Print_RBT_Node( rbt_node * x );

int isNullNode( rbt_node * x );

int RBT_Node_Compare( rbt_node * x, rbt_node * y );

rbt_node * rbt_node_new( int value );

#endif