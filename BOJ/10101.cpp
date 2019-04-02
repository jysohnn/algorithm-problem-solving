#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll a, b, c;

int main()
{
    cin>>a>>b>>c;
    if(a == b && b == c && a == 60) printf("Equilateral");
    else if(a + b + c == 180 && ((a == b) || (b == c) || (c == a))) printf("Isosceles");
    else if(a + b + c == 180) printf("Scalene");
    else printf("Error");
    return 0;
}