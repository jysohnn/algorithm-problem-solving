#include <cstdio>

int n;

int main()
{
    scanf("%d",&n);
    printf("%c%d",'A'+(n%12+8)%12,(n%10+6)%10);
    return 0;
}