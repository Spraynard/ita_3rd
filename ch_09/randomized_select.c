#include "randomized_partition.c"

// Returns the ith smallest element of Array[p...r]
int Randomized_Select( int *A, int p, int r, int i ) {
	int q, k;

	if ( p == r )
	{
		return A[p];
	}

	q = Randomized_Partition( A, p, r );
	k = q - p + 1;

	if ( i == k )
	{
		return A[q];
	}
	else if ( i < k )
	{
		return Randomized_Select( A, p, q - 1, i);
	}
	else
	{
		return Randomized_Select( A, q + 1, r, i - k );
	}
}