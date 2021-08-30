/*
 Упражнение 3.3. Напишите функцию expand(s1, s2), заменяющую сокращенную запись наподобие a-z в строке s1 эквивалентной полной записью abc. . . xyz в s2. В s1 допускаются буквы (прописные и строчные) и цифры. Следует уметь справляться с такими случаями, как a-b-c, a-z0-9 и -а-b. Считайте знак - в начале или в конце s1 обычным символом минус.
*/

#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[])
{
	int i, j, k;

	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
			int p = s1[i-1];
			int n = s1[i+1];
			if (p < n && 
				((p >= 'a' && n <= 'z') || (p >= 'A' && n <= 'Z') || (p >= '0' && n <= '9'))
			) {
				for (k = p + 1; k < n; k++)
					s2[j++] = k;
			} else {
				s2[j++] = s1[i];
			}
		} else {
			s2[j++] = s1[i];
		}
	}

	s2[j] = '\0';
}

int main()
{
	char s1[] = "-a-z-A-Z-0-9-asd-5-5-5-9a-ZZ-A-G-N-T-Z";
	char s2[100];
	expand(s1, s2);
	printf("%s\n", s2);

	char s[] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
	char t[100];
	expand(s, t);
	printf("%s\n", t);
}
