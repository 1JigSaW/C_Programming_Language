/*
 Упражнение 1.2. Выясните, что произойдет, если в строковую константу аргумента printf вставить \с, г	де с — символ, не входящий в представленный выше список.
*/

#include <stdlib.h>
#include <stdio.h>

int main() 
{
	printf("Hello,\t world!\n");
	printf("Hello,\a world!\n");
	printf("Hello,\b world!\n");
	printf("Hello,\n world!\n");
	printf("Hello,\v world!\n");
	printf("Hello,\f world!\n");
	printf("Hello,\r world!\n");
	printf("Hello,\? world!\n");
	printf("Hello,\\ world!\n");
	printf("Hello,\" world!\n");
	printf("Hello,\52 world!\n");
	printf("Hello,\x2A world!\n");
	/*printf("Hello,\c world!\n");*/
}
