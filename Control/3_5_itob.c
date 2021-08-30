/*
 Упражнение 3.5. Напишите функцию itob(n, s, b), которая переводит целое n в строку s,
представляющую число по основанию b. В частности, itob(n, s, 16) помещает в s текст числа n в
шестнадцатеричном виде.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
	long int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itob(long int n, char s[], int b)
{
	long int i, sign;
	if ((sign = n) < 0) 
		n = -n; 
	i = 0;
	int numb = n;
	int ost = 0;
	int nn = 0;
	do {	
		nn = numb;
		numb /= b;
		ost = nn % b;
	       	if (ost == 10 && b > 9)
			s[i++] = 'A';
		else if (ost == 11 && b > 9)
			s[i++] = 'B';
		else if (ost == 12 && b > 9)
			s[i++] = 'C';
		else if (ost == 13 && b > 9)
			s[i++] = 'D';
		else if (ost == 14 && b > 9)
			s[i++] = 'E';
		else if (ost == 15 && b > 9)
			s[i++] = 'F';
		else 				
			s[i++] = ost + '0';
			    
	} while (numb > b); 
	s[i++] = numb + '0';
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	int n = 36752;
	char s[100];
	int b = 16;
	itob(n, s, b);
	printf("%s\n", s);

	int n2 = 443;
        char s2[100];
        int b2 = 5;
        itob(n2, s2, b2);
        printf("%s\n", s2);

	int n3 = 1187;
        char s3[100];
        int b3 = 9;
        itob(n3, s3, b3);
        printf("%s\n", s3);

}
