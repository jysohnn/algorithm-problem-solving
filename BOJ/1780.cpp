#include <cstdio>

int n;
int a[2189][2189];
int sol[3];

void check(int xs, int xe, int ys, int ye)
{
	bool sameColor = true;
	int shape = a[xs][ys];
	for(int i=xs;i<xe;i++)
		for(int j=ys;j<ye;j++)
			if (a[i][j] != shape)
			{
				sameColor = false;
				break;
			}
	if (sameColor) sol[shape + 1]++;
	else
	{
		int term = (xe - xs) / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) 
				check(xs + term * i, xs + term * (i + 1), ys + term * j, ys + term * (j + 1));
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d",&(a[i][j]));
	check(0, n, 0, n);
	for (int i = 0; i < 3; i++) printf("%d\n",sol[i]);
	return 0;
}