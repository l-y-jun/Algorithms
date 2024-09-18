/*
// btof = Back to front
// no swap in this case
*/
void btof(int *arr, int head, int tail)
{ 
   *(arr + head) = *(arr + tail);
}

int removeElement(int *nums, int numsSize, int val)
{
        int front;
		int back;

        front = 0;
		back = numsSize;

        while (front < back)
            *(nums + front) == val ? btof(nums, front, --back) : front++;

        return (back);
}

/*
// v = 2, arr = [1,2,2,5,2]
// 1-btof = [1,2,2,5,2]
//             f     b
// 2-btof = [1,2,2,5,2]...
//             f   b
*/

