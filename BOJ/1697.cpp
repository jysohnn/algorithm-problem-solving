#include <cstdio>
#include <queue>

using namespace std;

queue<int> q;
bool v[100001] = {0};
int l[100001];

bool bc(int x)
{
    if(x >= 0 && x < 100001) return true;
    else return false;
}

int bfs(int x,int dest)
{
    v[x] = 1;
    l[x] = 0;
    q.push(x);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        v[p] = 1;
        if(p == dest) return l[p];
        if(bc(p+1) && !v[p+1]) v[p+1] = 1, q.push(p+1), l[p+1] = l[p] + 1;
        if(bc(p-1) && !v[p-1]) v[p-1] = 1, q.push(p-1), l[p-1] = l[p] + 1;
        if(bc(p*2) && !v[p*2]) v[p*2] = 1, q.push(p*2), l[p*2] = l[p] + 1;
    }
    return -1;
}

int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",bfs(x,y));
    return 0;
}