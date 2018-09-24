#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    queue<int> q,r;
    int n,m,count = 1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) q.push(i);
    while(!q.empty())
    {
        if(count % m == 0)
        {
            r.push(q.front());
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
        ++count;
    }
    int size = r.size();
    if(size == 1) printf("<%d>",r.front());
    else{
    for(int i=0;i<size;i++)
    {
        if(i==0) printf("<%d, ",r.front());
        else if(i==size-1) printf("%d>",r.front());
        else printf("%d, ",r.front());
        r.pop();
    }}
    return 0;
}