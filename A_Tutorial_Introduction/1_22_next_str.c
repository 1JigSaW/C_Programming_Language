/*
 Упражнение 1.22. Напишите программу, печатающую символы входного потока так, чтобы строки текста не
выходили правее n-й позиции. Это значит, что каждая строка, длина которой превышает n, должна печататься
с переносом на следующие строки. Место переноса следует "искать" после последнего символа, отличного от
символа-разделителя, расположенного левее n-й позиции. Позаботьтесь о том, чтобы ваша программа вела
себя разумно в случае очень длинных строк, а также когда до n-й позиции не встречается ни одного символа
пробела или табуляции.
*/

#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 8
#define LINE_WIDTH 10

int getchars(char s[], int maxline);
void fold(char s1[], char s2[], int linewidth, int tabwidth);

int main(void)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Input some characters, then press enter:\n");
    while (getchars(s1, MAXLINE) == 0)
        ;

    fold(s1, s2, LINE_WIDTH, TAB_WIDTH);
    printf("\nfold result:\n%s\n", s2);

    return 0;
}

int getchars(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
          s[l++] = c;
    s[l] = '\0';

    return l;
}

void fold(char s1[], char s2[], int lw, int tw)
{
    int i, l, c, k, w;

    w = 0;
    k = -1;
    i = l = 0;
    while ((c = s1[i]) != '\0') {
        if (c == ' ') {
            if (w + 1 == lw) {
                s2[l++] = '\n';
                w = 0;
                i = k;
            } else {
                s2[l++] = ' ';
                ++w;
            }
        } else if (c == '\t') {
            if (w + tw - w % tw >= lw) {
                s2[l++] = '\n';
                w = 0;
                i = k;
            } else {
                s2[l++] = '\t';
                w += tw;
            }
        } else {
            s2[l++] = c;
            if (w + 1 == lw) {
                s2[l++] = '\n';
                w = 0;
            } else {
                k = i;
                ++w;
            }
        }
        ++i;
    }
    s2[l++] = '\0';
}
