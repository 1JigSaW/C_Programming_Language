/*
 Упражнение 1.21. Напишите программу entab, заменяющую строки из пробелов минимальным числом
табуляций и пробелов таким образом, чтобы вид напечатанного текста не изменился. Используйте те же
"стопы" табуляции, что и в detab. В случае, когда для выхода на очередной "стоп" годится один пробел, что
лучше — пробел или табуляция?
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
