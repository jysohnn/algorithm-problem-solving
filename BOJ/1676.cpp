#include <cstdio>
#include <algorithm>

using namespace std;

struct z
{
	int two;
	int five;
} a[501];

int main()
{
	int x;
	a[0].two=0,a[0].five=0;
	a[1].two=0,a[1].five=0;
	for(int i=2;i<501;i++)
	{
		int n = i;
		int two=0,five=0;
		while(n%2 == 0) {++two;n/=2;}
		while(n%5 == 0) {++five;n/=5;}
		a[i].two = a[i-1].two + two;
		a[i].five = a[i-1].five + five;
	}
	scanf("%d",&x);
	printf("%d",min(a[x].two,a[x].five));
	return 0;
}