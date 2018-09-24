#include <stdio.h>
#include <stdlib.h>
  
int square(int size,int** x,int n,int m)
{
 int i,j,k,l;
 if(x[size-1][size-1]==size*size) return size*size;
 for(i=size;i<n;i++) if(x[i][size-1]-x[i-size][size-1]==size*size) return size*size;
 for(j=size;j<m;j++) if(x[size-1][j]-x[size-1][j-size]==size*size) return size*size;
 for(i=1;i<n-size+1;i++)
  for(j=1;j<m-size+1;j++)
  {
    if(x[i+size-1][j+size-1]+x[i-1][j-1]-x[i+size-1][j-1]-x[i-1][j+size-1]==size*size) return size*size;
  }
 return 0;
};
  
int main()
{
 int i,j;
 int n,m,size_max,result=0;
 scanf("%d %d",&n,&m);
  
 if(n>m) size_max=m;
 else size_max=n;
  
 int** a=(int**)malloc(sizeof(int*)*n);
 for(i=0;i<n;i++) *(a+i)=(int*)malloc(sizeof(int)*m);
 int** x=(int**)malloc(sizeof(int*)*n);
 for(i=0;i<n;i++) *(x+i)=(int*)malloc(sizeof(int)*m);
  
 for(i=0;i<n;i++)
 {
  char* tmp=(char*)malloc(sizeof(char)*(m+1));
  scanf("%s",tmp);
  for(j=0;j<m;j++)
  {
   if(tmp[j]=='0') a[i][j]=0;
   else a[i][j]=1;
  }
 }
  
 x[0][0]=a[0][0];
 for(i=1;i<n;i++) x[i][0]=x[i-1][0]+a[i][0];
 for(i=1;i<m;i++) x[0][i]=x[0][i-1]+a[0][i];
 for(i=1;i<n;i++)
    for(j=1;j<m;j++) x[i][j]=x[i-1][j]+x[i][j-1]-x[i-1][j-1]+a[i][j];
  
 for(i=1;i<=size_max;i++)
  if(square(i,x,n,m)!=0) result=square(i,x,n,m);
 printf("%d\n",result);
 return 0;
}