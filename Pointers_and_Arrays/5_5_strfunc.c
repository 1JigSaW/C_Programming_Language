/*
 Упражнение 5.5. Напишите варианты библиотечных функций strncpy, strncat и strncmp, которые
оперируют с первыми символами своих аргументов, число которых не превышает n. Например, strncpy
(t, s, n) копирует не более n символов t в s. Полные описания этих функций содержатся в приложении
В.
*/

#include <stdio.h>

void m_strncpy (char *t, char *s, int n)
{	
	int i = 1;
	while ((*s++ = *t++) != '\0' && i++ != n)
		;
}

void m_strncat (char *s, char *t, int n)
{	
	int i = 1;
	while (*s++) {
		if (*s == '\0') {
			while ((*s++ = *t++) && (i++ < n))
				;
			*s = '\0';
			break;
		}
	}
			
}
int m_strncmp(char *s, char *t, int n)
{
	int i = 1;
	for ( ; *s == *t; s++, t++)
		if (i++ == n)
			return 0;
	return *s - *t;
}

int main()
{
	char t[] = "My headphones";
	char s[100];
	int n = 7;
	m_strncpy (t, s, n);
	printf("%s\n", s);
	char s2[] = "My headphones ";
        char t2[] = "freedom";
        int n2 = 4;
        m_strncat (s2, t2, n2);
        printf("%s\n", s2);
	char s3[] = "fressales";
        char t3[] = "freedom";
        int n3 = 4;
        printf("%d\n", m_strncmp (s3, t3, n3));

}
	
