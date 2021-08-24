/*
 Упражнение 2.1. Напишите программу, которая будет выдавать диапазоны значений типов char, short, int и long, описанных как signed и как unsigned, с помощью печати соответствующих значений из стандартных заголовочных файлов и путем прямого вычисления. Определите диапазоны чисел с пла ающей точкой различных типов. Вычислить эти диапазоны сложнее.
*/

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>

int main() 
{
	printf("limits.h\n");	
	printf("INT: %d - %d\n", INT_MIN, INT_MAX);
	printf("CHAR: %d - %d\n", CHAR_MIN, CHAR_MAX);
	printf("SHORT: %d - %d\n", SHRT_MIN, SHRT_MAX);
	printf("LONG: %ld - %ld\n", LONG_MIN, LONG_MAX);
	printf("UNSIGNED INT: %d - %u\n", 0, UINT_MAX);
	printf("UNSIGNED CHAR: %d - %d\n", 0, UCHAR_MAX);
	printf("UNSIGNED SHORT: %d - %d\n", 0, USHRT_MAX);
	printf("UNSIGNED LONG: %d - %lu\n\n", 0, ULONG_MAX);

	printf("computations\n");
	printf("INT: -%.f - %.f\n", pow(2, sizeof(int)*8)/2, pow(2, sizeof(int)*8)/2-1);
	printf("CHAR: -%.f - %.f\n", pow(2, sizeof(char)*8)/2, pow(2, sizeof(char)*8)/2-1);
	printf("SHORT: -%.f - %.f\n", pow(2, sizeof(short)*8)/2, pow(2, sizeof(short)*8)/2-1);
	printf("LONG: -%.f - %.f\n", pow(2, sizeof(long)*8)/2, pow(2, sizeof(long)*8)/2-2);
	printf("UNSIGNED INT: %d - %.f\n", 0, pow(2, sizeof(int)*8)-1);
	printf("UNSIGNED CHAR: %d - %.f\n", 0, pow(2, sizeof(char)*8)-1);
	printf("UNSIGNED SHORT: %d - %.f\n", 0, pow(2, sizeof(short)*8)-1);
	printf("UNSIGNED LONG: %d - %.f\n", 0, pow(2, sizeof(long)*8)-2);

}	
