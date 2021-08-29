#include <stdio.h>

/* копирование ввода на вывод; 1-я версия */

int main()
{
	int c;
	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
