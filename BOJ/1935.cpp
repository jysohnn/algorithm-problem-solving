#include <cstdio>
#include <stack>

using namespace std;

int n;
char s[101];
double a[26], sol;
stack<double> ss;

int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++) scanf("%lf",a+i);
	for(int i=0;s[i]!=0;i++)
	{
		if('A' <= s[i] && s[i] <= 'Z') ss.push(a[s[i]-'A']);
		else
		{
			double first, second;
			second = ss.top(), ss.pop();
			first = ss.top(), ss.pop();
			switch(s[i])
			{
				case '+': first = first + second; break;
				case '-': first = first - second; break;
				case '*': first = first * second; break;
				case '/': first = first / second; break;
				default:break;
			}
			ss.push(first);
		}
	}
	printf("%.2lf",ss.top());
	return 0;
}