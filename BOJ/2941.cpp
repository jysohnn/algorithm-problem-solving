#include <stdio.h>
#include <cstring>
char a[101]={0};
int alphanum(char* x)
{
	int check=0;
	if(x[2]=='=')
	{
		for(int i=0;i<100;i++)
			if(a[i]==x[0] && a[i+1]==x[1] && a[i+2]==x[2]) check++;
	}
	else
	{
		for(int i=0;i<100;i++)
			if(a[i]==x[0] && a[i+1]==x[1]) check++;
	}
	return check;		
};
int main()
{
	int sol=0;
	scanf("%s",a);
	sol += alphanum("c=");
	sol += alphanum("c-");
	sol += alphanum("dz=");
	sol += alphanum("d-");
	sol += alphanum("lj");
	sol += alphanum("nj");
	sol += alphanum("s=");
	sol += alphanum("z=");
	sol = strlen(a) - sol;
	printf("%d",sol);
	return 0;
}