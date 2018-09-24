#include <stdio.h>
int main()
{
 int n;
 int i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  if(a-(b-c)>0) printf("do not advertise\n");
  else if(a-(b-c)<0) printf("advertise\n");
  else printf("does not matter\n");
 }
 return 0;
}