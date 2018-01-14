#include <cstdio>
#include <algorithm>

using namespace std;

int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		long long a, b, res, c;
		char pro, tmp;
		scanf("%lld %c %lld %c %lld", &a, &pro, &b, &tmp, &res);
		switch (pro)
		{
		case '+':c = a + b; break;
		case '-':c = a - b; break;
		case '*':c = a * b; break;
		case '/':c = a / b; break;
		default:break;
		}
		if (c == res) printf("correct\n");
		else printf("wrong answer\n");
	}
	return 0;
}