#include <stdio.h>

int arr[102][102];
int last[102];
int solve[102];
int main(){
	int t,n,k,id,m,i,j,rank;
	int a,b,c;
	scanf("%d",&t);
	while(t--){
		rank = 1;

		scanf("%d%d%d%d",&n,&k,&id,&m);
		for(i=0;i<=n;i++){
			solve[i] = last[i] = 0;
			for(j=0;j<=k;j++){
				arr[i][j] = 0;
			}
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(arr[a][b] < c)
				arr[a][b] = c;
			solve[a]++;
			last[a] = i;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=k;j++)
				arr[i][0]+=arr[i][j];
	
		for(i=1;i<=n;i++){
			if(arr[i][0] > arr[id][0]) rank++;
			else if( (arr[i][0] == arr[id][0]) && (solve[i] < solve[id])) rank++;
			else if( (arr[i][0] == arr[id][0]) && (solve[i] == solve[id]) && (last[i] < last[id])) rank++; 
		}
		printf("%d\n",rank);
	}


}