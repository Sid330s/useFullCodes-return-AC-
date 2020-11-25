#include<bits/stdc++.h>
using namespace std;
int t,l,r,n,q,dp[1000];
bool flag;
string str;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>q;
    cin>>str;
    dp[0]=0;
    for(int i=1;i<=n;i++) {
      if(str[i-1]=='1') dp[i]=dp[i-1]+1;
      else dp[i]=dp[i-1];
    }
    while(q--){
      cin>>l>>r;
      flag=false;
      if(str[l-1]=='1'){
        if(dp[l-1]>0) flag=true;
      }
      else {
        if((l-1-dp[l-1])>0) flag=true;
      }

      if(str[r-1]=='1'){
        if((dp[n]-dp[r])>0) flag=true;
      }
      else {
        if((n-r-(dp[n]-dp[r]))>0) flag=true;
      }

      if(flag) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;

    }
  }
  return 0;
}
