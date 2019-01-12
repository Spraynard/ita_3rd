#ifndef STRUCTS_H
#define STRUCTS_H

struct Square_Matrix {
	int rows;
	int filled;
	int **data;
};

typedef struct Square_Matrix Matrix;

void Matrix_Init( Matrix *matrix );
#endif