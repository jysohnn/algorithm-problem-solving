#include <iostream>
#include <string>
#include <stack>

using namespace std;

string _push("push"),_pop("pop"),_size("size"),_empty("empty"),_top("top");

int main()
{
    stack<int> s;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;

        if(a == _push)
        {
            int x;
            cin>>x;
            s.push(x);
        }
        else if(a == _pop)
        {
            if(!s.empty())
            {
                cout<<s.top()<<endl;
                s.pop();
            }
            else cout<<-1<<endl;
        }
        else if(a == _size) cout<<s.size()<<endl;
        else if(a == _empty) {if(s.empty()) cout<<1<<endl; else cout<<0<<endl;}
        else {if(s.empty()) cout<<-1<<endl; else cout<<s.top()<<endl;}
    }
    return 0;
}