/*
 Упражнение 1.4. Напишите программу, которая будет печатать таблицу соответствия температур по Цельсию
 температурам по Фаренгейту.
*/

#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -50; /* нижняя граница таблицы температур */
	upper = 50; /* верхняя граница */
	step = 2; /* шаг */

	celsius = lower;
	printf("Celsius => Fahrenheit\n");
	while (celsius <= upper) {
		fahr = ((9.0 / 5.0) * celsius) + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
