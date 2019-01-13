struct Queue {
	int head; // Index pointing at the element that is at the "front" of the queue.
	int tail; // Index @ the next enqueued element
	int length; // Overall length of the queue.
	int (* enqueue)( struct Queue * Q, int x ); // Function used to Insert ( i.e. Enqueue ) an element.
	int (* dequeue)( struct Queue * Q );/// Function used to delete / grab the head element ( i.e. Dequeue )
	int * set; // The actual queue array
};

typedef struct Queue Queue;

int Enqueue( Queue * Q, int x );
int Dequeue( Queue * Q );
Queue Init_Queue();