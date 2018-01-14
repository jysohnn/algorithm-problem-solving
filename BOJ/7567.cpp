#include <cstdio>

char a[51];

int main()
{
    char prev;
    int sum = 10;
    scanf("%s",a);
    prev = a[0];
    for(int i=1;a[i]!=0;i++)
    {
        if(a[i] == prev) sum += 5;
        else sum += 10, prev = a[i];
    }
    printf("%d",sum);
    return 0;
}