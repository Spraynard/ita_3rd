#include "node.h"
#include "list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void Print_List( List * L ) {
	Node * temp = L->head;
	while ( temp != NULL )
	{
		printf("%d ", temp->key );
		temp = temp->next;
	}

	printf("\n");
}

List Init_List() {
	List * L = ( List * ) malloc( sizeof( List ) );
	L->head = NULL;

	return * L;
}

Node * List_Search( List * L, int k ) {
	Node * x = L->head;
	int indexCount = 0;

	while ( x != NULL && x->key != k )
	{
		x = x->next;
		indexCount++;
	}

	printf("Node Found @ Index: %d\n", indexCount);
	return x;
}

int List_Insert( List * L, Node * x ) {
	x->next = L->head;

	if ( L->head != NULL )
	{
		L->head->prev = x;
	}

	L->head = x;
	x->prev = NULL;

	return 1;
}

void List_Delete( List * L, Node * N ) {
	if ( N->prev != NULL )
	{
		N->prev->next = N->next;
	}
	else
	{
		L->head = N->next;
	}

	if ( N->next != NULL )
	{
		N->next->prev = N->prev;
	}
}

void List_Delete_Key( List * L, int key ) {
	Node * delete = List_Search( L, key );
	List_Delete( L, delete );
}