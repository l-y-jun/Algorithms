#include <stdbool.h>

bool isplaceable(int *pot, int n);
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i;

    if (!n)
        return (true);

    if (flowerbedSize < 2)
        return (flowerbedSize && !*flowerbed && n == 1 ? true : false);

    if (((flowerbedSize + 1) / 2) < n)
        return (false);

    i = 1;
    if (!*flowerbed && !*(flowerbed + 1)) { // start
        n--;
        *(flowerbed + 0) = 1;
        i++;
    }

    while (n && i < flowerbedSize - 2) { // mid(left & right address)
        if (!*(flowerbed + i) && isplaceable(flowerbed, i)) {
            n--;
            *(flowerbed + i) = 1;
            i++;
        }
        i++;
    }

	if (!n || (n == 1 && !*(flowerbed + flowerbedSize - 1) && !*(flowerbed + flowerbedSize - 2))) // end
		return (true);

    return (false);
}

/*
* case when empty aside
*/
bool isplaceable(int *pot, int n)
{
    if ((!*(pot + n - 1)) && !*(pot + n + 1))
        return (true);

    return false;
}

