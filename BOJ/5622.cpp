#include <stdio.h>
int main()
{
	int sol=0;
	char a[20]={0};
	scanf("%s",a);
	for(int i=0;a[i]!=0;i++)
	{
		if(a[i]<=82) sol += (a[i]-65)/3 + 3;
		else if(a[i]==83) sol += 8;
		else if(a[i]>83 && a[i]<87) sol += 9;
		else sol += 10;
	}
	printf("%d",sol);
	return 0;
}