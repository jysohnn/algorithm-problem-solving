#include <cstdio>
#include <deque>

using namespace std;

deque<int> q;
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) q.push_back(i);
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop_front();
        if(!q.empty())
        {
            int tmp = q.front();
            q.pop_front();
            q.push_back(tmp);
        }
    }
    return 0;
}