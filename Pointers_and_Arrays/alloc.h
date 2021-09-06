#define ALLOCSIZE 10000 /* размер доступного пространства */

static char allocbuf[ALLOCSIZE]; /* память для alloc */
static char *allocp = allocbuf; /* указатель на своб. место */

char *alloc(int n) /* возвращает указатель на n символов */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n; /* пространство есть */
		return allocp - n; /* старое р */
	} else /* пространства нет */
		return 0;
}

void afree(char *p) /* освобождает память, на которую указывает р */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
