#include <cstdio>

int n;
int sol[201] = {0};
int a[201][3];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<3;i++)
    {
        int num[101] = {0};
        for(int j=0;j<n;j++) num[a[j][i]]++;
        for(int j=0;j<n;j++)
            if(num[a[j][i]] == 1) sol[j] += a[j][i];
    }
    for(int i=0;i<n;i++) printf("%d\n",sol[i]);
    return 0;
}