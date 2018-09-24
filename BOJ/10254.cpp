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
    double x, y;
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
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
    vector2 operator*(double rhs) const
    {
        return vector2(x * rhs, y * rhs);
    }
    double dot(const vector2& rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
    double cross(const vector2& rhs) const
    {
        return x * rhs.y - rhs.x * y;
    }
    double norm() const
    {
        return hypot(x, y);
    }
    vector2 normalize() const
    {
        return vector2(x / norm(), y / norm());
    }
};

double ccw(vector2 a, vector2 b)
{
    return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b)
{
    return ccw(a-p, b-p);
}

ll t, n;
vector<vector2> p, ret, sol;
vector2 f;

bool cmp(vector2& x, vector2& y)
{
    double flag = ccw(f, x, y);
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

double diameter(const vector<vector2>& p, vector<vector2>& sol)
{
    int n = p.size();

    // 우선 가장 왼쪽에 있는 점과 오른쪽에 있는 점을 찾는다.
    int left = min_element(p.begin(), p.end()) - p.begin();
    int right = max_element(p.begin(), p.end()) - p.begin();

    // p[left]와 p[right]에 각각 수직선을 붙인다. 두 수직선은 서로 정반대 방향을 가리키므로,
    // a의 방향만을 표현하면 된다.
    vector2 calipersA(0, 1);
    double ret = (p[right] - p[left]).norm();
    sol.push_back(p[right]); sol.push_back(p[left]);

    // toNext[i]: p[i]에서 다음 점까지의 방향을 나타내는 단위 벡터
    vector<vector2> toNext(n);
    for(int i = 0; i < n; i++) toNext[i] = (p[(i+1) % n] - p[i]).normalize();

    // a와 b는 각각 두 선분이 어디에 붙은 채로 회전하고 있는지를 나타낸다.
    int a = left, b = right;

    // 반 바퀴 돌아서 두 선분이 서로 위치를 바꿀 때까지 계속한다.
    while(a != right || b != left)
    {
        // a에서 다음 점까지의 각도와 b에서 다음 점까지의 각도 중 어느 쪽이 작은지 확인한다.
        double cosThetaA = calipersA.dot(toNext[a]);
        double cosThetaB = -calipersA.dot(toNext[b]);

        if(cosThetaA > cosThetaB) calipersA = toNext[a], a = (a+1) % n;
        else calipersA = toNext[b] * -1, b = (b+1) % n;

        if(ret < (p[a] - p[b]).norm())
        {
            ret = (p[a] - p[b]).norm();
            sol.clear();
            sol.push_back(p[a]); sol.push_back(p[b]);
        }
    }
    return ret;
}

int main()
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        p.clear(); ret.clear(); sol.clear();
        p.resize(n);
        for(ll i=0; i<n; i++)
        {
            ll x, y; scanf("%lld %lld", &x, &y);
            p[i].x = x; p[i].y = y;
        }
        graham(p, ret);
        diameter(ret, sol);
        printf("%lld %lld %lld %lld\n", ll(sol[0].x),ll(sol[0].y), ll(sol[1].x), ll(sol[1].y));
    }
    return 0;
}