struct Stack {
	int top; // Index of the most recently inserted element
	int max; // Max size of the stack
	int ( *push )( struct Stack * S, int x );
	int ( *pop )( struct Stack * S );
	int * set;
};

typedef struct Stack Stack;

void Print_Stack( Stack * s );
int Push( Stack * S, int x );
int Pop( Stack * S );
int Stack_Empty( Stack * S );
Stack Stack_Init();