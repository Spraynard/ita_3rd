#include "node.h"
#include "list.h"
#include "ht_item.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print_List( List * L ) {

	Node * temp;

	if ( L == NULL ) {
		printf("( NULL )");
		temp = NULL;
	}
	else
	{
		temp = L->head;
	}

	while ( temp != NULL )
	{
		Print_Item( temp->item );
		temp = temp->next;

		if ( temp != NULL )
		{
			printf("->\t");
		}
	}

	printf("\n\n");
}

List * Init_List() {
	List * L = ( List * ) malloc( sizeof( List ) );
	L->head = NULL;

	return L;
}

// Used to delete a LINKED_LIST struct

void Delete_List( List * L ) {

	Node * temp = malloc( sizeof( Node * ) );
	temp = L->head;

	// Get to the end node of the list.
	while ( temp->next ) {
		temp = temp->next;
	}

	// Now that we're at the end, procedurally delete
	// each node as we run back.
	while ( temp->prev ) {
		temp = temp->prev;
		Delete_Node( temp->next );
	}

	// Should be at the head now.
	Delete_Node( L->head );

	L->head = NULL;
}

Node * List_Search( List * L, char * k ) {

	Node * x = malloc( sizeof ( Node * ) );
	x = L->head;
	int indexCount = 0;

	// Comparint the item's ( ht_item ) key with the given key, k.
	while ( x != NULL && strcmp( x->item->key, k ) != 0 )
	{
		x = x->next;
		indexCount++;
	}

	return x;
}

/**
 * Returns a value on whether or not we have
 * a similar node in the list.
 * @param  L - List to search
 * @param  N - Node to compare to List Nodes
 * @return   - 0: Node NOT in list
 *             1: Node in list
 */
int List_Search_Node( List * L, Node * N ) {
	Node * Ns = List_Search( L, N->item->key );

	if ( Ns == NULL ) {
		return 0;
	}

	return 1;
}

/**
 * Inserts Node x at the head of Linked_List L
 */
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

/**
 * Deletes Node N in List L.
 * Does nothing if such a node is not available in list.
 */
void List_Delete( List * L, Node * N ) {

	// Check to see if Node, N is part of List L.
	if ( ! List_Search_Node( L, N ) )
	{
		return;
	}

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

void List_Delete_Key( List * L, char * key ) {

	Node * delete = List_Search( L, key );
	List_Delete( L, delete );
}
