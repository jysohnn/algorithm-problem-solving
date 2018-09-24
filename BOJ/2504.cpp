#include <cstdio>
#include <stack>
#define INF 99999999

using namespace std;

char a[31];

int sol(int start,int end)
{
    if(start > end) return 1;

    stack<char> s;
    int si,cal,ret = 0;

    for(int i=start;i<=end;i++)
    {
        if(a[i] == '(' || a[i] == '[')
        {
            if(s.empty())
            {
                si=i+1;
                if(a[i]=='(') cal = 2;
                else cal = 3;
            }
            s.push(a[i]);
        }
        else
        {
            if(s.empty()) return INF;
            else if(a[i] == ')' && s.top() == '[') return INF;
            else if(a[i] == ']' && s.top() == '(') return INF;
            else s.pop();
        }

        if(s.empty())
        {
            ret += cal * sol(si,i-1);
        }
    }
    return ret;
}

int main()
{
    int size,x;
    scanf("%s",a);
    for(size=0;a[size]!=0;size++);

    x = sol(0,size-1);
    if(x > INF-1) printf("0");
    else printf("%d",x);
    return 0;
}