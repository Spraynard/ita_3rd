#include "heap.h"

void Min_Heapify( Heap *H, int index ) {
	int left = Heap_Left( index );
	int right = Heap_Right( index );

	int smallest;

	// Checking if left child is smaller than our current root
	if ( left <= H->size && H->array[left] < H->array[index] )
	{
		smallest = left;
	}
	else
	{
		// Pre-emptively set the smallest as our current root
		smallest = index;
	}

	// Checking if right is larger than our current root
	if ( right <= H->size && H->array[right] < H->array[smallest] )
	{
		smallest = right;
	}

	// If the smallest element found isn't the root element
	// switch the smallest element with the root element.
	if ( smallest != index )
	{
		int temp = H->array[smallest];
		H->array[smallest] = H->array[index];
		H->array[index] = temp;

		Min_Heapify( H, smallest );
	}
}

/**
 * Builds a Min Heap
 * @param  A      Input array to insert into our heap
 * @param  length Length of input array
 * @return        Min Heaped "Heap" data structure
 */
Heap Build_Min_Heap( int *A, int length ) {
	Heap H;
	H.length = length;
	H.size = length;
	H.array = A;

	for ( int i = H.length / 2; i > 0; i-- )
	{
		Min_Heapify( &H, i );
	}

	return H;
}

/**
 * Sort an array from High to Low using a Min_Heap data structure which contains
 * @param  A      [description]
 * @param  length [description]
 * @return        [description]
 */
int *Heap_Sort_Min( int *A, int length ) {
	Heap H = Build_Min_Heap( A, length );

	for ( int i = H.length; i >= 0; i-- )
	{
		// Exchange the root element with the "index" we are currently on;
		int temp = H.array[i];
		H.array[i] = H.array[0];
		H.array[0] = temp;
		H.size--;
		Min_Heapify( &H, 0 );
	}

	return H.array;
}