#include <stdarg.h>
/* minprintf: минимальный printf с переменным числом аргумент */
void minprintf(char *fmt, ...)
{
	va_list ар; /* указывает на очередной безымянный аргумент */
	char *p, *sval;
	int ival;
	double dval;
	va_start(ap, fmt); /* устанавливает ар на 1-й безымянный аргумент */
	for (p = fmt; *р; р++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		switch (*++р) {
			case 'd':
			ival = va_arg(ap, int);
			printf ("%d", ival);
			break;
			case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
					break;
			default:
				putchar(*p);
				break;
		}
	}
va_end(ap); 

}
