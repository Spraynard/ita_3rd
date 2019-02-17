#ifndef _RBTNODEH_
#define _RBTNODEH_

typedef struct rbt_node rbt_node;

struct rbt_node {
	int key;
	rbt_node * parent;
	rbt_node * left;
	rbt_node * right;
	unsigned color: 1; // 0 - Black, 1 - Red
};

struct rbt_node T_NIL_Node;
rbt_node * T_Nil = &T_NIL_Node;

void Print_RBT_Node( rbt_node * x );

int isNullNode( rbt_node * x );

int RBT_Node_Compare( rbt_node * x, rbt_node * y );

rbt_node * RBT_Minimum( rbt_node * x );

rbt_node * rbt_node_new( int value );

#endif