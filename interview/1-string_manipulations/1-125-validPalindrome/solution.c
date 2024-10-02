#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

bool isPalindrome(char *s)
{
    int left = 0;
    int right = 1;

    int str_len = strlen(s);
    for (int i = 0; i < str_len; i++) {
        while (!isalnum(s[i + left])) {
            left++;
            if (i + left == str_len)
                return true;
        }

        while (!isalnum(s[str_len - i - right])) {
            right++;
        }
        printf("%d, left: %d, right: %d\n" ,i, i + left, str_len - i - right);
        // At this point left right on alnum for each side
        
        if (i + left >= str_len - i - right)
            break;

        if (tolower(s[i + left]) != tolower(s[str_len - i - right])) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    char str[] = "a man, a plan, a canal,: Panama";
    printf("%d\n", strlen(str));
    isPalindrome(str);
}

