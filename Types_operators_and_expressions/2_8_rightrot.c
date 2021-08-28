/*
 Упражнение 2.8. Напишите функцию rightrot(х, n), которая циклически сдвигает x вправо на n
разрядов.
*/

#include <stdio.h>

unsigned rigthrot(unsigned x, int n);

int main()
{
	printf("%d", rightrot(9, 5));
}

unsigned rigthrot(unsigned x, int n)
{	
	int nn = 0;
	if (nn < n) {
		x = x << 1;
		nn += 1;
		rightrot(x, n);
	}
	return x;
}
