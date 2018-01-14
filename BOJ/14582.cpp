#include <cstdio>

int u[9];
int s[9];
int uu=0,ss=0;
bool flag = false;

int main()
{
    for(int i = 0;i<9;i++) scanf("%d",u+i);
    for(int i = 0;i<9;i++) scanf("%d",s+i);
    for(int i = 0;i<18;i++)
    {
        if(i % 2 == 0) uu += u[i/2];
        else ss += s[i/2];
        if(uu > ss) flag = true;
    }
    if(flag && ss > uu) printf("Yes");
    else printf("No");
    return 0;
}