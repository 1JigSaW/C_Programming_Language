/*
 Упражнение 1.15. Перепишите программу преобразования температур, выделив само преобразование в отдельную функцию.
*/

#include <stdio.h>

int celsius(float fahr);
int fahrenheit(float cels);

int main()
{
	for (float i = 0.0; i < 10.0; i++){
		celsius(i);
		fahrenheit(i);
	}
}

int celsius(float fahr)
{
	float celsius;
	celsius = (5.0/9.0)*(fahr - 32.0);
	printf("%3.0f\t%6.1f\n", fahr, celsius);
}

int fahrenheit(float cels)
{
	float fahr;
	fahr = (9.0/5.0)*cels + 32.0;
	printf("%6.1f\t%3.0f\n", fahr, cels);
}


