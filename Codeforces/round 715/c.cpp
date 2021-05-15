#include<bits/stdc++.h>
using namespace std;
long long int t,n,arr[20005];
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    long long int dp[n][n];
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int gap=1;gap<n;gap++){
      for(int i=0,j=gap;j<n;i++,j++){
        dp[i][j]=min(dp[i+1][j],dp[i][j-1])+ arr[j]-arr[i];
      }
    }
    cout<<dp[0][n-1]<<endl;
  return 0;
}
