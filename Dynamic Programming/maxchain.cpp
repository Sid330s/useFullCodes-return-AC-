
bool comparator(val a,val b){
    return a.first<b.first;
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,comparator);
          int dp[n];
          dp[0]=1;
          for(int i=1;i<n;i++){
              dp[i]=1;
              for(int j=i-1;j>=0;j--){
                  if(p[i].first>p[j].second) dp[i]=max(dp[i],dp[j]+1);
              }
          }

          return dp[n-1];
}
