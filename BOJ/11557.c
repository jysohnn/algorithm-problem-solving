#include <stdio.h>
#include <stdlib.h>
int main()
{
 int t,i,j;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  int n,max=0,check;
  scanf("%d",&n);

  char** a=(char**)malloc(sizeof(char*)*n);
  for(j=0;j<n;j++) *(a+j)=(char*)malloc(sizeof(char)*21);
  int* b=(int*)malloc(sizeof(int)*n);

  for(j=0;j<n;j++) scanf("%s %d",*(a+j),b+j);
  for(j=0;j<n;j++)
  {
   if(max<=b[j]) {max=b[j];check=j;}
  }
  printf("%s\n",*(a+check));
 }
 return 0;
}