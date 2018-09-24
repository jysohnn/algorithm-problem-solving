#include <cstdio>
#include <deque>

using namespace std;

deque<int> dq;

void left(int n)
{
    for(int i=0;i<n;i++){
    dq.push_back(dq.front());
    dq.pop_front();}
}
void right(int n)
{
    for(int i=0;i<n;i++){
    dq.push_front(dq.back());
    dq.pop_back();}
}
int dis(int x)
{
    int size = dq.size();
    for(int i=0;i<size;i++)
        if(dq[i] == x) return i;
    return 0;
}
int main()
{
    int n,m,sol=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) dq.push_back(i);
    for(int i=0;i<m;i++)
    {
        int x,d,size = dq.size();
        scanf("%d",&x);
        d = dis(x);
        if(d < size-d) {left(d);dq.pop_front();sol+=d;}
        else {right(size-d);dq.pop_front();sol+=size-d;}
    }
    printf("%d",sol);
    return 0;
}