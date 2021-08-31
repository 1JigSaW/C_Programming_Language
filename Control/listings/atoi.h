#include <ctype.h>
/* atoi: преобразование s в целое число; версия 2 */
int atoi(char s[])
{
	int i, n, sign;
	/* игнорировать символы-разделители */
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1: 1;
	if (s[i] == '+' || s[i] == '-') /* пропуск знака */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0' );
	return sign * n;
}
