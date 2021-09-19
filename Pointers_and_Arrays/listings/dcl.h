#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS };

/* dcl: разбор объявителя */
void dcl(void)
{
	int ns;
	for (ns = 0; gettoken() == '*'; ) /* подсчет звездочек */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " указ. на");
}

/* dirdcl: разбор собственно объявителя */
void dlrdcl(void)
{
	int type;
	if (tokentype == '(') { /* ( dcl ) */
		dcl();
		if (tokentype != ')')
			printf( "ошибка: пропущена )\n");
	} else if (tokentype == NAME) /* имя переменной */
		strcpy(name, token);
	else
		printf("ошибка: должно быть name или (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " функц. возвр.");
		else {
			strcat(out, " массив");
			strcat(out, token);
			strcat(out, " из");
		}
}

int gettoken(void) /* возвращает следующую лексему */
{
	int с, getch(void);
	void ungetch(int);
	char *p = token;
	while ((c = getch()) == ' ' || с == ' \ t ' )
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0' ;
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

int tokentype; /* тип последней лексемы */
char token[MAXTOKEN]; /* текст последней лексемы */
char name[MAXTOKEN]; /* имя */
char datatype[MAXTOKEN]; /* тип = char, int и т.д. */
char out[1000]; /* выдаваемый текст */

int main() /* преобразование объявления в словесное описание */
{
	int type;
	char temp[MAXTOKEN];
	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(qut, token);
			else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf ("неверный элемент %s в фразе\n", token);
		printf("%s\n", out);
	}
	return 0;
}

