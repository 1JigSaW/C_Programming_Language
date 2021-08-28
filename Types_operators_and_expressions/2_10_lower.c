/*
 Упражнение 2.10. Напишите функцию lower, которая переводит большие буквы в малые, используя
условное выражение (а не конструкцию if-else).
*/

#include <stdio.h>

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int main()
{	
	printf("%c\n", lower('S'));
	return 0;
}

