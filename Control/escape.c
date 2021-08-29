/*
 Упражнение 3.2. Напишите функцию escape(s, t), которая при копировании текста из t в s преобразует такие символы, как новая строка и табуляция в "видимые последовательности символов" (вроде \n и \t). Используйте инструкцию switch. Напишите функцию, выполняющую обратное преобразование эскейп-последовательностей в настоящие символы.
*/

#include <stdio.h>

void escape(char s[], char t[]) {
	flag = 0;
	for (int i = j = 0; t[i] != 0; i++) {
		switch (t[i]) {
			case '\\':
				flag = 1;
				break;
			case 't':
				if (flag) {
					s[j++] = '\t';
					flag = 0;
					break;
				}
			case 'n':
				if (flag) {
					s[j++] = '\n';
					flag = 0;
					break;
				}
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}

int main()
{
	char s[100];
	char t[100];
	int i = 0;
	while ((c = getchar()) != EOF)
        	t[i++] = c;
  	t[i] = '\0';
	escape(s, t);
	printf("%s", s);
	return 0;
}
