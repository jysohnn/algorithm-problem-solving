#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, state = 0, sol = 0;
ll lever = 0;
bool multi = 0;
string a;

int main()
{
    cin>>n>>a;
    for(int i=0; i<n; i++)
    {
        if(a[i] == 'P')
        {
            lever = (lever + 1) % 2;
            if(state == 1) multi = 1;
        }
        else
        {
            if(state == 1)
            {
                if(multi) sol += 6;
                else if(lever == 0) sol += 5;
                else if(lever == 1) sol += 1;
            }
            state++;
            if(state > 2) state = 2;
        }
    }
    cout<<sol;
    return 0;
}