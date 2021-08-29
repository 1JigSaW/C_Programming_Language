/*
 Упражнение 2.З. Напишите функцию htol(s), которая преобразует последовательность
шестнадцатеричных цифр, начинающуюся с 0х или 0Х, в соответствующее целое. Шестнадцатеричными
цифрами являются символы 0…9, а…f, А…F.
*/

#include <stdio.h>
#include <math.h>

int htol(char s[]);

int main() 
{	
	int n = htol("0x45F");
	printf("%d", n);
}

int htol(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; ; ++i) {
		if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
			i++;
			continue;
		}
		
		if (s[i] >= '0' && s[i] <= '9') {
			n = 16 * n + (s[i] - '0');
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			n = 16 * n + (s[i] - 'a' + 10);
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			n = 16 * n + (s[i] - 'A' + 10);
		} else {
			break;
		}
	}
	return n;
}
