#include <stdio.h>
#include <math.h>

int insertionSortSteps( int value )
{
	return ( value > 1 ) ? 8 * pow( value, 2 ) : 0;
}

int mergeSortSteps( int value )
{
	return ( value > 1 ) ? 64 * value * log( value ) : 0;
}

int algo1( int value )
{
	return ( value > 1 ) ? 100 * pow( value, 2 ) : 0;
}

int algo2( int value )
{
	return ( value > 1 ) ? pow( 2, value ) : 0;
}

int main(int argc, char const *argv[])
{
	int stepMax = 100;

	// printf("Insertion Sort Timing\t");
	// printf("Merge Sort Timing\n");

	printf("Algo 1 Timing\t");
	printf("Algo 2 Timing\n");
	for ( int i = 0; i <= stepMax; i++ )
	{
		printf("n = %i, time = %i\tn = %i, time = %i\n", i, algo1(i), i, algo2(i));
	}
}