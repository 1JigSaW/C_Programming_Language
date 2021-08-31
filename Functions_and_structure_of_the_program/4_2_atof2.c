/*
 Упражнение 4.2. Дополните функцию atof таким образом, чтобы она справлялась с числами вида
123.456e-6 в которых после мантиссы может стоять е (или Е) с последующим порядком (быть может, со знаком).
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 100

double atof (char s[])
{
	double val, power;
	int i, j, sign, exp, k, m, new_exp;
	new_exp = 1;
	for (i = 0; isspace(s[i]); i++)
		; 
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit (s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	for (k = 0; s[k] != '\0'; k++) {
                if (s[k] == 'e' || s[k] == 'E') {
			exp = s[k+2] - '0';
			for (m = 0; m < exp; m++)
				new_exp *= 10;
		}
	}
	return (sign * val / power) / new_exp;
}

int mgetline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n' )
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int main()
{
	double sum, atof (char[]);
	char line[MAXLINE];
	int mgetline (char line[], int max);
	sum = 0;
	while (mgetline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}
