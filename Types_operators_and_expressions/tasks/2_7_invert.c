/*
 Упражнение 2.7. Напишите функцию invert(х, р, n), возвращающую значение x с инвертированными
n битами, начиная с позиции p (остальные биты не изменяются).
*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
	printf("%d", invert(9, 3, 5));
	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	return x^(~(~0<<n)<<(p+1-n));
}
