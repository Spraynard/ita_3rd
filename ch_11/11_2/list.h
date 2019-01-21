#ifndef _LISTH_
#define _LISTH_

#include "node.h"

struct Linked_List {
	Node * head;
};

typedef struct Linked_List List;

List * Init_List();

Node * List_Search( List * L, char * k );
int List_Search_Node( List * L, Node * N );

int List_Insert( List * L, Node * N );

void Print_List( List * L );
void List_Delete( List * L, Node * N );
void List_Delete_Key( List * L, char * key );
void Delete_List( List * L );

#endif