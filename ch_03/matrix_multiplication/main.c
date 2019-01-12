#include "structs.h"
#include "matrix.c"

int main() {
	Matrix matrix1;
	Matrix matrix2;
	Matrix matrix3;
	Matrix matrix4;

	// int arr1[4] = { 1, 2, 3, 12 };
	// int arr2[4] = { 4, 5, 6, 12 };
	// int arr3[4] = { 7, 8, 9, 12 };
	// int arr4[4] = { 7, 8, 9, 12 };

	// int arr5[4] = { 10, 11, 12, 8 };
	// int arr6[4] = { 13, 14, 15, 8 };
	// int arr7[4] = { 16, 17, 18, 8 };
	// int arr8[4] = { 16, 17, 18, 8 };

	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 4, 5, 6 };
	int arr3[3] = { 7, 8, 9 };

	int arr4[3] = { 7, 8, 9, };
	int arr5[3] = { 10, 11, 12 };
	int arr6[3] = { 13, 14, 15 };

	// // Initializing and building matrix 1
	// Square_Matrix_Init( &matrix1, 4 );
	// Square_Matrix_Append( &matrix1, arr1, (int) sizeof( arr1 ) / sizeof( arr1[0] ) );
	// Square_Matrix_Append( &matrix1, arr2, (int) sizeof( arr2 ) / sizeof( arr2[0] ) );
	// Square_Matrix_Append( &matrix1, arr3, (int) sizeof( arr3 ) / sizeof( arr3[0] ) );
	// Square_Matrix_Append( &matrix1, arr4, (int) sizeof( arr4 ) / sizeof( arr4[0] ) );

	// // printf("Matrix 1: \n");
	// // Print_Square_Matrix( &matrix1 );

	// // Initializing and building matrix 2
	// Square_Matrix_Init( &matrix2, 4 );
	// Square_Matrix_Append( &matrix2, arr5, (int) sizeof(arr5) / sizeof( arr5[0] ) );
	// Square_Matrix_Append( &matrix2, arr6, (int) sizeof(arr6) / sizeof( arr6[0] ) );
	// Square_Matrix_Append( &matrix2, arr7, (int) sizeof(arr7) / sizeof( arr7[0] ) );
	// Square_Matrix_Append( &matrix2, arr8, (int) sizeof(arr8) / sizeof( arr8[0] ) );

		// Initializing and building matrix 1
	Square_Matrix_Init( &matrix1, 3 );
	Square_Matrix_Append( &matrix1, arr1, (int) sizeof( arr1 ) / sizeof( arr1[0] ) );
	Square_Matrix_Append( &matrix1, arr2, (int) sizeof( arr2 ) / sizeof( arr2[0] ) );
	Square_Matrix_Append( &matrix1, arr3, (int) sizeof( arr3 ) / sizeof( arr3[0] ) );

	// printf("Matrix 1: \n");
	// Print_Square_Matrix( &matrix1 );

	// Initializing and building matrix 2
	Square_Matrix_Init( &matrix2, 3 );
	Square_Matrix_Append( &matrix2, arr4, (int) sizeof(arr4) / sizeof( arr4[0] ) );
	Square_Matrix_Append( &matrix2, arr5, (int) sizeof(arr5) / sizeof( arr5[0] ) );
	Square_Matrix_Append( &matrix2, arr6, (int) sizeof(arr6) / sizeof( arr6[0] ) );
	printf("Matrix 2: \n");
	Print_Square_Matrix( &matrix2 );


	// This is where we would multiply the matrix
	matrix3 = Square_Matrix_Multiply( matrix1, matrix2 );

	printf("Matrix 3, O(n^3) multiply: \n");
	Print_Square_Matrix( &matrix3 );

	matrix4 = Square_Matrix_Multiply_Recursive( matrix1, matrix2 );
	printf("Matrix 4, O(n^2.8) multiply: \n");
	Print_Square_Matrix( &matrix4 );

}