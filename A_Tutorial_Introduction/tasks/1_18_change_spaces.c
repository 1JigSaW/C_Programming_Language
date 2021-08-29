/*
 Упражнение 1.18. Напишите программу, которая будет в каждой вводимой строке заменять стоящие подряд символы пробелов и табуляций на один пробел и удалять пустые строки.
*/

#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len; 
	int max; 
	int i;
	char line[MAXLINE]; 
	char longest[MAXLINE]; 
	max = 0;
	while ((len = mgetline(line, MAXLINE)) > 0)
    	{
		len = len - 1;
        	for (i = len - 1; i >= 0; --i)
		{
			if (line[i] == ' ' || line[i] == '\t')
                		len = len - 1;
            		else
                		i = 0;
		}
	}
        for (i = 0; i < len; ++i)
            printf("%c", line[i]);
        printf("\n");
	
	printf("Длина строки new: %d\n", i);
}

int mgetline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
