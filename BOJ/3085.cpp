#include <cstdio>
#include <algorithm>

using namespace std;

int n, sol = 1;
char a[51][51];

void check()
{
    for(int i=0;i<n;i++)
    {
        int count = 1;
        char cur = a[i][0];
        for(int j=1;j<n;j++)
        {
            if(a[i][j] == cur)
            {
                count++;
                if(count > sol) sol = count;
            }
            else count = 1, cur = a[i][j];
        }
        count = 1, cur = a[0][i];
        for(int j=1;j<n;j++)
        {
            if(a[j][i] == cur)
            {
                count++;
                if(count > sol) sol = count;
            }
            else count = 1, cur = a[j][i];
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
        {
            swap(a[i][j],a[i][j+1]);
            check();
            swap(a[i][j],a[i][j+1]);
            swap(a[j][i],a[j+1][i]);
            check();
            swap(a[j][i],a[j+1][i]);
        }
    printf("%d",sol);
    return 0;
}