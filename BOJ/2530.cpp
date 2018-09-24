#include <cstdio>

int h,m,s;
int t;

int main()
{
    scanf("%d %d %d %d",&h,&m,&s,&t);
    s += t % 60;
    t /= 60;
    if(s > 59) m++, s -= 60;
    m += t % 60;
    t /= 60;
    if(m > 59) h++, m -= 60;
    h += t % 24;
    if(h > 23) h -= 24;
    printf("%d %d %d",h,m,s);
    return 0;
}