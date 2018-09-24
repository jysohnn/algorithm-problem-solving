#include <cstdio>

int a[12], s[12];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++) s[i] = 11;
	for(int i=0;i<n;i++)
	{
		int j;
		int check = 0;
		for(j=0;j<n && check != a[i];j++)
			if(i+1 < s[j]) check++;
		for(;s[j] != 11;j++);
		s[j] = i+1;
	}
	for(int i=0;i<n;i++) printf("%d ",s[i]);
	return 0;
}