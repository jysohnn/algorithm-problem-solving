#include <stdio.h>
int main()
{         
 int m,n;
 long long count=0;
 int i,j; 
 int a[10001]={1,1,0};
         
 for(i=2;i<10001;i++)
 {    
  if(a[i]==0)
  { 
   for(j=2;i*j<10001;j++) a[i*j]=1;
  } 
 }  
 scanf("%d %d",&m,&n);
 for(i=m;i<=n;i++)
 {
 	if(a[i]==0)
 	{
 		count+=i;
	}
 }
 for(i=m;i<=n;i++)
 {
 	if(a[i]==0)
 	{
 		printf("%lld\n%d",count,i);
 		break;
	}
 }
 if(i==n+1) printf("-1");
 return 0; 
}