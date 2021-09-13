/*
 Упражнение 5.11. Усовершенствуйте программы entab и detab (см. упражнения 1.20 и 1.21) таким
образом, чтобы через аргументы можно было задавать список "стопов" табуляции.
*/

#include <stdio.h>

#define MAXLINE 1000
#define STOP 5

int main()
{
	int len;
    	char line[MAXLINE];
    	int i, j, l;
    	int ntab = 0;
    	int nspaces = 0;
    	int spaces = 0;

	if (argc == 1)
		tabstop = 8;
	else if (argc == 2)
		tabstop = atoi(*++argv);
	else {
		printf("Usage entab (8)(tabstop)\n");
		return 1;
	}

   	while((len = getchar()) > 0)
    	{
        	for(i = 0; line[i] != '\n'; ++i)
        	{
            		if (line[i] == ' ')
            		{
                		++spaces;
                		if (line[i + 1] != ' ')
                		{
                    			ntab = spaces/STOP;
                    			nspaces = spaces%STOP;
                    			spaces = 0;
                    			for (j = 0; j < ntab; ++j)
                        			putchar('|');
                    			for (l = 0; l < nspaces; ++l)
                        			putchar('\\');
                		}
            		}
            		if (line[i] != ' ')
            			putchar(line[i]);
        	}
    	}
    	return 0;
}
