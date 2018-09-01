#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

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
    ll ret = ccw(a-p, b-p);
    if (ret > 0) return 1;
    else if(ret == 0) return 0;
    else return -1;
}
bool isParallel(vector2 a, vector2 b, vector2 c, vector2 d)
{
    return (a-b).cross(c-d) == 0;
}
bool segmentIntersect(vector2 a, vector2 b, vector2 c, vector2 d)
{
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);

    if(ab == 0 && cd == 0)
    {
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

ll n, k;
ll a[100001];
bool sol = 0;

int main()
{
    cin>>n;
    for(ll i=1; i<=n; i++) scanf("%lld", a+i);
    cin>>k;
    
    for(ll i=1; i<n; i++)
    {
        vector2 xx(i, k * i);
        vector2 yy(i+1, k*(i+1));
        vector2 x(i, a[i]);
        vector2 y(i+1, a[i+1]);
        if(segmentIntersect(xx, yy, x, y)) sol = 1;
    }
    if(sol || a[1] == k) cout<<'T';
    else cout<<'F';
    return 0;
}