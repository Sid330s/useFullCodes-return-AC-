#include<bits/stdc++.h>
using namespace std;
long long int t,diff,diff1,inc,n,k,dp;
bool flag;
string str1,str2;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    cin>>str1;
    cin>>str2;
    flag=true;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    cout<<str1<<endl;
    cout<<str2<<endl;
    diff=0;
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
      if(str2[i]-str1[i]>=0) dp[i]=dp[i-1]+str2[i]-str1[i];
    }
    for(int i=0;i<n;i++){
      if(str2[i]-(str1[i]+)>=0) diff=diff+str2[i]-str1[i];
      else {
        flag=false;
        break;
      }
    }
    cout<<diff<<endl;
    if(diff%k!=0) flag=false;

    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
