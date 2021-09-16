#include <stdio.h>
#include <ctype. h>
#include <string.h>

#define MAXWORD 100


struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
/* подсчет частоты встречаемости слов */
int main()
{
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while (getword (word, MAXWORD) != EOF)
		if (lsalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

struct tnode { /* узел дерева */
	char *word; /* указатель на текст */
	int count; /* число вхождений */
	struct tnode *left; /* левый сын */
	struct tnode *right; /* правый сын */
};

struct tnode *talloc(void);
char *strdup(char *);

/* addtree: добавляет узел со словом w в р или ниже него */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	if (p == NULL) { /* слово встречается впервые */
		р = talloc(); /* создается новый узел */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++; /* это слово уже встречалось */
	else if (cond < 0) /* меньше корня левого поддерева */
		p->left = addtree(p->left, w);
	else /* больше корня правого поддерева */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: упорядоченная печать дерева р */
void treeprint(struct tnode *p)
{
	if (р != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

#include <stdlib.h>
/* talloc: создает tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s) /* делает дубликат s */
{
	char *p;
	p = (char *) malloc(strlen(s)+1); /* +1 для '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}
