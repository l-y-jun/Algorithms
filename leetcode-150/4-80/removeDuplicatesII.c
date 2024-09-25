#include <assert.h>
#include <stdio.h>

void test(int *nums, int numsSize, int ret, int *expected);
void copy(int *dest, int *src, int *end);
void stat(int *arr, int len);

int countDuplicates(int *from, int *to) {
	int ret;

	if (!(from < to))
		return 0;

	ret = 0;
	printf("from %d: to: %d\n", *from, *to);
	while ((from < to) && (*from == *(from + 1))) {
		ret++;
		from++;
	}

	printf("DUPS: %d", ret);
	return (ret);
}

int removeDuplicates(int *nums, int numsSize)
{
	int dupcnt;
	int *cur;
	int *tail;

	cur = nums;
	tail = cur + numsSize - 1;
	printf("CUR: %d TAIL:%d\n", *cur, *tail);
	while (cur < tail) {
		if ((dupcnt = countDuplicates(cur, tail)) && dupcnt > 1) {
			printf("DUPS: %d\n", dupcnt);
			copy(cur + 2, cur + 2 + dupcnt - 1, tail);
			tail -= (dupcnt - 1);
			cur++;
		}
		cur++;
	}
	printf("RET : %d\n", tail - nums);
	return (tail - nums + 1);
}

void copy(int *dest, int *src, int *end)
{
	while (src <= end)
		*dest++ = *src++;
}

int main(void)
{
	int nums1[] = {1,1,1};
	int ret1 = 2;
	int expected1[] = {1, 1};
	test(nums1, 3, ret1, expected1);

	int nums2[] = {0,0,1};
	int ret2 = 3;
	int expected2[] = {0,0,1};
	test(nums2, 3, ret2, expected2);

}

void test(int *nums, int numsSize, int ret, int *expected)
{
	int i;
	int v;

	i = 0;
	v = removeDuplicates(nums, numsSize);

	assert(v == ret);
	while (i < ret) {
		printf("TEST %d: %d and %d\n", i , *(nums+i), *(expected + i));
		assert(*(nums + i) == *(expected + i));
		i++;
	}
	printf("FIN TEST\n");
}

void stat(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
		printf("%d ", *(arr + i++));

	printf("\n");
}
