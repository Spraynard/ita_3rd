#include "heap.h"

/**
 * Based on the array index of a "child" heap node in an array, find the "parent"'s index of a heap node in the same array.
 * @param  index Index of "child" heap node.
 * @return       "Parent" index of given "child" heap node index.
 */
int Heap_Parent( int index ) {
	return index >> 1;
}

/**
 * Based on the inde of a "Parent" heap node in an array, find the "left-child's" index of this node
 * @param  index Index of "Parent" heap node
 * @return       "Left Child" heap node index
 */
int Heap_Left( int index ) {
	return index << 1;
}

/**
 * Based on the index of a "Parent" heap node in an array, find the "right-child's" index of this node.
 * @param  index Index of a "Parent" heap node
 * @return       "Right Child" heap node index
 */
int Heap_Right( int index ) {
	return ( index << 1 ) + 1;
}