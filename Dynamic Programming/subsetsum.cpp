/*


             0 1 2 3 4 5 6 7 8 9 10 11
          0  1 0 0 0 0 0 0 0 0 0 0  0
          1  1 1 0 0 0 0 0 0 0 0 0  0
          5  1 1 0 0 0 1 0 0 0 0 0  0
          5  1 1 0 0 0 1
         11


         if (A[i] > j)
         DP[i][j] = DP[i-1][j]
         else
         DP[i][j] = DP[i-1][j] OR DP[i-1][j-A[i]]


*/

int equalPartition(int n, int arr[])
    {
        int S=0;
        for(int i=0;i<n;i++) S+=arr[i];
        if(S%2) return 0;
        S=S/2;
        sort(arr,arr+n);
        bool dp[n][S+1]={0};
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=S;j++){
                if(j<arr[i]) dp[i][j]=dp[i-1][j];
                else dp[i][j]= (dp[i-1][j] || dp[i-1][j-arr[i]]) ;
            }
        }
        return dp[n-1][S];
    }

    bool isSubsetSum(int set[], int n, int sum)
  {

      bool subset[n + 1][sum + 1];


      for (int i = 0; i <= n; i++)
          subset[i][0] = true;


      for (int i = 1; i <= sum; i++)
          subset[0][i] = false;
      for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= sum; j++) {
              if (j < set[i - 1])
                  subset[i][j] = subset[i - 1][j];
              if (j >= set[i - 1])
                  subset[i][j] = subset[i - 1][j]
                                 || subset[i - 1][j - set[i - 1]];
          }
      }


      return subset[n][sum];
  }
