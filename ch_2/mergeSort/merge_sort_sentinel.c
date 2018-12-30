#include <stdio.h>
#include <limits.h>

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

/**
 * Merge works by dividing the input array into a L and R side, of which we will append a SENTINEL
 * element to ( INT_MAX ) that will be used to effectively anchor our L and R arrays. Once these arrays are built,
 * we compare between the two and add the sort specific item to our main array.
 */
void merge( int array[], int p, int q, int r)
{
	int i, j;
	int n1 = q - p + 1;
	int n2 = r - q;

	// Putting anchors at the end of each array requires space for them.
	// That's why +1 is there.
	int L[n1 + 1];
	int R[n2 + 1];

	// Fill the left and right arrays
	for ( i = 0; i < n1; i++ )
	{
		L[i] = array[p + i];
	}

	for ( j = 0; j < n2; j++ )
	{
		R[j] = array[q + j + 1];
	}

	// Sentinels appended at the end of our arrays
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	i = 0; //Initial Index of Left
	j = 0; //Initial Index of Right

	for ( int k = p; k <= r; k++ )
	{
		if ( L[i] <= R[j] )
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
	}
}

void mergeSort( int array[], int p, int r )
{
	int q;
	if ( p < r )
	{
		q = ( p + r ) / 2; // Finding the halfway pt of the input array

		mergeSort( array, p, q );
		mergeSort( array, q + 1, r );
		merge( array, p, q, r );
	}
}

int main() {
	int inputArray[] = {2, 4, 5, 7, 1, 2, 3, 6};
	int inputArraySize = sizeof( inputArray ) / sizeof( inputArray[0] );
	mergeSort( inputArray, 0, inputArraySize - 1);
	printArray( inputArray, inputArraySize );
}