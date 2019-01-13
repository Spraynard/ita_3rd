#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "queue.c"

int main() {
	int run = 1;
	char inputString[100];
	char inputNumString[100];
	int inputNum;
	Queue q = Init_Queue();
	int enqueueSuccessful;

	while ( run ) {
		Print_Queue( &q );

		printf("Do you want to Add, Delete, or End the script?\n");
		fgets(inputString, 100, stdin);

		// Lowercase the input string
		for (int i = 0; inputString[i]; i++) {
			inputString[i] = tolower(inputString[i]);
		}

		// Enqueue
		if ( strncmp( inputString, "add", 3 ) == 0 )
		{
			printf("What number do you want to enqueue?\n");
			fgets(inputNumString, 100, stdin);
			sscanf(inputNumString, "%d", &inputNum);
			enqueueSuccessful = q.enqueue( &q, inputNum );

			if ( ! enqueueSuccessful )
			{
				printf("Exiting because of queue overflow\n");
				exit( 0 );
			}
		}
		// Dequeue
		else if ( strncmp( inputString, "delete", 6 ) == 0 )
		{
			inputNum = q.dequeue( &q );
			printf("The number taken out of the queue: %d\n", inputNum );
		}
		// End Script
		else if ( strncmp( inputString, "end", 3 ) == 0 )
		{
			printf("Ending Script\n");
			exit( 0 );
		}
		else
		{
			continue;
		}
	}
}