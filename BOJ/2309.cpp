#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[9];
vector<int> sol;

int main()
{
	for(int i=0;i<9;i++) scanf("%d", a+i);
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
		{
			int sum = 0;
			for(int k=0;k<9;k++)
				if(k != i && k != j) sum += a[k];
			if(sum == 100)
			{
				for(int k=0;k<9;k++)
					if(k != i && k != j) sol.push_back(a[k]);
				sort(sol.begin(), sol.end());
				for(int k=0;k<sol.size();k++) printf("%d\n", sol[k]);
				return 0;
			}
		}
	return 0;
}