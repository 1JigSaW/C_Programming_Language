/*
 Упражнение 1.23. Напишите программу, убирающую все комментарии из любой Си-программы. Не забудьте
должным образом обработать строки символов и строковые константы. Комментарии в Си не могут быть
вложены друг в друга.
*/

#include <stdio.h>

int main()
{	
	int c;
	while ((c = getchar()) != EOF) {
		if (c == "//") {
			printf("%c", c);
		}
	}
	return 0;
}