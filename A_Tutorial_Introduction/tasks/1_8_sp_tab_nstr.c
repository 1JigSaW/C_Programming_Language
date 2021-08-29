/* Упражнение 1.8. Напишите программу для подсчета пробелов, табуляций и новых строк. */

#include <stdio.h>


/* подсчет строк входного потока */
int main()
{
	int c, nl, ns, nt;
	nl = 0;
	ns = 0;
	nt = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++nt;
		else if (c == ' ')
			++ns;
	printf("%d\n", nl);
	printf("%d\n", nt);
	printf("%d\n", ns);
}
