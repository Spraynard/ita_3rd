/**
 * O(k + n) sort in which we sort an array of ints
 * @param A        Input Array - Array to be sorted
 * @param inputLen Length of Input Array
 * @param B        Output Array - Array to insert values and sort
 * @param k        Range of integers in the input array. Should try
 *                 and be the max value of the array to maintain efficiency
 *                 but, it should only matter if k is pretty big
 */
void Counting_Sort( int *A, int inputLen, int *B, int k ) {
	k = k + 1;
	int C[k], i, j;

	for ( i = 0; i < k; i++ )
	{
		C[i] = 0;
	}

	// C is filled with 0's

	for ( j = 0; j < inputLen; j++ )
	{
		C[A[j]] = C[A[j]] + 1;
	}

	// C[i] is filled where i = # of times the number shows up

	for ( i = 1; i < k; i++ )
	{
		C[i] = C[i] + C[i - 1];
	}

	// C[i] is filled where i = # of elements < i

	for ( j = inputLen; j > 0; j-- )
	{
		B[C[A[j - 1]] - 1] = A[j - 1];

		// C[A[j - 1]] is the correct final position of A[j] in the output array.
		// We decrement in order to assure that non distinct numbers are placed in B as well.
		C[A[j - 1]] = C[A[j - 1]] - 1;
	}

	// Should be sorted now.
}