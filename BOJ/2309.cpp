#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a[9];
	int sum=-100;
	bool check[9]={0};
	for(int i=0;i<9;i++) {scanf("%d",a+i); sum+=a[i];}
	sort(a,a+9);
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
			if(a[i]+a[j] == sum)
			{
				check[i]=true;
				check[j]=true;
				break;
			}
	for(int i=0;i<9;i++)
		if(!check[i]) printf("%d\n",a[i]);
	return 0;
}