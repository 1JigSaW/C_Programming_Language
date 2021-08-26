/*
 Упражнение 2.4. Напишите версию функции squeeze(s1, s2), которая удаляет из s1 все символы,
встречающиеся в строке s2.
*/

#include <stdio.h>

void m_squeeze(char s1[], char s2[]);

int main()
{
	char s1[4] = {'a', 'b', 'c', 'o'};
	char s2[4] = {'a', 'b', 'h'};
	m_squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;
}

void m_squeeze(char s[], char t[])
{
	if (t[0] == '\0')
		return;

	int i ,j, k;
	int same;

	for (i = j = 0; s[i] != '\0'; i++) {
		same = 1;

		for (k = 0; t[k] != '\0'; k++) {
			if (s[i+k] == '\0') {
				same = 0;
				break;
			}


			if (t[k] != s[i+k]) {
				same = 0;
				break;
			}
		}

		if (same == 1) {
			i += k - 1;
		} else {
			s[j++] = s[i];
		}
	}

	s[j] = '\0';
}
