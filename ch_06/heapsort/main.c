#include <stdio.h>
// #include "maxheap.c"
#include "maxheappriority.c"
#include "minheap.c"
#include "heap.c"

void printArray( int *inputArray, size_t size )
{
	if ( ! size )
	{
		return;
	}

	for ( int i = 0; i < size; i++ )
	{
		printf("%d, ", inputArray[i]);
	}
	printf("\n");
}

int main() {
	Heap test;
	int array[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
	int arrayLength = sizeof( array ) / sizeof( array[0] );

	printf("Initial Array\n");
	printf("Initial Array Length: %d\n", arrayLength);
	printArray( array, arrayLength );

	test = Build_Max_Heap( array, arrayLength - 1 );

	printf("Max Heaped Array\n");
	printArray(test.array, arrayLength);

	int *sortedArray = Heap_Sort_Max( array, arrayLength - 1 );

	printf("Max Heap Sorted Array\n");
	printArray(sortedArray, arrayLength);

	test = Build_Min_Heap( array, arrayLength - 1 );;

	printf("Min Heaped Array\n");
	printArray(test.array, arrayLength);

	sortedArray = Heap_Sort_Min( array, arrayLength - 1 );

	printf("Min Heap Sorted Array\n");
	printArray(sortedArray, arrayLength);

	int maxHeapKey = Heap_Maximum( test );

	printf("Max Element Of Heap: %d\n", maxHeapKey);
	printArray(test.array, test.length);
	int maxHeapKeyExtracted = Heap_Extract_Max( &test );

	printf("Max Element Of Heap Extracted: %d\n", maxHeapKeyExtracted);
	printArray(test.array, test.length);


}