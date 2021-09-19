//Упражнение 5.19. Модифицируйте undcl так, чтобы она не генерировала лишних скобок.

#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;	// type of last token
char token[MAXTOKEN];	// last token string
char out[1000];	// output string

// gcc 44.undcl.c getch.c
// cat 44.undcl.test | ./a.out
int main()
{
	int type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n') {
			if (type == PARENS) {
				if (out[0] == '*') {
					sprintf(temp, "(%s)", out);
					strcpy(out, temp);
				}
				strcat(out, token);
			} else if (type == BRACKETS) {
				if (out[0] == '*' || strstr(out, "()") != NULL) {
					sprintf(temp, "(%s)", out);
					strcpy(out, temp);
				}
				strcat(out, token);
			} else if (type == '*') {
				sprintf(temp, "*%s", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
		}

		printf("%s\n", out);
	}
	return 0;
}


int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
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
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}
