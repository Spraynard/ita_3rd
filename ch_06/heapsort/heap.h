#ifndef HEAP_H
#define HEAP_H

struct Heap {
	int *array;
	int size;
	int length;
};

typedef struct Heap Heap;

// Heap Implementation Functions
int Heap_Left( int index );

int Heap_Right( int index );

int Heap_Parent( int index );

// Max Heap Implementation Functions
void Max_Heapify( Heap *H, int index );

Heap Build_Max_Heap( int *A, int length );

int *Heap_Sort_Max( int *A, int length );

// Min Heap Implementation Functions
void Min_Heapify( Heap *H, int index );

Heap Build_Min_Heap( int *A, int length );

int *Heap_Sort_Min( int *A, int length );


// Max Heap Priority Queue Implementation Functions
int Heap_Maximum( Heap H );

int Heap_Extract_Max( Heap *H );

void Heap_Increase_Key( Heap *H, int i, int key );

void Max_Heap_Insert( Heap *H, int key );

// Min Heap Priority Queue Implementation Functions
int Heap_Minimum( Heap H );

int Heap_Extract_Min( Heap H );

void Heap_Decrease_Key( Heap H, int i, int key );

void Min_Heap_Insert( Heap H, int key );

#endif