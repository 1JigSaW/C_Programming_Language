#include <stdio.h>
/* эхо аргументов командной строки: версия 1 */
int main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", ++argv[i], (i  argc-1) ? " " : "");
	printf("\n");
	return 0;
}
