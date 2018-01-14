#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
double x, y, z;
ll fac[21] = { 1,1 };
double plu[21] = { 0 };
double minu[21] = { 0 };
double bronze = 0, silver = 0, gold = 0, pla = 0, dia = 0;

int main()
{
	for (int i = 2; i < 21; i++) fac[i] = i * fac[i - 1];
	cin >> x >> y >> z;
	for (int i = 0; i <= 20; i++)
		for (int j = 0; j <= 20 - i; j++)
		{
			int k = 20 - i - j;
			int idx = i - j;
			if (idx < 0)
			{
				ll multi = fac[20] / (fac[i] * fac[j] * fac[k]);
				double sol = pow(x, i)*pow(y, j)*pow(z, k);
				sol *= (double)multi;
				minu[-idx] += sol;
			}
			else
			{
				ll multi = fac[20] / (fac[i] * fac[j] * fac[k]);
				double sol = pow(x, i)*pow(y, j)*pow(z, k);
				sol *= (double)multi;
				plu[idx] += sol;
			}
		}
	for (int i = 11; i <= 20; i++) bronze += minu[i];
	for (int i = 1; i < 11; i++) silver += minu[i];
	for (int i = 0; i < 10; i++) gold += plu[i];
	for (int i = 10; i < 20; i++) pla += plu[i];
	dia = plu[20];

	printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n%.8lf",
		bronze, silver, gold, pla, dia);
	return 0;
}