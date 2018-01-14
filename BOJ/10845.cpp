#include <iostream>
#include <string>
#include <queue>

using namespace std;

string _push("push"),_pop("pop"),_size("size"),_empty("empty"),_front("front"),_back("back");

int main()
{
    queue<int> q;
    
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
            q.push(x);
        }
        else if(a == _pop)
        {
            if(!q.empty())
            {
                cout<<q.front()<<endl;
                q.pop(); 
            }
            else cout<<-1<<endl;
        }
        else if(a == _size) cout<<q.size()<<endl;
        else if(a == _empty) {if(q.empty()) cout<<1<<endl; else cout<<0<<endl;}
        else if(a == _front) {if(q.empty()) cout<<-1<<endl; else cout<<q.front()<<endl;}
        else {if(q.empty()) cout<<-1<<endl; else cout<<q.back()<<endl;}
    }
    return 0;
}