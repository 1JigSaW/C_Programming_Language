#include <stdio.h>

#define MAXLINE 10 /* максимальный размер вводимой строки */

int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	char temp[MAXLINE];

	int wait;
    	wait = 0;

    	int iNt; /* промежуточная длина текстового потока */
    	iNt = 0;

    	int i; /* для for-цикла */
    	for (i = 0; i < MAXLINE; ++i)
        	line[i] = longest[i] = temp[i] = 0;

    	max = 0;
    	/* есть ли еще строка */
    	while ((len = mgetline(line, MAXLINE)) > 0 )
    	{
        	if(line[len-1] != '\n')
        	{
            	if (wait == 0)
                	copy(temp, line);
            	iNt = iNt + len;
            	if (max < iNt)
                	max = iNt;
            	wait = 1;
        	}

        	else
        	{
            	if (wait == 1)
            	{
                	if (max < (iNt + len))
                	{
                    	max = iNt + len;
                    	copy(longest, temp);
                	}
                	wait = 0;
            	}
            	else if (len > max)
            	{
                	max = len;
                	copy(longest, line);
            	}
            	iNt = 0;
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
