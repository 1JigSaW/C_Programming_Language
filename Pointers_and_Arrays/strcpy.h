/* strcpy: копирует t в s; вариант с индексируемым массивом*/
void strcpy(char *s, char *t)
{
	int i;
	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}
