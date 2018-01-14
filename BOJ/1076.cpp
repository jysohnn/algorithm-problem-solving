#include <cstdio>
#include <cstring>

long long n, f;

const char* color[10] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};

long long pow(int x)
{
	long long ret = 1;
	for(int i=0;i<x;i++) ret *= 10;
	return ret;
}

int main()
{
	int i;
	long long sol;
	char a[10];
	scanf("%s",a);
	for(i=0;i<10;i++)
		if(strcmp(a,color[i]) == 0) break;
	sol += i; sol *= 10;
	scanf("%s",a);
	for(i=0;i<10;i++)
		if(strcmp(a,color[i]) == 0) break;
	sol += i;
	scanf("%s",a);
	for(i=0;i<10;i++)
		if(strcmp(a,color[i]) == 0) break;
	sol *= pow(i);
	printf("%lld",sol);
	return 0;
}