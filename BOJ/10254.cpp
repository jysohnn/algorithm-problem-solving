#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

#define N 200003

using namespace std;

typedef long long ll;
ll n, cnt, p1, p2, mx = 0;
const double PI = acos(-1);
int t;
pair<ll, ll> aa, bb;

struct point {
    ll x, y;
    bool operator<(const point&r)const {
        return x<r.x || (x == r.x&&y<r.y);
    }
    ll ccw(point p, point q) {
        return (p.x - x)*(q.y - y) - (p.y - y)*(q.x - x);
    }
} a[N], convex[N];

void convexhull() {
    scanf("%lld", &n);
    ll i;
    for (i = 1; i <= n; i++)
        scanf("%lld %lld", &a[i].x, &a[i].y);
    sort(a + 1, a + 1 + n);
    for (i = 1; i <= n; i++) {
        for (; cnt >= 2 && convex[cnt - 1].ccw(convex[cnt], a[i]) <= 0; --cnt);
        convex[++cnt] = a[i];
    }
    for (p2 = cnt, i = n - 1; i >= 1; --i) {
        for (; cnt >= p2 + 1 && convex[cnt - 1].ccw(convex[cnt], a[i]) <= 0; --cnt);
        convex[++cnt] = a[i];
    }
    p1 = 1; cnt--;
}

ll cal_dis() {
    return (convex[p1].x - convex[p2].x)*(convex[p1].x - convex[p2].x) + (convex[p1].y - convex[p2].y)*(convex[p1].y - convex[p2].y);
}

void rotating_calipers()
{
    ll i;
    ll x1, y1, x2, y2, xx1, yy1, xx2, yy2;
    double cos1, cos2;

    x1 = x2 = 0;
    y1 = -1, y2 = 1;

    for (i = 1; i <= cnt; i++) {
        if (mx < cal_dis())
        {
            aa.first = convex[p1].x;
            aa.second = convex[p1].y;
            bb.first = convex[p2].x;
            bb.second = convex[p2].y;
            mx = cal_dis();
        }

        xx1 = (convex[p1%cnt + 1].x - convex[p1].x); yy1 = (convex[p1%cnt + 1].y - convex[p1].y);
        xx2 = (convex[p2%cnt + 1].x - convex[p2].x); yy2 = (convex[p2%cnt + 1].y - convex[p2].y);

        cos1 = (double)(x1*xx1 + y1*yy1) / sqrt(x1*x1 + y1*y1) / sqrt(xx1*xx1 + yy1*yy1);
        cos2 = (double)(x2*xx2 + y2*yy2) / sqrt(x2*x2 + y2*y2) / sqrt(xx2*xx2 + yy2*yy2);

        if (cos1>cos2) {
            p1 = p1%cnt + 1;
            x1 = xx1; y1 = yy1;

            x2 = -x1; y2 = -y1;
        }
        else {
            p2 = p2%cnt + 1;
            x2 = xx2; y2 = yy2;
            x1 = -x2; y1 = -y2;
        }
    }
    printf("%lld %lld %lld %lld\n", aa.first, aa.second, bb.first, bb.second);
}

int main() {
    scanf("%d", &t);
    while (t--)
    {
        mx = 0;
        n = 0, cnt = 0, p1 = 0, p2 = 0;
        convexhull();
        rotating_calipers();
    }
    return 0;
}