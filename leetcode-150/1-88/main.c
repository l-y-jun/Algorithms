#include <assert.h>

void test(int* result, int len, int *expected);
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void stat(int *arr, int len);

int test_case(void)
{
	int nums1[]	 = {0};
	int nums2[]	 = {2};
	int m = 0;
	int n = 1;
	int expected[] = {2};
	int *result;

	stat(nums1, m);	
	stat(nums2, n);	
	stat(expected, m + n);	
	merge((int *)nums1, sizeof(int), m, (int *)nums2, sizeof(int), n);
	printf("result end: ");
	stat(nums1, m + n);	
	test(nums1, m + n, (int *)expected);
}

void stat(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
		printf("%d ", *(arr + i++));

	printf("\n");
}

void test(int *result, int len, int *expected)
{
	if (len)
		while (len--) {
			assert(*(result + len) == *(expected + len));
		}
}


int main(void)
{
	test_case();
	return (0);
}

