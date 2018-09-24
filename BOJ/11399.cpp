#include <cstdio>
#include <algorithm>

using namespace std;

int n, sol = 0;
int a[1001];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    sort(a,a+n);
    for(int i=1;i<n;i++) a[i] = a[i-1]+a[i];
    for(int i=0;i<n;i++) sol += a[i];
    printf("%d",sol);
    return 0;
}