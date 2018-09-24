#include <stdio.h>
int main()
{
 int a[8][8]={0};
 int i,j,check=0;
 for(i=0;i<8;i++){
  for(j=0;j<8;j++)
  {
   char x=0;
   scanf("%c",&x);
   if(x=='F') a[i][j]=1;
  } getchar();
 }
 for(i=0;i<8;i++)
  for(j=0;j<8;j++)
   {if((i+j)%2==0&&a[i][j]==1) check++;}

 printf("%d",check);
 return 0;
}