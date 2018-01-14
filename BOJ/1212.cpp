#include <cstdio>

char n[333335];

int main()
{
	scanf("%s",n);
	for(int i=0;n[i]!=0;i++)
	{
		char a[3];
		n[i] -= 48;
		for(int j=2;j>=0;j--)
		{
			if(n[i]%2==0) a[j]='0';
			else a[j]='1';
			n[i] /= 2;
		}
		if(i==0)
		{
			int c;
			for(c=0;c<2 && a[c]=='0';c++);
			for(int j=c;j<3;j++) printf("%c",a[j]);
		}
		else printf("%s",a);
	}	
	return 0;
}