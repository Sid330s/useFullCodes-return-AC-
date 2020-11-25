class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N+2];

        for(int i=0;i<N;i++) dp[i][0]=0,dp[i][N+1]=0;
        for(int j=1;j<=N;j++) dp[0][j]=Matrix[0][j-1];
        for(int i=1;i<N;i++)
            for(int j=1;j<=N;j++)
                dp[i][j]=Matrix[i][j-1]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
        int ans=0;
        for(int j=1;j<=N;j++) ans = max(ans,dp[N-1][j]);
        return ans;
    }
};
