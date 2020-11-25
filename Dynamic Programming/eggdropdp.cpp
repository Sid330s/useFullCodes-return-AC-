int eggDrop(int n, int k)
{
    int dp[n+1][k+1];

    for(int j=0;j<=k;j++) dp[1][j]=j;
    for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
		dp[i][0] = 0;
	}

    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            dp[i][j]=INT_MAX;
            for(int x=0;x<j;x++){
                dp[i][j]=min(dp[i][j],1+max(dp[i-1][x],dp[i][j-1-x]));
            }
        }
    }

    return dp[n][k];
}
