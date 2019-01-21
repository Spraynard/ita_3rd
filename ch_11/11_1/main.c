#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../util.c"
#include "Table.c"

int * buildRandomArray( int len ) {
	int i;
	int * returnArray = malloc( len * sizeof( int ) );

	for ( i = 0; i < len; i++ )
	{
		returnArray[i] = rand() % 101;
	}

	return returnArray;
}

int main() {
	srand(time(NULL));

	int universe[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int universeSize = sizeof( universe ) / sizeof( universe[0] );
	int i, randomArraySize;
	int * randomArray;
	Table T = buildTable( universe, universeSize );

	for ( i = 0; i < universeSize; i++ )
	{
		randomArraySize = 1 + rand() % 50;
		randomArray = buildRandomArray( randomArraySize );

		Element E = buildElement( i, randomArray, randomArraySize );

		Direct_Address_Insert( &T, E );

		if ( rand() % 2 )
		{
			Direct_Address_Delete( &T, E );
		}
	}
	printTable( &T );
	printf("\n");
	Element * randomElement = Direct_Address_Search( &T, rand() % universeSize );
	printElement( randomElement );
	return 0;
}