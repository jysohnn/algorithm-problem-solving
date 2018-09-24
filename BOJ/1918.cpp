#include <cstdio>
#include <stack>

using namespace std;

stack<char> s;
int in[48];
int out[48];

int main()
{
	in['+'] = 0,in['-'] = 0,in['*'] = 1,in['/'] = 1,in['('] = 2;
	out['+'] = 0,out['-'] = 0,out['*'] = 1,out['/'] = 1,out['('] = -1;
    while(1)
    {
        char c = getchar();
        if(c == '\n' || c == EOF) break;
        if('A' <= c && c <= 'Z') putchar(c);
        else
        {
            if(c == ')')
            {
                while(!s.empty() && s.top() != '(') putchar(s.top()), s.pop();
                s.pop();
            }
            else
            {
                while(!s.empty() && out[s.top()] >= in[c]) putchar(s.top()), s.pop();
                s.push(c);
            }
        }
    }
    while(!s.empty()) putchar(s.top()), s.pop();
    return 0;
}