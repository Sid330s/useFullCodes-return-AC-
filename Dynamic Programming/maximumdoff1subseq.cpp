int longestSubsequence(int N, int A[])
   {
       int dp[N];
       dp[0]=1;

       for(int i=1;i<N;i++){
           dp[i]=1;
           for(int j=i-1;j>=0;j--){
               if(abs(A[i]-A[j])==1) dp[i]=max(dp[i],dp[j]+1);
           }
       }

       return *max_element(dp,dp+N);
   }
