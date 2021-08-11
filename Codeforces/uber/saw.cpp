#include<bits/stdc++.h>
using namespace std;
int duplicatePairsOnSegment(vector<int> arr) {
    int ans=0;
    int n=arr.size();
    int dp[n];
    bool f1=true;
    bool f2=true;
    dp[0]=0;
    for(int i=1;i<n;i++){
      if(arr[i]==arr[i-1]) dp[i]=0,f1=true,f2=true;
      else if(arr[i]>arr[i-1] && f1) dp[i]=dp[i-1]+1,f1=false,f2=true;
      else if(arr[i]<arr[i-1] && f2) dp[i]=dp[i-1]+1,f2=false,f1=true;
      else dp[i]=1,f1=true,f2=true;
    }
    for(int i=0;i<n;i++) ans+=dp[i];
    return ans;
}

int main(){
  vector<int> arr{ 1, 1, 1, 0, 1 };
  cout<<duplicatePairsOnSegment(arr)<<endl;
  return 0;
}
