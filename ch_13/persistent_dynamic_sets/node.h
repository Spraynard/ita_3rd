#ifndef _NODEH_
#define _NODEH_

struct node {
	struct node * left;
	struct node * right;
	int value;
};

struct node * node_new( int value );
struct node * node_copy( struct node * N );

#endif