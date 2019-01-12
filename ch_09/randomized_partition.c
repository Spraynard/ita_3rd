#include <stdlib.h>

int Partition( int *A, int p, int r )
{
	int j;
	int x = A[r];
	int i = p - 1;

	for ( j = p; j < r; j++ )
	{
		if ( A[j] <= x )
		{
			i++;
			// Exchange A[i] w/ A[j];
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	// Exchange A[i + 1] with A[r]
	int temp2 = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp2;

	return i + 1;
}

/**
 * Not a good implementation
 * as it skews the randomness but it's good enough.
 */
int Random( int start, int end ) {
	return start + ( rand() % end );
}

int Randomized_Partition( int *A, int p, int r ) {
	int i = Random( p, r ), temp;

	// Exchange A[r] with A[i]
	temp = A[r];
	A[r] = A[i];
	A[i] = A[r];

	return Partition( A, p, r );
}