//-----------------//
// Siddharth Kale  //
//-----------------//
//  f(x) = f(x-3) + f(x-2)
//  f(1)= 0 , f(2)= 1 , f(3)= 1 , f(4)=1
#include<bits/stdc++.h>
using namespace std;
long long int t,n,dp[1000005];
int main(){

  cin>>t;

  while(t--){
    cin>>n;

    dp[0]=1;
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++) dp[i]=(dp[i-2]%1000000009+dp[i-3]%1000000009)%1000000009;
    cout<<dp[n]<<endl;
  }
  return 0;
}
