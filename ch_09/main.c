#include "randomized_select.c"
#include <stdio.h>

int main() {
	int A[6] = { 1, 3, 2, 7, 8, 9 };
	int ALen = sizeof( A ) / sizeof( A[0] );
	int rangeStart = 0;
	int rangeEnd = ALen - 2;
	// What's the min?
	int min = Randomized_Select( A, rangeStart, rangeEnd - 1, 1 );

	printf("Array Range - Based on index: ( %d, %d )\n", rangeStart, rangeEnd - 1);
	printf("The Min Number Is: %d\n", min);

	return 0;
}