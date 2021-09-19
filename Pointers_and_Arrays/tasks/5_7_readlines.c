#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* максимальное число строк */
char save[ARR_SIZE];
char *lineptr[MAXLINES]; /* указатели на строки */

int m_getline(char *s, int lim);
int readlines(char *lineptr[], int nlines);
void whitelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);


/* сортировка строк */
int main()
{
	int nlines; /* количество прочитанных строк */
	if ((nlines = readlines(lineptr, MAXLINES) >= 0)) {
		qsort(lineptr, 0, nlines-1);
		whitelines(lineptr, nlines);
		return 0;
	} else {
		printf("ошибка: слишком много строк\n");
		return 1;
	}
}

#define MAXLEN 1000 /* максимальная длина строки */

char *alloc(int);

/* readlines: чтение строк */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	int offset = 0;
	nlines = 0;
	while ((len = m_getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = &strstore[offset]) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* убираем символ \n */
			strcpy(p, line);
			offset += len;
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: печать строк */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* qsort: сортирует v[left]...v[right] по возрастанию */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) /* ничего не делается, если в массиве */
		return; /* менее двух элементов */
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: поменять местами v[i] и v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int m_getline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*t++ = c;

	if (c == '\n')
		*t++ = c;

	*t = '\0';
	return t - s;
}

