#include <stdio.h>

char a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char b[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[2] = {a, b};

/* day_of_year: определяет день года по месяцу и дню */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	char *p = daytab[leap] + 1;
	for (i = 1;i < month; i++)
		day += *p++;
	return day;
}

/* month_day: определяет месяц и день по дню года */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	char *p = daytab[leap] + 1;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= *p++;
	*pmonth = i;
	*pday = yearday;
}

int main()
{
	int day_of_year(int, int, int);
	void month_day(int, int, int*, int*);

	int day = day_of_year(2018, 8, 19);
	printf("%d\n", day);

	int month;
	month_day(2018, 231, &month, &day);
	printf("%d, %d\n", month, day);
}
