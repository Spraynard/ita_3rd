/**
 * Stack Implementation
 * Very rudimentary, non dynamic implementation of a stack.
 * Currently initializes with enough memory to not make it a problem for training purposes.
 */

#include <stdio.h>
#include <stdlib.h>
#include "util.c"
#include "stack.h"

void Print_Stack( Stack * s ) {
	printf("Stack Top: %d\n", s->top);
	printf("Current Stack:\n");
	printArray( s->set, s->top + 1 );
}

int Push( Stack * S, int x ) {
	if ( S->top == S->max - 1 ) return 0;

	S->top++;
	S->set[S->top] = x;
	return 1;
}

int Pop( Stack * S ) {
	if ( S->top == -1 ) {
		printf("Stack Underflow\n");
		exit(1);
	}
	else {
		S->top--;
		return S->set[S->top + 1];
	}
}

int Stack_Empty( Stack * S ) {
	if ( S->top == -1 )
	{

		return 1;
	}
	return 0;
}

Stack Stack_Init() {
	Stack s;
	s.max = 1000;
	s.push = Push;
	s.pop = Pop;
	s.top = -1;
	s.set = (int *) malloc( s.max * sizeof( int ) );

	return s;
}
