#include <stdio.h>
int main()
{
    double a,b,c,d;
    scanf("%lf %lf",&a,&b);
    scanf("%lf %lf",&c,&d);
    double max=a/c+b/d;
    int i=0;
    if(c/d+a/b>max) {max=c/d+a/b,i=1;}
    if(d/b+c/a>max) {max=d/b+c/a,i=2;}
    if(b/a+d/c>max) {max=b/a+d/c,i=3;}
    printf("%d",i);
    return 0;
}