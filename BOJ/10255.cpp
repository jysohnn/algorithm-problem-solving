#include <iostream>
#include <algorithm>
#include <cmath>
#define EPSILON 0.0001

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
    ll cross(const vector2& rhs) const
    {
        return x * rhs.y - rhs.x * y;
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

ll t;

int main()
{
    scanf("%lld", &t);
    while(t--)
    {
        bool inf = false;
        ll xmin, ymin, xmax, ymax;
        ll a, b, c, d, sol = 0;
        vector2 rec[4], l1, l2;
        scanf("%lld %lld %lld %lld", &xmin, &ymin, &xmax, &ymax);
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        l1 = vector2(a, b); l2 = vector2(c, d);
        rec[0] = vector2(xmin, ymin);
        rec[1] = vector2(xmin, ymax);
        rec[2] = vector2(xmax, ymax);
        rec[3] = vector2(xmax, ymin);

        for(ll i=0; i < 4; i++)
        {
            ll j = i + 1; if(j > 3) j = 0;
            if(isParallel(rec[i], rec[j], l1, l2))
            {
                vector2 a = l1;
                vector2 b = l2;
                vector2 c = rec[i];
                vector2 d = rec[j];
                if(i % 2 == 1)
                {
                    if(b.x < a.x) swap(a, b);
                    if(d.x < c.x) swap(c, d);
                }
                else
                {
                    if(b.y < a.y) swap(a, b);
                    if(d.y < c.y) swap(c, d);
                }

                if(i % 2 == 1 && d.x > a.x && b.x > c.x && a.y == c.y) inf = true;
                if(i % 2 == 0 && d.y > a.y && b.y > c.y && a.x == c.x) inf = true;
            }
        }
        if(inf) {printf("4\n"); continue;}
        for(ll i=0; i < 4; i++)
        {
            ll j = i + 1; if(j > 3) j = 0;
            if(segmentIntersect(rec[i], rec[j], l1, l2)) sol++;
        }

        for(ll i=0; i < 4; i++)
        {
            if(isParallel(l1, rec[i], l1, l2))
            {
                vector2 a = l1;
                vector2 b = l2;
                vector2 c = rec[i];
                if(min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)
                && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)) sol--;
            }
        }
        printf("%lld\n", sol);
    }
    return 0;
}