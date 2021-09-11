/*
 Упражнение 4.1. Напишите функцию strindex(s, t), которая выдает позицию самого правого вхождения t в s или -1, если вхождения не обнаружено.
*/

#include <stdio.h>

int strindex(char s[], char t[])
{
	int i, j, k, res;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0') {
			res = i;
			continue;
		}

	}
	if (res)
		return res;
	else
		return -1;
}

int main() 
{
	char s[] = "hello lol aa dd ff lol yytr";
	char t[] = "lol";
	printf("%d\n", strindex(s, t));
}
