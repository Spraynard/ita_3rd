#include "countingsort.c"
#include <stdio.h>
#include <stdlib.h>



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
	int array[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	int arrayLen = sizeof(array)/sizeof(array[0]);

	int *outArray = (int *) calloc( arrayLen, sizeof( int ) );

	printf("Input Array Before: \n");
	printArray(array, arrayLen);

	printf("Output Array Before: \n");
	printArray(outArray, arrayLen);

	Counting_Sort( array, arrayLen, outArray, 5 );

	printf("Input Array After: \n");
	printArray(array, arrayLen);

	printf("Output Array After: \n");
	printArray(outArray, arrayLen);
}