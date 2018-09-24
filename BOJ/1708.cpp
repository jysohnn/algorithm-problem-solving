#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
using ll = long long;

struct vector2
{
    ll x, y;
    explicit vector2(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    bool operator==(const vector2& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
    bool operator<(const vector2& rhs) const
    {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    vector2 operator+(const vector2& rhs) const
    {
        return vector2(x + rhs.x, y + rhs.y);
    }
    vector2 operator-(const vector2& rhs) const
    {
        return vector2(x - rhs.x, y - rhs.y);
    }
    vector2 operator*(ll rhs) const
    {
        return vector2(x * rhs, y * rhs);
    }
    ll dot(const vector2& rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
    ll cross(const vector2& rhs) const
    {
        return x * rhs.y - rhs.x * y;
    }
    double norm() const
    {
        return hypot(x, y);
    }
};

ll ccw(vector2 a, vector2 b)
{
    return a.cross(b);
}
ll ccw(vector2 p, vector2 a, vector2 b)
{
    return ccw(a-p, b-p);
}

ll n;
vector<vector2> p, ret;
vector2 f;

bool cmp(vector2& x, vector2& y)
{
    ll flag = ccw(f, x, y);
    if(flag > 0) return true;
    else if(flag == 0)
    {
        if((x-f).norm() < (y-f).norm()) return true;
        else return false;
    }
    else return false;
}

void graham(vector<vector2>& p, vector<vector2>& ret)
{
    sort(p.begin(), p.end());
    f = p[0]; ret.push_back(f);
    sort(p.begin() + 1, p.end(), cmp);
    for(int i=1; i<p.size(); i++)
    {
        while(ret.size() >= 2
        && ccw(ret[ret.size()-1] - ret[ret.size()-2], p[i] - ret[ret.size()-1]) <= 0) ret.pop_back();
        ret.push_back(p[i]);
    }
}

int main()
{
    cin>>n; p.resize(n);
    for(ll i=0; i<n; i++)
    {
        ll x, y; scanf("%lld %lld", &x, &y);
        p[i].x = x; p[i].y = y;
    }
    graham(p, ret);
    cout<<ret.size();
    return 0;
}