#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long a[100001];

long long solve(int s, int e)
{   
    int l, r, mid = (s+e)/2;
    long long ret = 0;
    long long h, w;
    
    if(s == e-1) return a[s]*a[s];
    
    h = min(a[mid],a[mid+1]);
    w = a[mid] + a[mid+1];
    ret = h * w; 
    l = mid - 1, r = mid + 2;
    while(s <= l  || r < e)
    {
        long long tmp;
        if(s <= l && r < e) tmp = max(a[l], a[r]), a[l] > a[r] ? l-- : r++;
        else if(s <= l) tmp = a[l], l--;
        else tmp = a[r], r++;
        w += tmp;
        h = min(h, tmp); 
        ret = max(ret, h * w);
    }
    return max(ret, max(solve(s,mid), solve(mid,e)));
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    printf("%lld",solve(0,n));
    return 0;
}