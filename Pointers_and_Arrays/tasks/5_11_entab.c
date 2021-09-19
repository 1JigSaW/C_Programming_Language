/*
 Упражнение 5.11. Усовершенствуйте программы entab и detab (см. упражнения 1.20 и 1.21) таким
образом, чтобы через аргументы можно было задавать список "стопов" табуляции.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int c, n, i;
	int cur;

	if (argc == 1)
		n = 8;
	else if (argc == 2)
		n = atoi(*++argv);
	else {
		printf("Usage: detab (8)(tab stop)\n");
		return 1;
	}

	cur = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = n - cur; i > 0; --i)
				putchar(' ');
			cur = 0;
		} else {
			putchar(c);
			cur++;
			if (cur > n)
				cur = 0;
		}
	}

}
