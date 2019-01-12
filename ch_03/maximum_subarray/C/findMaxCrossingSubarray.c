#include <limits.h>
#include "subarraystructs.h"

struct subArrayTuple findMaxCrossingSubarray( int A[], int low, int mid, int high ) {
	struct subArrayTuple returnData;
	int i, j;
	int sum, leftSum, rightSum;
	int maxLeftIndex, maxRightIndex;

	leftSum = INT_MIN;
	rightSum = INT_MIN;

	sum = 0;
	for ( i = mid; i >= low; i-- )
	{
		sum += A[i];

		if ( sum > leftSum )
		{
			leftSum = sum;
			maxLeftIndex = i;
		}
	}

	sum = 0;
	for ( j = mid + 1; j <= high; j++ )
	{
		sum += A[j];

		if ( sum > rightSum )
		{
			rightSum = sum;
			maxRightIndex = j;
		}
	}

	returnData.maxLeftIndex = maxLeftIndex;
	returnData.maxRightIndex = maxRightIndex;
	returnData.subArraySum = leftSum + rightSum;

	return returnData;
}