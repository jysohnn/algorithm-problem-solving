#include <iostream>

int sol = 0;

int main()
{
	int tmp = 0;
	while (1)
	{
		char x = getchar();
		if (x == EOF) break;
		else if (x == ',') sol += tmp, tmp = 0;
		else if ('0' <= x && x <= '9') tmp *= 10, tmp += (x - '0');
	}
	sol += tmp;
	printf("%d", sol);
	return 0;
}