#include <stdio.h>

int r[104];
int num[104];
int s[104];


int main() {
	int t, n, i, j,k,flag;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		flag = 0;

		for (i = 1; i <= n; i++)
			s[i] = 0;
		for (i = 1; i <= n; i++)
			scanf("%d", &r[i]);
		for (i = 1; i <= n; i++)
			num[i] = i;
		s[n] = r[n] + 1;
		num[s[n]] = 0;
		for (i = n-1; i >= 1; i--) {
			if (r[i] >= i) {
				flag = 1;
				break;
			}
			k = 1;
			while (r[i]) {
				if (num[k]!=0)
					r[i]--;
				k++;
			}
			while (num[k]==0)k++;
			s[i] = num[k];
			num[k] = 0;
		}

		if (flag == 0) {
			for (i = 1; i <= n; i++) {
				printf("%d ", s[i]);
			}
		}
		else {
			printf("IMPOSSIBLE");
		}
		printf("\n");
	}
}