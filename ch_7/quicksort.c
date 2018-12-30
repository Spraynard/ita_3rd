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

void Quick_Sort( int* A, int p, int r ) {
	int q;

	if ( p < r )
	{
		q = Partition( A, p, r );
		Quick_Sort( A, p, q - 1);
		Quick_Sort( A, p + 1, r);
	}
}