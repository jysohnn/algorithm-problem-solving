#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

vector<pair<int, string>> v =
{ { 1967,"DavidBowie" },
{ 1969,"SpaceOddity" },
{ 1970,"TheManWhoSoldTheWorld" },
{ 1971,"HunkyDory" },
{ 1972,"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars" },
{ 1973,"AladdinSane" },
{ 1973,"PinUps" },
{ 1974,"DiamondDogs" },
{ 1975,"YoungAmericans" },
{ 1976,"StationToStation" },
{ 1977,"Low" },
{ 1977,"Heroes" },
{ 1979,"Lodger" },
{ 1980,"ScaryMonstersAndSuperCreeps" },
{ 1983,"LetsDance" },
{ 1984,"Tonight" },
{ 1987,"NeverLetMeDown" },
{ 1993,"BlackTieWhiteNoise" },
{ 1995,"1.Outside" },
{ 1997,"Earthling" },
{ 1999,"Hours" },
{ 2002,"Heathen" },
{ 2003,"Reality" },
{ 2013,"TheNextDay" },
{ 2016,"BlackStar" } };

int t;

int main()
{
	cin >> t;
	while (t--)
	{
		int count = 0;
		int x, y; scanf("%d %d", &x, &y);
		for (int i = 0; i < v.size(); i++)
			if (x <= v[i].first && v[i].first <= y) count++;
		printf("%d\n", count);
		for (int i = 0; i < v.size(); i++)
			if (x <= v[i].first && v[i].first <= y)
				printf("%d %s\n", v[i].first, v[i].second.c_str());
	}
	return 0;
}