#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> ll;
typedef pair<ll, ll> line;

line a[3001];
int n, g = 0, maxi = 0;
int p[3001];

long long ccw(ll a, ll b, ll c)
{
	long long ret = a.first*b.second + b.first*c.second + c.first*a.second
		- b.first*a.second - c.first*b.second - a.first*c.second;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

int check(line a, line b) // return : 교점개수
{
	long long ab = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
	long long ba = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
	if(ab == 0 && ba == 0)
	{
		if(a.first > a.second) swap(a.first, a.second);
		if(b.first > b.second) swap(b.first, b.second);
		
		if(a.second < b.first || b.second < a.first) return 0; // 평행, 안 만남
		else if((a.first == b.first && a.second != b.second)
			 || (a.first == b.second && a.second != b.first)
			 || (a.second == b.first && a.first != b.second)
			 || (a.second == b.second && a.first != b.first)) return 1; // 평행 or 안평행, 한 점 만남
		else return -1; // 평행, 무한개, 겹침
	}
	return ab <= 0 && ba <= 0; // 평행 아니고, 한 점 만남 or 안 만남
}

int find(int x)
{
	if (p[x] < 0) return x;
	p[x] = find(p[x]);
	return p[x];
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	int tmp = p[x] + p[y];
	if (x == y) return;
	if (p[x] < p[y])
	{
		p[y] = x;
		p[x] = tmp;
	}
	else
	{
		p[x] = y;
		p[y] = tmp;
	}
}

int main()
{
	for (int i = 0;i < 3001;i++) p[i] = -1;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		int x, y, x2, y2;
		scanf("%d %d %d %d", &x, &y, &x2, &y2);
		a[i].first.first = x;
		a[i].first.second = y;
		a[i].second.first = x2;
		a[i].second.second = y2;
	}
	for(int i = 0;i < n;i++)
		for (int j = i + 1;j < n;j++) 
			if (check(a[i], a[j])) merge(i, j);
	for(int i=0;i<n;i++)
		if (p[i] < 0)
		{
			g++;
			if (maxi < p[i] * (-1)) maxi = p[i] * (-1);
		}
	printf("%d\n%d",g,maxi);
	return 0;
}