#include <stdio.h>
#include <string.h>

char *getNextWord(char *w);
void reverseNstring(char *s, int n);
int wordlen(char *w);
char *movWord(char *dest, char *src);
void formatWords(char *s);

char* reverseWords(char* s) {
    char *word;

    formatWords(s);
    reverseNstring(s, strlen(s));

    word = s;
    while (word) {
        reverseNstring(word, wordlen(word));
        word = getNextWord(word);
    }

    return (s);
}

void formatWords(char *s)
{ // format " hi  this   " to "hi this" 
    char *frontWord;
    char *backWord;

    frontWord = (*s != ' ') ? s : getNextWord(s);
    backWord = getNextWord(frontWord);
    s = movWord(s, frontWord);

    while (backWord) {
        frontWord = backWord;
        backWord = getNextWord(backWord);
        s = *s ? movWord(s + 1, frontWord) : s;
        
    }
    *s = '\0';

    return ;
}

int wordlen(char *w)
{
    int i;

    i = 0;
    while (*(w + i) && *(w + i) != ' ')
        i++;

    return i;
}

void reverseNstring(char *s, int n) {
    // cleaned string only
    char *end;
    char tmp;
    end = s + (n - 1);

    while (end > s) {
        tmp = *s;
        *s++ = *end;
        *end-- = tmp;
    }
}

char *getNextWord(char *w)
{
    while (*w && (*w != ' ')) // skip current word
        w++;

    while(*w && (*w == ' ')) // skip blank next word
        w++;
    
    return ((*w) ? (w) : NULL); // word or NULL on EOF(last)
}

char *movWord(char *dest, char *src) 
{
    char ch;

    if (dest > src)
        return NULL;
    
    while (*src && *src != ' ') {
        ch = *src;
        *src++ = ' ';
        *dest++ = ch;
    }

    *dest = *dest ? ' ' : '\0';

    return dest;
}

int main(void)
{
	char str[]= "f string is s\0";
	
	reverseWords(str);
	printf("%s", str);
}
