#include <stdio.h>

/* подсчет вводимых символов; 1-я версия */
int main()
{
	long nc;
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
