#include <stdio.h>
#include "subarraystructs.h"
#include "findMaxSubarray.c"

int main() {
	struct subArrayTuple maxSubArray;

	int inputArray[] = { -5, -4, -3, -4 };
	int inputArraySize = sizeof( inputArray ) / sizeof( inputArray[0] );

	maxSubArray = findMaximumSubarray( inputArray, 0, inputArraySize - 1 );

	printSubArrayTuple( maxSubArray );
}