#include<bits/stdc++.h>
using namespace std;
long long int t,n,cnM,cnT;
string str;
long long int dp[100005];
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    cin>>str;
    cnM=0;
    cnT=0;
    for(int i=0;i<n;i++){
      if(str[i]=='M') cnM++;
      else cnT++;
    }
    if(cnM!=n/3) cout<<"NO"<<endl;
    else{

      bool flag = true;
      dp[0]=0;
      for(int i=1;i<=n;i++){
        if(str[i-1]=='T')
          dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1];
        // cout<<dp[i]<<" ";
      }
      // cout<<endl;

      int l=1;
      int r=n/3;
      for(int i=1;i<=n;i++){
        if(str[i-1]=='M') {
          if(dp[i]-dp[0]<l){
            flag=false;
            break;
          }
          if(dp[n]-dp[i]<r){
            flag=false;
            break;
          }
          l++;
          r--;
        }
      }

      if(flag) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }

 }
  return 0;
}
