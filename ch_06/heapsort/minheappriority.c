#include "heap.h"
#include "minheap.c"
#include <limits.h>
#include <stdlib.h>
// Max Heap Priority Queue Implementation Functions

// Assumes our Heap's array is already max heaped.
int Heap_Minimum( Heap H ) {
	return H.array[0];
}


int Heap_Extract_Min( Heap *H ) {
	int min;

	if ( H->size < 1 )
	{
		printf("Heap Underflow. Not enough elements in your heap");
		exit( 1 );
	}
	// Obtaining the min number
	min = Heap_Minimum( *H );

	// Removing that min number
	H->array[0] = H->array[H->size--];

	// Heapifying the array based on the fact that we removed the root element and we want to make sure it's back in min HEAP status.
	Min_Heapify( H, 0 );

	return min;
}

/**
 * Increase a key at index i in the heap array to a new value greater than or equal to the current value.
 * @param H   - Heap - The heap in which we want to update our key.
 * @param i   - int - The index of the heap key we want to update.
 * @param key - int - Our value to update.
 */
void Heap_Decrease_Key( Heap *H, int i, int key ) {

	if ( H->array[key] > H->array[i] )
	{
		printf("New key is greater than the current key");
		exit( 1 );
	}

	// Insert our key into the array at specified index
	H->array[i] = key;

	// Case and comparison check for looping
	while ( i > 0 && H->array[Heap_Parent(i)] > H->array[i] )
	{
		// Exchange the items that invalidate our data structure
		int temp = H->array[i];

		H->array[i] = H->array[Heap_Parent(i)];
		H->array[Heap_Parent(i)] = temp;

		/**
		 * Loop case check.
		 * If we get to the root ( i = 0 ) then exit.
		 * If there's no need to replace ( by our comparison ) then exit.
		 */
		i = Heap_Parent(i);
	}
}

/**
 * [Max_Heap_Insert description]
 * @param H   [description]
 * @param key [description]
 */
void Min_Heap_Insert( Heap *H, int key ) {
	H->size++;
	H->length++;

	H->array = (int *) realloc( H->array, sizeof( int ) * H->size );
	H->array[H->size] = INT_MAX;

	Heap_Decrease_Key( H, H->size, key );
}