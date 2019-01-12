#include <stdio.h>
/**
 * Implementing an increasing insertion sort algorithm, in which we grab an array's value and reference that
 * value to each of the previous ( sorted ) values in the array until we find an item that is less than the current key.
 */
void insertionSortNonDecrease( int *inputArray, size_t size )
{
	for ( int i = 0; i < size; i++ )
	{
		int key = inputArray[i];
		int j = i - 1;

		while ( j > -1 && inputArray[j] > key )
		{
			inputArray[j + 1] = inputArray[j];
			j--;
		}
		inputArray[j + 1] = key;
	}
}

void insertionSortNonIncrease( int *inputArray, size_t size )
{
	for ( int i = 0; i < size; i++ )
	{
		int key = inputArray[i];
		int j = i - 1;

		while ( j > -1 && inputArray[j] < key )
		{
			inputArray[j + 1] = inputArray[j];
			j--;
		}
		inputArray[j + 1] = key;
	}
}

void printArray( int *inputArray, size_t size )
{
	for ( int i = 0; i < size; i++ )
	{
		printf("%i, ", inputArray[i]);
	}
	printf("\n");
}

int main()
{
	int inputArray[7] = {10, 2, 3, 5, 7, 25, 82};
	size_t inputArraySize = sizeof( inputArray ) / sizeof( inputArray[0] );

	printf("Our Unsorted Array:\n");
	printArray( inputArray, inputArraySize );

	insertionSortNonDecrease( inputArray, inputArraySize );
	printf("\nOur Increasing Sort Array\n");
	printArray( inputArray, inputArraySize );

	insertionSortNonIncrease( inputArray, inputArraySize );
	printf("\nOur Decreasing Sort Array\n");
	printArray( inputArray, inputArraySize );
}