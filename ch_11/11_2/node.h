#include "ht_item.h"

#ifndef _NODEH_
#define _NODEH_


/**
 * Implementation of a linked list node
 */

typedef struct Node Node;

// Extension of a linked-list node in which instead of attaching a key->value to the node, we attach an ht_item
// which contains key->value information once stored in a hash table.
struct Node {
	ht_item * item;
	Node * prev;
 	Node * next;
};

Node * Init_Node( char * key, int value );

void Delete_Node( Node * N );

void Print_Node( Node * N );

#endif