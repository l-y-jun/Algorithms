#include <stdlib.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int biggest;
    int i;
    bool *ret;

    i = 1;
    biggest = *candies;
    while (i < candiesSize) {
        biggest = *(candies + i) > biggest ? *(candies + i) : biggest;
        i++;
    }

    biggest -= extraCandies;
    ret = (bool *)malloc(sizeof(bool) * candiesSize);
    i = 0;
    while (i < candiesSize)
        *(ret + i++) = biggest > *(candies + i) ? false : true;

    *returnSize = candiesSize;
    return (ret);
}

