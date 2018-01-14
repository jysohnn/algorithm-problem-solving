#include <stdio.h>
int main()
{
 int a,b;
 for(a=0;getchar()!='h';a++){}
 getchar();
 for(b=0;getchar()!='h';b++){}
 if(b>a) printf("no");
 else printf("go");
 return 0;
}