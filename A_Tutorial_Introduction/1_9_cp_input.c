/* Упражнение 1.9. Напишите программу, копирующую символы ввода в выходной поток и заменяющую
стоящие подряд пробелы на один пробел. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    	int c, blank_recieved;
    	blank_recieved = 0;
    	printf("Input some characters, when you finishes, press Ctrl+D.\n");
    	while ((c = getchar()) != EOF)
       		if (c == ' ') {
            		if (!blank_recieved) {
                		blank_recieved = 1;
                		putchar(c);
           		 }
        	} else {
            		blank_recieved = 0;
            		putchar(c);
       		 }
}

