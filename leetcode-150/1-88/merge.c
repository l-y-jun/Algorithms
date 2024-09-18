void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int *temp[m + n];
	int i;
	int n1_i;
	int n2_i;

	i = 0;
	n1_i = 0;
	n2_i = 0;

	while ((m > n1_i) || (n > n2_i)) {
		if ((m > n1_i) && (n > n2_i))
			*(temp + i++) = *(nums1 + n1_i) < *(nums2 + n2_i) ? *(nums1 + n1_i++) : *(nums2 + n2_i++);
		else
			*(temp + i++) = (m > n1_i) ? *(nums1 + n1_i++) : *(nums2 + n2_i++);
	}

	while (i--)
		*(nums1 + i) = *(temp + i);
}

