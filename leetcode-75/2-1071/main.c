#include <string.h>
#include <stdio.h>

int getMaxCommonDivisor(const char *dest, const char *src);
/*
* is div of src -> is div of dest -> is dup in src? is dup in dest?
*/
int isdupstr(const char *s, const char *pattern, int len); // check string in pattern
int getNextDivisor(int v, int div); // find next smaller divisor
int	isdiv(int v, int div); // modulus calc

int main(void)
{
	int ret;

	ret = getMaxCommonDivisor("LEET", "CODE");
	printf("%d", ret);
	return (0);
}

int getMaxCommonDivisor(const char *dest, const char *src)
{
	int destlen;
	int srclen;
	int div;
	int ret;

	destlen = strlen(dest);
	srclen = strlen(src);
	div = srclen;
	while ((div = getNextDivisor(srclen, div))) { // is div of src?
		if (isdiv(destlen, div) && isdupstr(src, src, div) && isdupstr(dest, src, div)) 
			return (div);
		div--;
	}

	return (0);
}

int getNextDivisor(int v, int div)
{
	while (div && v % div) 
		div--;

	return (div);
}

int isdupstr(const char *s, const char *pattern, int len)
{
	int dupcnt;

	dupcnt = strlen(s) / len;
	while (dupcnt-- && strncmp(s, pattern, len) == 0)
		s += len;

	return (n < 0 ? 1 : 0);
}

int isdiv(int v, int div)
{
	return ((v % div) ? 0 : 1);
} 


