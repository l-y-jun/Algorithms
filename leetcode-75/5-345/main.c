#include <stdio.h>

void swap(char *s1, char *s2);
int isVowel(char s);

char *reverseVowels(char* s) {
    char *start;
    char *end;

    end = s;
    while (*(end + 1))
        end++;

    start = s;
    while (start < end) {
        while (start < end && !isVowel(*start))
            start++;

        while (start < end && !isVowel(*end))
            end--;

        if (start < end) {
            swap(start, end);
		}
		start++;
		end--;
    }

    return (s);
}

void swap(char *s1, char *s2)
{
    char temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int isVowel(char s) {
    char *vowels = "aeiouAEIOU\0";

    while(*vowels)
        if (s == *vowels++)
            return 1;

    return 0;
}

int main(void)
{
	char keys[] = "helloworld\0";
	printf("%s\n", keys);
	reverseVowels(keys);
	printf("%s\n", keys);
	return (0);
}
