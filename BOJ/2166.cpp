#include <iostream>
#include <cmath>
#define EPSILON 0.0001

using namespace std;
using ll = long long;

/* 먼저 벡터를 표현하는 구조체를 정의합니다. */
struct vector2{
    double x, y;
    //생성자
    vector2(){}
    vector2(double _x, double _y){
        x = _x, y = _y;
    }
    //외적
    double cross(const vector2& other) const{
        return x*other.y-y*other.x;
    }
    
    /* 연산자 오버로딩을 통해 실제 벡터의 연산을 구현합니다. */
    
    //벡터의 실수배
    vector2 operator * (double r) const{
        return vector2(x*r, y*r);
    }
    //벡터의 덧셈
    vector2 operator + (vector2 other) const{
        return vector2(x + other.x, y + other.y);
    }
    //벡터의 뺄셈
    vector2 operator - (vector2 other) const{
        return vector2(x - other.x, y - other.y);
    }
    //두 벡터의 비교
    bool operator == (vector2 other) const{
        return x == other.x && y == other.y;
    }
    bool operator < (vector2 other) const{
        return x < other.x && y < other.y;
    }
};

/*
 - 점 a, b를 지나는 직선과 점 c, d를 지나는 직선의 교점을 x에 반환한다.
 - 두 직선이 평행이면(겹치는 경우 포함) 거짓을, 아니면 참을 반환한다.
 */
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x){
    double det = (b-a).cross(d-c);
    //두선이 평행인 경우
    if(fabs(det) < EPSILON) return false;
    x = a+(b-a)*((c-a).cross(d-c)/det);
    return true;
}

//원점에서 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 반환 한다.
double ccw(vector2 a, vector2 b){
    return a.cross(b);
}
//점 p를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 반환 한다.
double ccw(vector2 p, vector2 a, vector2 b){
    return ccw(a-p, b-p);
}

//점 a, b와 점 c, d가 평행한 두 선분 일 때 이들이 한 점에서 겹치는지 확인한다.
bool paralleSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){
    if(b < a) swap(a,b);
    if(d < c) swap(c,d);
    
    //한 직선위에 없거나 두 선분이 겹치지 않는 경우를 우선 걸러낸다. 본문의 1번 관계인 경우이다.
    if(ccw(a, b, c) != 0 || b < c || d < a) return false;
    
    //두 선분이 확실히 겹친다면 교차점 하나를 찾는다.
    if(a<c) p = c;
    else p = a;
    return true;
}

/*
 - p가 두 점 a, b를 감싸면서 각 변이 x, y축에 평행한 최소사각형 내부에 있는지 확인한다.
 - a, b, p는 일직선 상에 있다고 가정한다.
 */
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b){
    if(b < a) swap(a, b);
    return p == a || p == b || (a <p && p < b);
}

/*
 - 두 점 a, b를 지나는 선분과 두 점 c, b를 지나는 선분을 p에 반환한다.
 - 교짐이 여러개일 경우 아무점이나 반환한다.
 */
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){
    //두 직선이 평행인 경우를 우선 예외로 처리한다.
    if(!lineIntersection(a, b, c, d, p))
        return paralleSegments(a, b, c, d, p);
    //p가 두 선분에 포함되어 있는 경우에만 참을 반환한다.
    return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

ll n;
ll x[10001];
ll y[10001];
double sol = 0;

int main()
{
    scanf("%lld", &n);
    for(ll i=0; i<n; i++) scanf("%lld %lld", x+i, y+i);
    for(ll i=0; i<n; i++)
    {
        ll j = i+1;
        if(j >= n) j = 0;
        sol += (double)(x[i] + x[j]) * (double)(y[i] - y[j]);
    }
    printf("%.1lf", abs(sol) / 2.0);
    return 0;    
}