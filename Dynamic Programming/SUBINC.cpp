//-----------------//
// Siddharth Kale  //
//-----------------//
#include<bits/stdc++.h>
using namespace std;
long long int t,n,arr[100005],dp[100005],ans;

int main(){

  cin>>t;

  while(t--){
    cin>>n;
    arr[0]=-1;
    for(int i=1;i<=n;i++) cin>>arr[i];

    dp[0]=0;

    for(int i=1;i<=n;i++) {
      if(arr[i]>=arr[i-1]) dp[i]=dp[i-1]+1;
      else dp[i]=1;
    }

    ans=0;
    for(int i=1;i<=n;i++) ans=ans+dp[i];

    cout<<ans<<endl;

  }
  return 0;
}
