/*
 Упражнение 5.6. Отберите подходящие программы из предыдущих глав и упражнений и перепишите их,
используя вместо индексирования указатели. Подойдут, в частности, программы getline (главы 1 и 4),
atoi, itoa и их варианты (главы 2, 3 и 4), reverse (глава 3), а также strindex и getop (глава 4).
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* getline: читает строку в s, возвращает длину */
int m_getline(char *s, int lim)
{
	int c;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n' )
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return sizeof(s);
}

/* atoi: преобразование s в целое число; версия 2 */
int m_atoi(char *s)
{
	int i, n, sign;
	while (isspace(*s))
		*s++;
	sign = (*s == '-') ? -1: 1;
	if (*s == '+' || *s == '-') /* пропуск знака */
		*s++;
	n = 0;
	for (n = 0; isdigit(*s); *s++)
        	n = 10 * n + (*s -'0');
	return sign * n;
}

void m_reverse(char *s)
{
    char tmp, *p;
    p = s + strlen(s) - 1;
    while (p > s) {
        tmp = *s;
        *s++ = *p;
        *p-- = tmp;
    }
}


/* itoa: преобразование n в строку s */
void m_itoa (int n, char *s)
{
	int sign;
	char *new_s;
	new_s = s;
	if ((sign = n) < 0)
		n = -n; 
	do { 
		*new_s++ = n % 10 + '0'; 
	} while ((n /= 10) > 0); 
	if (sign < 0)
		*new_s++ = '-';
	*new_s = '\0';

	m_reverse(new_s);
}

/* strindex: вычисляет место t в s или выдает -1, если t нет в s */
int m_strindex (char *s, char *t)
{
	int i = 0;
	while (*s != '\0') {
		i++;
		while (*t++ != '\0' && *s++ == *t++)
			;
		if (*t == '\0')
			return i;
	}
	return -1;
}

#define BUFSIZE 100
#define NUMBER '0'
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

/* getop: получает следующий оператор или операнд */
int getop(char *s)
{
	int i, c;
	while ((*s = c = getch()) == ' ' || c == '\t' )
		;
	*s++ = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* не число */
	i = 0;
	if (isdigit(c)) /* накапливаем целую часть */
		while (isdigit(*s++ = c = getch()))
	;
	if (c == '.') /* накапливаем дробную часть */
		while (isdigit(*s++ = c = getch()))
			;
	*s = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int main()
{
	char s[1000];
	char s2[] = "124124";
	int n = 124214;
	char s3[1000];
	printf("\n%d\n", m_getline(s, 1000));
	printf("%d\n", m_atoi(s2));
	m_itoa(n, s3);
	printf("%s\n", s3);
	char s4[] = "dfsaflsd";
	char t4[] = "f";
	printf("%d\n", m_strindex(s4, t4));
	char s5[100];
	printf("%d\n", getop(s5));
}
