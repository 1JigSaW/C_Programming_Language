/*
 Упражнение 3.1. В нашей программе бинарного поиска внутри цикла осуществляются две проверки, хотя могла быть только одна (при увеличении числа проверок вне цикла). Напишите программу, предусмотрев в ней одну проверку внутри цикла. Оцените разницу во времени выполнения.
*/

#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (x < mid)
		x += 1;
	else
		x -= 1;
	return mid; 
}

int main() 
{
	time_t start,end;
	start = time(NULL);
	int n = 10;
	int v[n];
	for (int i = 0; i <= n; i++)
		v[i] = i;
	printf("%d\n", binsearch(3, v, n));
	end = time(NULL);
	printf("Цикл использовал %.20lf секунд.\n", difftime(end, start));
}
