/*
 Упражнение 2.6. Напишите функцию setbits(x, p, n, y), возвращающую значение x, в котором n
битов, начиная с p-й позиции, заменены на n правых разрядов из y (остальные биты не изменяются).
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main(void)
{
    printf("%u\n", setbits(170, 4, 3, 7));
    return 0;
}


unsigned setbits(unsigned x, int p, int n, int y)
{
    int i, mask, j;
    i = (x >> (y+1-n)) & ~(~0 << n);
    mask = ~(((1 << n)-1) << (p+1-n));
    j = mask & x;
    return j | i << (p+1-n);
}
