#include <cstdio>
#include <deque>

using namespace std;

struct print
{
    bool check;
    int order;
    print(int ch,int x) :check(ch),order(x) {}
};

bool isthere(deque<print>& dq)
{
    int order = dq[0].order;
    int size = dq.size();
    for(int i=1;i<size;i++)
        if(dq[i].order > order) return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        deque<print> dq;
        int n,ch,count = 1;

        scanf("%d %d",&n,&ch);
        for(int j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            if(j == ch) dq.push_back(print(true,x));
            else dq.push_back(print(false,x));
        }
        while(!dq.empty())
        {
            if(!isthere(dq))
            {
                if(dq[0].check)
                {
                    printf("%d\n",count);
                    break;
                }
                else
                {
                    dq.pop_front();
                    ++count;
                }
            }
            else
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    return 0;
}