#include <stdio.h>
char sum[3][3][100][100]={0};
void Phanoi(int x,int y,int n)
{
 if(n==1)
 {
  printf("%d %d\n",x,y);
 }
 else
 {
  Phanoi(x,6-x-y,n-1);
  printf("%d %d\n",x,y);
  Phanoi(6-x-y,y,n-1);
 }
};
void calstring(char* a,char* b,char* result)
{
 int i;
 char buff[100]={0};
 for(i=0;i<99;i++)
 {
  result[i]=a[i]+b[i]+buff[i];
  buff[i+1]=result[i]/10;
  result[i]=result[i]%10;
 }
};
void plusone(char* result)
{
 char a[100]={0};
 char b[100]={0};
 int i;
 for(i=0;i<100;i++) b[i]=result[i];
 a[0]=1;
 calstring(a,b,result);
};
void DP_hanoi()
{
 int i,j,k;
 for(i=0;i<3;i++)
  for(j=0;j<3;j++) {sum[i][j][0][0]=1;}
 for(k=1;k<100;k++)
  for(i=0;i<3;i++)
   for(j=0;j<3;j++) {if(j!=i){calstring(sum[i][3-i-j][k-1],sum[3-i-j][j][k-1],sum[i][j][k]); plusone(sum[i][j][k]);}}
};
int main()
{
 int n,i,check=0;
 scanf("%d",&n);
 DP_hanoi();
 for(i=99;i>=0;i--) if(sum[0][2][n-1][i]!=0){check=i;break;}
 for(i=check;i>=0;i--) printf("%c",sum[0][2][n-1][i]+48);
 printf("\n");
 if(n<=20) Phanoi(1,3,n);
 return 0;
}