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
	int array2[] = { 2, 2000, 0, 417, 80, 81, 64, 34 };
	int array3[] = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };

	int arrayLen = sizeof(array)/sizeof(array[0]);
	int array3Len = sizeof(array3)/sizeof(array3[0]);

	int *outArray = (int *) calloc( arrayLen, sizeof( int ) );
	int *outArray3 = (int *) calloc( array3Len, sizeof( int ) );

	Counting_Sort( array3, array3Len, outArray3, 6 );

	printf("Output Array After: \n");
	printArray(outArray3, array3Len);
}