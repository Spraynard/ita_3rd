from algFns import findMaxSubArray

a = [1, 2, -6, 7, -10, -8]

maxSubarrayTuple = findMaxSubArray( a, 0, len( a ) - 1 )

print( maxSubarrayTuple )