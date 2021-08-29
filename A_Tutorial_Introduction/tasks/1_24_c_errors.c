/*
 Упражнение 1.24. Напишите программу, проверяющую Си-программы на элементарные синтаксические
ошибки вроде несбалансированности скобок всех видов. Не забудьте о кавычках (одиночных и двойных),
эскейп-последовательностях (\...) и комментариях. (Это сложная программа, если писать ее для общего
случая.)
*/

#include <stdio.h>

#define SIZE 100

int main()
{
	int i = 0;
       	int arr[SIZE];
	int flag = 0;
	int flag2 = 0;
	int flag3 = 0;
	int flag4 = 1;
	int flag5 = 1;
	int flag6 = 0;
    
    	for(i = 0; i < SIZE; ++i)
        	arr[i] = getchar();
    
    	for(i = 0; i < SIZE; ++i)
		if (arr[i] == '(') 
			flag++;
		else if (arr[i] == ')')
			flag--;
		else if (arr[i] == '[')
			flag2++;
		else if (arr[i] == ']')
			flag2--;
		else if (arr[i] == '{')
			flag3++;
		else if (arr[i] == '}')
			flag3--;
		else if (arr[i] == '\"')
			flag4 *= -1;
		else if (arr[i] == '\'')
			flag5 *= -1;
		else if (arr[i] == '/' && arr[i+1] == '*')
			flag6++;
		else if (arr[i] == '*' && arr[i+1] == '\\')
			flag6--;
	if (flag != 0)
		printf("brackets:() are not closed");
	else if (flag2 != 0)
		printf("brackets:[] are not closed");
	else if (flag3 != 0)
		printf("brackets:{} are not closed");
	else if (flag4 != 1)
                printf("quotes:\"\" are not closed");
	else if (flag5 != 1)
                printf("quotes:'' are not closed");
	else if (flag6!= 0)
                printf("comments:/**\\ are not closed");


   	printf("\n");
    
    	return 0;
}

