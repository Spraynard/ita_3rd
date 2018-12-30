#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

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

void Square_Matrix_Init( Matrix *matrix, int n ) {
	matrix->filled = 0;
	matrix->rows = n;
	matrix->data = malloc( n * sizeof( int ) );

	for ( int i = 0; i < n; i++ )
	{
		matrix->data[i] = malloc( n * sizeof( int ) );
	}
}

void Print_Square_Matrix( Matrix *matrix ) {
	int i, j;
	int n = matrix->rows;

	for ( i = 0; i < n; i++ ) {
		printf("|");

		for ( j = 0; j < n; j++ ) {
			printf("%d", matrix->data[i][j]);

			if ( j < ( n - 1 ) )
			{
				printf(", ");
			}
		}
		printf("|\n");
	}
}

void Square_Matrix_Append( Matrix *matrix, int A[], int ASize ) {
	if ( matrix->filled >= matrix->rows ) {
		printf("Our matrix is already filled as fuck\n");
		exit( -1 );
	}

	if ( ASize != matrix->rows ) {
		printf("Given array to append needs to have the same elements as our matrix has rows\n");
		exit( -1 );
	}

	matrix->data[matrix->filled++] = A;
}

void Square_Matrix_Init_Empty( Matrix *matrix ) {
	for ( int i = 0; i < matrix->rows; i++ ) {
		int * temp = calloc( matrix->rows, sizeof( int ) );
		Square_Matrix_Append( matrix, temp, matrix->rows );
	}
}

Matrix Square_Matrix_Multiply( Matrix A, Matrix B ) {
	int i, j, k, n;
	n = A.rows;

	Matrix C;
	Square_Matrix_Init( &C, n );
	Square_Matrix_Init_Empty( &C );

	for ( i = 0; i < n; i++ ) {

		for ( j = 0; j < n; j++ ) {

			for ( k = 0; k < n; k++ ) {
				C.data[i][j] += A.data[i][k] * B.data[k][j];
			}
		}
	}

	return C;
}

void Get_Quad( Matrix parent, Matrix *sub, int startRow, int endRow, int startCol, int endCol ) {
	int tempX = 0;
	int tempY = 0;
	int i, j;

	// printf("Printing Parent Matrix TO build a quad from\n");
	// Print_Square_Matrix( &parent );
	// printf("Printing Sub Matrix build as a quad\n");
	// Print_Square_Matrix( sub );

	printf("Start Row: %d\t", startRow);
	printf("End Row: %d\t", endRow);
	printf("Start Col: %d\t", startCol);
	printf("End Col: %d\n", endCol);

	for ( i = startRow; i < endRow; i++ )
	{
		tempX = 0;
		for ( j = startCol; j < endCol; j++ )
		{
			sub->data[tempX][tempY] = parent.data[j][i];
			tempX++;
		}
		tempY++;
	}
}

void Set_Quad( Matrix *parent, Matrix *sub, int startRow, int endRow, int startCol, int endCol ) {
	int tempX = 0;
	int tempY = 0;
	int i, j;


	for ( i = startRow; i < endRow; i++ )
	{
		tempX = 0;
		for ( j = startCol; j < endCol; j++ )
		{
			parent->data[j][i] = sub->data[tempX][tempY];
			tempX++;
		}
		tempY++;
	}
}

Matrix Add_Square_Matrices( Matrix A, Matrix B ) {
	int n = A.rows;
	Matrix temp;
	Square_Matrix_Init( &temp, n );

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			temp.data[i][j] = A.data[i][j] + B.data[i][j];
		}
	}
	return temp;
}

