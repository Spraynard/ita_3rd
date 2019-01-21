#ifndef _LISTH_
#define _LISTH_

#include "node.h"

struct Linked_List {
	Node * head;
};

typedef struct Linked_List List;

Node * List_Search( List * L, int k );
int List_Insert( List * L, Node * N );

#endif