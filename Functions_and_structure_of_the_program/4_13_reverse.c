/*
 Упражнение 4.13. Напишите рекурсивную версию функции reverse(s), переставляющую элементы строки
в ту же строку в обратном порядке.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[], char s2[], int n)
{		
	if (n != 0) {
		s2[strlen(s)-n-1] = s[n];
		reverse(s, s2, n-1);
	}
	s2[strlen(s)-n-1] = s[n];
}


int main()
{
	char s[] = "12345";
	char s2[100];
	int n = strlen(s) - 1;
	reverse(s, s2, n);
	printf("%s", s2);
}
