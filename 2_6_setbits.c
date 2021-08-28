/*
Упражнение 2.6. Напишите функцию setbits(x, p, n, y), возвращающую значение x, в котором n
битов, начиная с p-й позиции, заменены на n правых разрядов из y (остальные биты не изменяются).
*/

#include <stdio.h>

unsigned setbits (unsigned x, int p, int n, unsigned y);

int main()
{	
	int x = 121;
	int y = 12;
	printf("%d", setbits(x, 1, 8, y));
}

unsigned setbits (unsigned x, int p, int n, unsigned y)
{
	int i, mask, j;
    	i = (x >> (y+1-n)) & ~(~0 << n);
    	mask = ~(((1 << n)-1) << (p+1-n));
    	j = mask & x;
    	return j | i << (p+1-n);
}
