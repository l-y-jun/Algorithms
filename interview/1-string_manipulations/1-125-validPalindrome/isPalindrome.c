#include <string.h>
#include <stdbool.h>
#include <stdio.h>

char getAlnum(char *pt);

bool isPalindrome(char* s) {
    char *backchar_pt;
    char *frontchar_pt;

    frontchar_pt = s;
    backchar_pt = s + strlen(s) - 1;

    /* is backchar pointer have Same or Lower than frontchar pt? */
    while (frontchar_pt < backchar_pt)
    { 
        /* not comparable ? then, skip 1 */
        if (!getAlnum(frontchar_pt)) {
            frontchar_pt++;
        /* not comparable ? then, skip 1 */
        } else if (!getAlnum(backchar_pt)) {
            backchar_pt--;
        /* comparable */
        } else {
            /* Equal Alnum ? them skip 1 each*/
            if (*frontchar_pt == *backchar_pt) {
                frontchar_pt++;
                backchar_pt--;
            /* Not Palindrome, return 0*/
            } else {
                return (false);
            }
        }  
    }

    /* Palindrome for pair sets*/
    return (true);
}

char getAlnum(char *pt)
{
    char ch;

    ch = *pt;

    if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') // loweralpha or num
        return (*pt);

    if (ch >= 'A' && ch <= 'Z') { // upperalpha to lower
        *pt += 32;
        return (*pt);
    }

    return ('\0'); // not alnum
}

int main(void)
{
    char str[] = "a man, a plan, a canal,: Panama";
    printf("%d\n", strlen(str));
    printf("%s\n", isPalindrome(str) ? "True" : "False");
}

