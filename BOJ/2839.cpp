#include <stdio.h>

int dp[5001]={0};

int main()
{
    int n;
    dp[3]=1,dp[5]=1;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++)
    {
        if(dp[i])
        {
            for(int j=1;i+j*3<n+1;j++)
                if(!dp[i+j*3] || dp[i+j*3]>dp[i]+j) dp[i+j*3]=dp[i]+j;
            for(int j=1;i+j*5<n+1;j++)
                if(!dp[i+j*5] || dp[i+j*5]>dp[i]+j) dp[i+j*5]=dp[i]+j;
        }
    }
    if(dp[n]) printf("%d",dp[n]);
    else printf("-1");
    return 0;
}