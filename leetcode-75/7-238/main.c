#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int *ret;
	int i;
	int v;

	if (!numsSize)
		return (NULL);

	ret = (int *)malloc(sizeof(int) * numsSize);
	*returnSize = numsSize;

	if (numsSize == 1) {
		*ret = 0;
		return (ret);
	}

	// [1, a, ab, abc, abcd] product and save in order
	// product e, de, cde, bcde in reverse order

	*ret = 1;
	v = 1;
	i = 0;
	while (i < (numsSize - 1)) { // i = 0 -> n-2 
		v *= *(nums + i++); // a
		*(ret + i) = v;  //[1] = a
	}

	v = 1;
	while (i) {
		v *= *(nums + i--); // v = 1 * e
		*(ret + i) *= v;  // [end - 1] = abc * v
	}
		
	return (ret);
}

