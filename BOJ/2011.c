#include <stdio.h>
int main()
{
 int i;
 char s[5002]={0};
 int a[5002]={0};
 scanf("%s",s);

 for(i=0;s[i]!=0;i++)
 {
  if(i==0&&s[i]=='0'){printf("0\n");return 0;}
  if(s[i]=='0'&&s[i+1]=='0') {printf("0\n");return 0;}
  if(s[i]!='1'&&s[i]!='2'&&s[i+1]=='0') {printf("0\n");return 0;}
 }

 for(i=0;s[i]!=0;i++)
 {
  if(i==0) a[i]=1;
  else
  {
   if(s[i]=='0')
   {
    if(i>=2) a[i]=a[i-2];
    else a[i]=1;
   }
   else
   {
    if(s[i-1]=='1')
    {
     if(i>=2) a[i]=a[i-1]+a[i-2];
     else a[i]=a[i-1]+1;
    }
    else if(s[i-1]=='2')
    {
     if(s[i]>='1'&&s[i]<='6')
     {
      if(i>=2) a[i]=a[i-1]+a[i-2];
      else a[i]=a[i-1]+1;
     }
     else a[i]=a[i-1];
    }
    else
    {
     a[i]=a[i-1];
    }
   }
  }
  if(a[i]>=1000000) a[i]=a[i]%1000000;
 }
 printf("%d\n",a[i-1]%1000000);
 return 0;
}