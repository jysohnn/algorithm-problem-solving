#include <stdio.h>
int main()
{         
 int a,b;
 int i,j; 
 int n[1000010]={0};
        
 scanf("%d %d",&a,&b);
 for(i=2;i<=b;i++)
 {    
  if(n[i]==0)
  { 
   for(j=2;i*j<=b;j++) n[i*j]=1;
  } 
 }  
 for(i=a;i<=b;i++)
 {
  if(n[i]==0 && i!=1) printf("%d\n",i); 
 }  
 return 0; 
}