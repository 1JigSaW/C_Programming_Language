#include <stdio.h>

/* printd: печатает n как целое десятичное число */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');


}

int main()
{
	int n = -1234;
	char s[100];
	printd(n);
}
