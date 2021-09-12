/*
 Упражйение 5.8. В функциях day_of_year и month_day нет никаких проверок правильности вводимых
дат. Устраните этот недостаток.
*/

#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: определяет день года по месяцу и дню */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	if (year > 0 && month > 0 && month < 13 && day > 0 && day < 32) {
		leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
		for (i = 1;i < month; i++)
			day += daytab[leap][i];
		return day;
	} else {
		return -1;
	}
}

/* month_day: определяет месяц и день по дню года */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	if (year > 0 && yearday < 367) {
		int i, leap;
		leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
		for (i = 1; yearday > daytab[leap][i]; i++)
			yearday -= daytab[leap][i];
		*pmonth = i;
		*pday = yearday;
	} else {
		printf("incorrect date");
	}
}

int main()
{	
	int pmonth = 0;
	int pday = 0;
	printf("%d\n", day_of_year(1986, 2, 5));
	month_day(1954, 322, int *pmonth, int *pday);
	printf("%d, %d\n", &pmonth, &pday);
}
