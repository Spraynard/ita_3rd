#include <stdlib.h>
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