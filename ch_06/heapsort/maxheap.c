#include "heap.h"

void Max_Heapify( Heap *H, int index ) {
	int left = Heap_Left( index );
	int right = Heap_Right( index );

	int largest;

	// Checking if left child is larger than our current root
	if ( left <= H->size && H->array[left] > H->array[index] )
	{
		largest = left;
	}
	else
	{
		// Pre-emptively set the largest as our current root
		largest = index;
	}

	// Checking if right is larger than our current root
	if ( right <= H->size && H->array[right] > H->array[largest] )
	{
		largest = right;
	}

	// If the largest element found isn't the root element
	// switch the largest element with the root element.
	if ( largest != index )
	{
		int temp = H->array[largest];
		H->array[largest] = H->array[index];
		H->array[index] = temp;

		Max_Heapify( H, largest );
	}
}

Heap Build_Max_Heap( int *A, int length ) {
	Heap H;
	H.length = length;
	H.size = length;
	H.array = A;

	for ( int i = H.length / 2; i > 0; i-- )
	{
		Max_Heapify( &H, i );
	}

	return H;
}

int *Heap_Sort_Max( int *A, int length ) {
	Heap H = Build_Max_Heap( A, length );

	for ( int i = H.length; i >= 0; i-- )
	{
		// Exchange the root element with the "index" we are currently on;
		int temp = H.array[i];
		H.array[i] = H.array[0];
		H.array[0] = temp;
		H.size--;
		Max_Heapify( &H, 0 );
	}

	return H.array;
}