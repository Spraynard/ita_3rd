#ifndef SUBARRAYSTRUCTS_H
#define SUBARRAYSTRUCTS_H

struct subArrayTuple {
	int maxLeftIndex;
	int maxRightIndex;
	int subArraySum;
};

void printSubArrayTuple( struct subArrayTuple tuple )
{
	printf("Tuple Left Index: %d\n", tuple.maxLeftIndex);
	printf("Tuple Right Index: %d\n", tuple.maxRightIndex);
	printf("Tuple Sum: %d\n", tuple.subArraySum);
}

#endif
