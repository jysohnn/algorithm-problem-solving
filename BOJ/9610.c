#include <stdio.h>
int main()
{
	int i,n;
	int q[5]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x==0||y==0) q[0]++;
		else{
		if(x>0){
			if(y>0) q[1]++;
			else q[4]++;
		}
		else{
			if(y>0) q[2]++;
			else q[3]++;
		}}
	}
	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d",q[1],q[2],q[3],q[4],q[0]);
	return 0;
}