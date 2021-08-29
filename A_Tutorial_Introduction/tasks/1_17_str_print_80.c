/*
 Упражнение 1.17. Напишите программу печати всех вводимых строк, содержащих более 80 символов.*/

#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len; 
	int max; 
	char line[MAXLINE]; 
	char longest[MAXLINE]; 
	max = 0;
	while ((len = mgetline(line, MAXLINE)) > 0)
    	{
        	printf("%d\r\n", len); 
        	if ((len - 1) > 80)
        	{
            		copy(longest, line);
            		max = max + len;
			printf("%s", line);
        	}
    	}
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

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
