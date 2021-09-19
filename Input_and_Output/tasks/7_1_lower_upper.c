/*
Упражнение 7.1. Напишите программу, осуществляющую перевод ввода с верхнего регистра на нижний или с нижнего на верхний в зависимости от имени, по которому она вызывается и текст которого находится в argv[0].
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NOT_FOUND -1;

static int strindex(char s[], char t[]) {

    size_t i;
    size_t j;
    size_t k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ; // Empty
        if (k > 0 && t[k] == '\0')
            return (int)i;
    }

    return NOT_FOUND;
}

int main(int argc, char *argv[]) {

    int c;
    int (*func)(int) = (strindex(argv[0], "upper") < 0) ? tolower : toupper;

    while ((c = getchar()) != EOF)
        (void)putchar(func(c));

    return 0;
}

