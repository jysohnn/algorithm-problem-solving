#include <cstdio>
#include <cmath>

int main()
{
    double h,v;
    double x;
    scanf("%lf %lf",&h,&v);
    x = ((-2.0*h*h)+sqrt(4.0*h*h*h*h+4.0*v*v*h*h))/(2.0*v);
    printf("%.2lf %.2lf",sqrt(h*h+x*x)/2.0,(v-x)*h/sqrt(h*h+x*x));
    return 0;
}