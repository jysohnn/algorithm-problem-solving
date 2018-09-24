#include <cstdio>
#include <deque>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        deque<int> dq;
        bool check = true, error = false;
        int n,x = 0;
        char s[100001];

        scanf("%s",s);
        scanf("%d",&n);

        while(1)
        {
            char c = getchar();
            if(c == ']')
            {
                if(x!=0) dq.push_back(x);
                break;
            }
            else if(c >= '0' && c <= '9') x = x*10+c-'0';
            else if(c == ',') {dq.push_back(x);x=0;}
        }

        for(int j=0;s[j]!=0;j++)
        {
            if(s[j] == 'R') check = !check;
            else
            {
                if(dq.empty()) {printf("error\n");error=true;break;}
                if(check) dq.pop_front();
                else dq.pop_back();
            }
        }
        if(!error){
        int size = dq.size();
        putchar('[');
        if(check)
        {
            for(int j=0;j<size;j++)
            {
                if(j==0) printf("%d",dq[j]);
                else printf(",%d",dq[j]);
            }
        }
        else
        {
            for(int j=size-1;j>=0;j--)
            {
                if(j==size-1) printf("%d",dq[j]);
                else printf(",%d",dq[j]);
            }
        }
        printf("]\n");}
    }
    return 0;
}