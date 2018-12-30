#include "quicksort.c"
#include <stdio.h>

void printArray( int *inputArray, size_t size )
{
	if ( ! size )
	{
		return;
	}

	for ( int i = 0; i < size; i++ )
	{
		printf("%d", inputArray[i]);
		if ( i < size - 1 ) {
			printf(", ");
		}
	}
	printf("\n");
}

int main() {
	int array[] = { 2,8,7,1,9,3,5,6,4, };
	int arrayLen = sizeof(array) / sizeof(array[0]);

	printf("Printing Unsorted Array\n");
	printArray( array, arrayLen );

	printf("Sorting Array\n");
	Quick_Sort( array, 0, arrayLen - 1 );
	printf("Sorted Array\n");
	printArray( array, arrayLen);
}