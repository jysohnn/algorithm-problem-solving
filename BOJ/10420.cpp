#include <cstdio>

int n;
int y = 2014, m = 4, d = 2;
int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	scanf("%d", &n);
	n--;
	while (n--)
	{
		if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) days[2] = 29;
		else days[2] = 28;
		d++;
		if (d > days[m]) d -= days[m], m++;
		if (m > 12) m -= 12, y++;
	}
	printf("%d-%02d-%02d",y,m,d);
	return 0;
}