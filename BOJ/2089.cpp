#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> v[50];

vector<int> sum(vector<int> x, vector<int> y)
{
	vector<int> ret;
	int carry = 0;
	int i = x.size() - 1, j = y.size() - 1;
	while(i >= 0 && j >= 0)
	{
		int sum = x[i] + y[j] - carry;
		if(sum < 0) sum = 1, carry = -1;
		else carry = sum / 2, sum -= carry * 2;
		ret.push_back(sum);
		i--; j--;
	}
	while(i >= 0)
	{
		int sum = x[i] - carry;
		if(sum < 0) sum = 1, carry = -1;
		else carry = sum / 2, sum -= carry * 2;
		ret.push_back(sum);
		i--;
	}
	while(j >= 0)
	{
		int sum = y[j] - carry;
		if(sum < 0) sum = 1, carry = -1;
		else carry = sum / 2, sum -= carry * 2;
		ret.push_back(sum);
		j--;
	}
	if(carry == -1) ret.push_back(1);
	else if(carry == 1) ret.push_back(1), ret.push_back(1);
	while(!ret.empty() && ret.back() != 1) ret.pop_back();
	if(ret.size() == 0) return vector<int>(1, 0);
	reverse(ret.begin(), ret.end());
	return ret;
}
vector<int> reverse(vector<int> x)
{
	vector<int> tmp = x;
	tmp.push_back(0);
	return sum(x, tmp);
}
vector<int> twice(vector<int> x)
{
	x.push_back(0);
	return reverse(x);
}

int main()
{
	ll n; bool flag = 0;
	vector<int> sol(1, 0);
	vector<int> bin;

	v[0] = vector<int>(1, 1);
	for(int i = 1; i < 50; i++) v[i] = twice(v[i - 1]);

	cin >> n;

	if(n < 0) n *= -1, flag = 1;
	while(n)
	{
		bin.push_back(n % 2);
		n /= 2;
	}
	for(int i = 0; i < bin.size(); i++)
		if(bin[i]) sol = sum(sol, v[i]);
	if(flag) sol = reverse(sol);
	for(int i = 0; i < sol.size(); i++) printf("%d", sol[i]);
	return 0;
}