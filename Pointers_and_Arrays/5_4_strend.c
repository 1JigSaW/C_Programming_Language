/*
 Упражнение 5.4. Напишите функцию strend(s, t), которая выдает 1, если строка t расположена в конце
строки s, и нуль в противном случае.
*/

#include <stdio.h>

int m_strend(char *s, char *t)
{
	while (*s++)
		if (*s++ == *t++) 
			if (*t == '\0')
				return 1;
	return 0;
}

int main()
{
	char s[] = "hello friend";
	char t[] = "friend";
	printf("%d\n", m_strend(s, t));
	char s2[] = "hello lol";
        char t2[] = "friend";
        printf("%d\n", m_strend(s2, t2));
}
