#include <stdlib.h>
#include <stdio.h>

char *mergeAlternately(char * word1, char * word2){
    char *ret;
    int maxlen;
    int i;

    i = 0;

    while (*(word1 + i) && *(word2 + i))
        i++;

    maxlen = i;

    if (*(word1 + i))
        while (*(word1 + i))
			i++;

    if (*(word2 + i))
        while (*(word2 + i))
			i++;
    
    maxlen += i;
    ret = (char *)malloc((maxlen + 1) * sizeof(char));
    *(ret + maxlen) = 0;
    
    i = 0;
    while (i < maxlen) {
        if (*word1) {
            *(ret + i) = *word1;
            i++;
            word1++;
        }
        if (*word2) {
            *(ret + i) = *word2;
            i++;
            word2++;
        }
    }

    return (ret);
}

int main(void)
{
	char *ret = mergeAlternately("HI", "hello");
	printf("%s", ret);
	free(ret);
}
