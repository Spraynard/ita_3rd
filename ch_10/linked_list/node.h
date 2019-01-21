#ifndef _NODEH_
#define _NODEH_

/**
 * Implementation of a linked list node
 */

struct Node {
	int key;
	struct Node * prev;
	struct Node * next;
};

typedef struct Node Node;

Node * Init_Node( int key );
void Print_Node( Node * N );

#endif