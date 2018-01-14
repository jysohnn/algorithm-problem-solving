#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n[11] = {0};
int x, y;
int sol = 0, tmp = 0;

int main()
{
    cin>>x>>y;
    for(int i=1;i<=10;i++) n[i] = 2;
    n[x]--; n[y]--;
    for(int i=1;i<=10;i++)
        for(int j=0;j<n[i];j++) v.push_back(i);
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
        {
            if(x == y)
            {
                if(v[i] != v[j]) sol++;
                else if(v[i] < x) sol++;
            }
            else if(v[i] != v[j] && (v[i]+v[j])%10 < (x+y)%10) sol++;
            tmp++;
        }
    printf("%.3lf", (double)sol / (double)tmp);
    return 0;
}