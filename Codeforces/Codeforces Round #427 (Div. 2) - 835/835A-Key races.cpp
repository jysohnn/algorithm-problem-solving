#include <cstdio>
#include <algorithm>

using namespace std;

int s, v1, v2, t1, t2;

int main()
{
 int a, b;
 scanf("%d %d %d %d %d",&s,&v1,&v2,&t1,&t2);
 a = 2 * t1 + s * v1;
 b = 2 * t2 + s * v2;
 if(a < b) printf("First");
 else if(a > b) printf("Second");
 else printf("Friendship");
 return 0;
}