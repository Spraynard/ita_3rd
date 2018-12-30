import math

def findMaxSubArray( A, low, high ):
	if ( low == high ):
		return ( low, high, A[low] )
	else:
		mid = math.floor(( low + high ) / 2)

		( maxLeftStart, maxLeftEnd, maxLeftSum ) = findMaxSubArray( A, low, mid )
		( maxRightStart, maxRightEnd, maxRightSum ) = findMaxSubArray( A, mid + 1, high )
		( maxCrossStart, maxCrossEnd, maxCrossSum ) = findMaxCrossingSubarray( A, low, mid, high )

		if ( maxLeftSum >= maxRightSum and maxLeftSum >= maxCrossSum ):
			return ( maxLeftStart, maxLeftEnd, maxLeftSum )
		elif ( maxRightSum >= maxLeftSum and maxRightSum >= maxCrossSum ):
			return ( maxRightStart, maxRightEnd, maxRightSum )
		else:
			return ( maxCrossStart, maxCrossEnd, maxCrossSum )

def findMaxCrossingSubarray( A, low, mid, high ):
	leftSum = float('-inf')
	rightSum = float('-inf')

	sum = 0
	for i in range( mid, low - 1, -1 ):
		sum += A[i]

		if ( sum > leftSum ):
			leftSum = sum
			maxLeft = i

	sum = 0
	for j in range( mid + 1, high + 1):
		sum += A[j]

		if ( sum > rightSum ):
			rightSum = sum
			maxRight = j
	return ( maxLeft, maxRight, leftSum + rightSum )