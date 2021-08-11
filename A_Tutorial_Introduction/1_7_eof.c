/* Упражнение 1.7. Напишите программу, печатающую значение EOF. */

#include <stdio.h>

int main()
{
	int c;
	while ((c = getchar()) != EOF)
		putchar(EOF);
}
