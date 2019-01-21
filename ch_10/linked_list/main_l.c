#include "list.c"
#include "node.c"
#include "node.h"
#include <stddef.h>
#include <stdio.h>

int main() {
	List L = Init_List();

	Node * n1 = Init_Node( 5 );
	Node * n2 = Init_Node( 7 );
	Node * n3 = Init_Node( 10 );
	Node * n4 = Init_Node( 15 );
	Node * n5 = Init_Node ( 8 );
	Node * n6 = Init_Node( 9 );

	List_Insert( &L, n1 );
	List_Insert( &L, n2 );
	List_Insert( &L, n3 );
	List_Insert( &L, n4 );
	List_Insert( &L, n5 );
	List_Insert( &L, n6 );

	Print_List( &L );

	List_Search( &L, 7 );
	List_Search( &L, 5 );

	List_Delete( &L, n4 );

	Print_List( &L );

	List_Delete_Key( &L, 9 );

	Print_List( &L );
}