void Combine_Submatrices( Matrix *parent, Matrix TopLeft, Matrix TopRight, Matrix BottomLeft, Matrix BottomRight, int n ) {

	Set_Quad( parent, &TopLeft, 0, n / 2, 0, n / 2 );

	// printf("Transform - Top Left: \n");
	// Print_Square_Matrix( parent );

	Set_Quad( parent, &TopRight, n / 2, n, 0, n / 2 );

	// printf("Transform - Top Right: \n");
	// Print_Square_Matrix( parent );

	Set_Quad( parent, &BottomLeft, 0, n / 2, n / 2, n );

	// printf("Transform - Bottom Left: \n");
	// Print_Square_Matrix( parent );

	Set_Quad( parent, &BottomRight, n / 2, n, n / 2, n );

	// printf("Transform - Bottom Right: \n");
	// Print_Square_Matrix( parent );


}

/**
 * Recursive matrix multiplication. Only works for NxN matrices where N is an even number currently.
 */
Matrix Square_Matrix_Multiply_Recursive( Matrix A, Matrix B ) {
	int n = A.rows;

	Matrix C;
	Square_Matrix_Init( &C, n );
	Square_Matrix_Init_Empty( &C );

	// Base Case, when we are a 1x1 matrix
	if ( n == 1 ) {
		// printf("Printing A\n");
		// Print_Square_Matrix( &A );

		// printf("Printing B\n");
		// Print_Square_Matrix( &B );

		C.data[0][0] = A.data[0][0] * B.data[0][0];
	}
	else {
		// Partition each of ou21matrices into four n/2 by n/2 matrices
		// Initializing Matrice Partitions
		Matrix A11, A12, A21, A22;
		Matrix B11, B12, B21, B22;
		Matrix C11, C12, C21, C22;

		// Initializing our Matrices

		Square_Matrix_Init( &A11, n / 2 );
		Square_Matrix_Init( &A12, n / 2 );
		Square_Matrix_Init( &A21, n / 2 );
		Square_Matrix_Init( &A22, n / 2 );

		Square_Matrix_Init( &B11, n / 2 );
		Square_Matrix_Init( &B12, n / 2 );
		Square_Matrix_Init( &B21, n / 2 );
		Square_Matrix_Init( &B22, n / 2 );

		Square_Matrix_Init( &C11, n / 2 );
		Square_Matrix_Init( &C12, n / 2 );
		Square_Matrix_Init( &C21, n / 2 );
		Square_Matrix_Init( &C22, n / 2 );

		// Partition Matrix A into quadrants

		Get_Quad( A, &A11, 0, n / 2, 0, n / 2 );
		Get_Quad( A, &A12, n / 2, n, 0, n / 2 );
		Get_Quad( A, &A21, 0, n / 2, n / 2, n );
		Get_Quad( A, &A22, n / 2, n, n / 2, n );

		// Partition Matrix B into quadrants

		Get_Quad( B, &B11, 0, n / 2, 0, n / 2 );
		Get_Quad( B, &B12, n / 2, n, 0, n / 2 );
		Get_Quad( B, &B21, 0, n / 2, n / 2, n );
		Get_Quad( B, &B22, n / 2, n, n / 2, n );

		// // Partition matrix C into Quadrants by recursing and adding each of the resultant matrices to each other.

		// C11 = Add_Square_Matrices( Square_Matrix_Multiply_Recursive( A11, B11 ), Square_Matrix_Multiply_Recursive( A12, B21 ) );
		// C12 = Add_Square_Matrices( Square_Matrix_Multiply_Recursive( A11, B12 ), Square_Matrix_Multiply_Recursive( A12, B22 ) );
		// C21 = Add_Square_Matrices( Square_Matrix_Multiply_Recursive( A21, B11 ), Square_Matrix_Multiply_Recursive( A22, B21 ) );
		// C22 = Add_Square_Matrices( Square_Matrix_Multiply_Recursive( A21, B12 ), Square_Matrix_Multiply_Recursive( A22, B22 ) );

		// printf("C11\n");
		// Print_Square_Matrix( &C11 );

		// printf("C12\n");
		// Print_Square_Matrix( &C12 );

		// printf("C21\n");
		// Print_Square_Matrix( &C21 );

		// printf("C22\n");
		// Print_Square_Matrix( &C22 );

		// // Combine the partitions of matrix C into C
		// Combine_Submatrices( &C, C11, C12, C21, C22, n );
	}

	return C;
}