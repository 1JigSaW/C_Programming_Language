#include <stdio.h>
#include <ctype.h>

int main() /* lower: переводит ввод на нижний регистр */
{
	int с;
	while ((с = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}
