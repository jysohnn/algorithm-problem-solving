#include <cstdio>
#include <cstring>

int t;
char* a[4] = {"kg","l","lb","g"};

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        double v;
        char si[3];
        scanf("%lf %s",&v,si);
        for(int i=0;i<4;i++)
            if(strcmp(a[i],si) == 0)
            {
                switch(i)
                {
                    case 0: printf("%.4lf lb\n",v*2.2046);break;
                    case 1: printf("%.4lf g\n",v*0.2642);break;
                    case 2: printf("%.4lf kg\n",v*0.4536);break;
                    case 3: printf("%.4lf l\n",v*3.7854);break;
                    default: break;
                }
            }
    }
    return 0;
}