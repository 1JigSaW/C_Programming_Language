/*
 Упражнение 3.6. Напишите версию itoa с дополнительным третьим аргументом, задающим минимальную ширину поля. При необходимости преобразованное число должно слева дополняться пробелами.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
	long int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(long int n, char s[], int w)
{
	long int i, sign;
	if ((sign = n) < 0) 
		n = -n; 
	i = 0;
	do { 
		s[i++] = n % 10 + '0'; 
	} while ((n /= 10) > 0); 
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	int len = strlen(s);
	if (strlen(s) > w) {
		s[w + 1] = '\0';
	} else {
		int j = 0;
		do {
			s[j+len] = s[j];
			s[j] = '_';
			j++;
		} while (j != (w - len));
	}
}

int main() 
{
	long int n = -182;
	char s[1000];
	int w = 8;
	itoa(n, s, w);
	printf("%s", s);
	return 0;
}
