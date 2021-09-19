/*
 Упражнение 5.13. Напишите программу tail, печатающую n последних введенных строк. По умолчанию
значение n равно 10, но при желании n можно задать с помощью аргумента. Обращение вида
tail -n
печатает n последних строк. Программа должна вести себя осмысленно при любых входных данных и любом
значении n. Напишите программу так, чтобы наилучшим образом использовать память; запоминание строк
организуйте, как в программе сортировки, описанной в параграфе 5.6, а не на основе двумерного массива с фиксированным размером строки.
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 50000
#define MAXLEN 10000

int mygetline(char *line, int max);

char *alloc(int);
void afree(char*);

main(int argc, char *argv[])
{
	int n;

	if (argc == 1)
		n = 10;
	else if (argc == 2 && (*++argv)[0] == '-') {
		n = atoi(*argv + 1);
		if (n < 1)
			n = 10;
	} else {
		printf("Usage: tail -n\n");
		return 1;
	}

	char line[MAXLEN], *lineptr[MAXLINES];
	int len;
	char *p;
	int lines = 0;

	while ((len = mygetline(line, MAXLEN)) > 0) {
		p = alloc(len + 1);
		strcpy(p, line);
		lineptr[lines++] = p;
	}


	int i = lines - n;
	i = (i >= 0) ? i : 0;

	while (n-- > 0 && i <= lines) {
		printf("%s", lineptr[i++]);
	}

	return 0;
}

