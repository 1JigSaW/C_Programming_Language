/*
 Упражнение 5.2. Напишите функцию getfloat — аналог getint для чисел с плавающей точкой. Какой тип
будет иметь результирующее значение, выдаваемое функцией getfloat?
*/

#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; /* буфер для ungetch */
int bufp = 0; /* след, свободная позиция в буфере */

int getch(void) /* взять (возможно возвращенный) символ */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* вернуть символ на ввод */
{
	if (bufp >= BUFSIZE)
		printf ("ungetch: слишком много символов\n");
	else
		buf[bufp++] = c;
}

float getfloat(float *pn)
{
	float c, sign;
	while (isspace(c = getch()))
		; /* пропуск символов-разделителей */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* не число */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch(sign == 1 ? '+' : '-');
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main()
{
	int n;
    	float array[10], r;

    	for (n = 0; n < 10 && (r = getfloat(&array[n])) != EOF; n++) {
        	if (r)
            		printf("you input a number: %g\n", array[n]);
        	else
            		printf("it is not a number.\n");
    	}

    	return 0;
}
