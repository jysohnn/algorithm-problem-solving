#include <stdio.h>
int main()
{         
 int t,count=0;
 int i,j; 
 int n[1001]={1,1,0};
         
 for(i=2;i<1001;i++)
 {    
  if(n[i]==0)
  { 
   for(j=2;i*j<1001;j++) n[i*j]=1;
  } 
 }  
 
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
 	int x;
 	scanf("%d",&x);
 	if(n[x]==0) count++;
 }
 printf("%d",count);
 return 0; 
}