/* strcpy: копирует t в s; версия 2 (с указателями) */
void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}
