#include "subarraystructs.h"
#include "findMaxCrossingSubarray.c"

struct subArrayTuple findMaximumSubarray( int A[], int low, int high ) {
	int mid;
	struct subArrayTuple leftArrayData;
	struct subArrayTuple rightArrayData;
	struct subArrayTuple crossArrayData;

	if ( high == low )
	{
		struct subArrayTuple returnData;

		returnData.maxLeftIndex = low;
		returnData.maxRightIndex = high;
		returnData.subArraySum = A[low];
		return returnData; // base case: only one element
	}
	else
	{
		mid = ( low + high ) / 2;

		leftArrayData = findMaximumSubarray( A, low, mid );
		rightArrayData = findMaximumSubarray( A, mid + 1, high );
		crossArrayData = findMaxCrossingSubarray( A, low, mid, high );

		printf("Left\n");
		printSubArrayTuple(leftArrayData);
		printf("\n");
		printf("Right\n");
		printSubArrayTuple(rightArrayData);
		printf("\n");
		printf("Cross\n");
		printSubArrayTuple(crossArrayData);
		printf("\n");

		if ( leftArrayData.subArraySum >= rightArrayData.subArraySum && leftArrayData.subArraySum >= crossArrayData.subArraySum )
		{
			return leftArrayData;
		}
		else if ( rightArrayData.subArraySum >= leftArrayData.subArraySum && rightArrayData.subArraySum >= crossArrayData.subArraySum )
		{
			return rightArrayData;
		}
		else
		{
			return crossArrayData;
		}
	}
}