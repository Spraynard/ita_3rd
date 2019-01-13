#include "queue.h"
#include "util.c"

void Print_Queue( Queue * q ) {
	int i, j, temp;
	printArray( q->set, q->length );
	for ( i = 0; i < 3; i++ )
	{
		// printf("Value of I: %d\n", i);
		for ( j = 0; j < q->length; j++ )
		{
			// printf("Value of I: %d\n", i);
			if ( i == 0 )
			{
				if ( j == q->head )
				{
					printf("^");
				}

				if ( j == q->tail )
				{
					printf("^");
				}
			}
			else if ( i == 1 )
			{
				// printf("I == 1");
				if ( j == q->head )
				{
					printf("|");
				}

				if ( j == q->tail )
				{
					printf("|");
				}
			}
			else if ( i == 2 )
			{
				// printf("I == 2");
				if ( j == q->head )
				{
					printf("head");
				}

				if ( j == q->tail )
				{
					printf("tail");
				}
			}
			// cover for the formatting of the number
			temp = q->set[j];
			while ( temp ) {
				printf(" ");
				temp = temp / 10;
			}


			// covering for the space and comma
			printf("  ");
		}
		printf("\n");
	}
}

int Enqueue( Queue * Q, int x ) {

	if ( Q->head == Q->tail + 1 )
	{
		printf("Queue Overflow\n");
		return 0;
	}

	Q->set[Q->tail] = x;

	if ( Q->tail == Q->length - 1 )
	{
		Q->tail = 0;
	}
	else
	{
		Q->tail++;
	}

	return 1;
}

int Dequeue( Queue * Q ) {
	// Check for Queue underflow

	if ( Q->head == Q->tail )
	{
		printf("Queue Underflow");
		exit( 1 );
	}

	int x = Q->set[Q->head];

	if ( Q->head == Q->length - 1 )
	{
		Q->head = 0;
	}
	else
	{
		Q->head++;
	}

	return x;
}

Queue Init_Queue() {
	Queue q;

	/**
	 * On initialization, head and tail point at the same area
	 * of the "set" ( i.e. array )
	 */
	q.head = 0;
	q.tail = 0;
	q.length = 12;
	q.enqueue = Enqueue;
	q.dequeue = Dequeue;
	q.set = ( int * ) calloc( q.length, sizeof( int ) );

	return q;
}