void Counting_Sort( int *A, int inputLen, int *B, int k ) {
	int C[k], i, j;

	for ( i = 0; i < k; i++ )
	{
		C[i] = 0;
	}

	for ( j = 0; j < inputLen; j++ )
	{
		C[A[j]] = C[A[j]] + 1;
	}

	for ( i = 0; i < k; i++ )
	{
		C[i] = C[i] - C[i -1];
	}

	for ( j = inputLen; j > 0; j-- )
	{
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
}