#include <cstdio>
#include <vector>

using namespace std;

vector<bool> v, w;
const int SIZE = 100000;

int main()
{
	int x;
	for (int i = 0; i < SIZE; i++) scanf("%1d", &x), v.push_back(x);
	for (int i = 0; i < SIZE; i++) scanf("%1d", &x), w.push_back(x);
	for (int i = 0; i < SIZE; i++) printf("%d", v[i] & w[i]); putchar('\n');
	for (int i = 0; i < SIZE; i++) printf("%d", v[i] | w[i]); putchar('\n');
	for (int i = 0; i < SIZE; i++) printf("%d", v[i] ^ w[i]); putchar('\n');
	for (int i = 0; i < SIZE; i++) printf("%d", !v[i]); putchar('\n');
	for (int i = 0; i < SIZE; i++) printf("%d", !w[i]); putchar('\n');
	return 0;
}