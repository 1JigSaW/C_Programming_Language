/* strcpy: копирует t в s: версия 1 (с указателями) */
void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}
