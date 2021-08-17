/*
 Упражнение 1.14. Напишите программу, печатающую гистограммы частот встречаемости вводимых
 символов.
*/

#include <stdio.h>

int main()
{
	int c = 0;
	int arr[127];
	for (int i = 0; i < 128; i++)
		arr[i] = 0;
	while ((c = getchar()) != EOF)
    	{
        	if (c < 128)    
			++arr[c]; 
    	}
     
    	for (int i = 32; i < 127; ++i)
    	{
		if (arr[i] > 0) {
            		printf("\"");
            		putchar(i); 
            		printf("\": ");
            		for (int j = 1; j <= arr[i]; ++j)
                		printf("#");
            		printf("\n");
        	}
    	}

    	return 0;
}



