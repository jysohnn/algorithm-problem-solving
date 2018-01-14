#include <cstdio>
#include <deque>
using namespace std;

int weight = 0;
deque<int> input;
deque<int> b;
int main() {
	int n, w, l;
	int t = 0;
	
	//puts("!");
	scanf("%d %d %d", &n, &w, &l);
	for (int i = 0; i < w; i++)
		b.push_back(0);
	//puts("!");
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	//puts("!");
	int tmp;
	while (1)
	{
		
		tmp = b.front();
		b.pop_front();
		weight -= tmp;

		if (input.size() != 0 && weight + input.front() <= l)
		{
			tmp = input.front();
			input.pop_front();
			b.push_back(tmp);
			weight += tmp;
		}
		else
		{
			b.push_back(0);
		}
		t++;
		if (weight == 0) break;
	}
	printf("%d\n", t);
	return 0;
}