#include <stdio.h>
int main()
{
    int a[8];
    bool check=true;
    for(int i=0;i<8;i++) scanf("%d",a+i);
    for(int i=0;i<7;i++)
        if(a[i+1]-a[i]!=1) check=false;
    if(check) {printf("ascending"); return 0;}
    else check=true;
    for(int i=0;i<7;i++)
        if(a[i+1]-a[i]!= -1) check=false;
    if(check) printf("descending");
    else printf("mixed");
    return 0;
}