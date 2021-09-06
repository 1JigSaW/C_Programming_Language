/*
 Упражнение 5.3. Используя указатели, напишите функцию strcat, которую мы рассматривали в главе 2
(функция strcat(s, t) копирует строку t в конец строки s).
*/

#include <stdio.h>

void m_strcat(char *s, char *t)
{
	while (*s++)
		if (*s == '\0') 
			while(*s++ = *t++)
				;
}

int main()
{
	char s[] = "hello ";
	char t[] = "friend";
	m_strcat(s, t);
	printf("%s\n", s);
}
