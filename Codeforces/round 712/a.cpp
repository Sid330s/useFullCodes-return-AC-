#include<bits/stdc++.h>
using namespace std;
long long int t,n,cnt;
string str,ans;
int main(){
  cin>>t;
  while(t--){
    cin>>str;
    n=str.length();
    cnt=0;
    while(cnt<n && str[cnt]=='a') cnt++;
    if(cnt==n) cout<<"NO"<<endl;
    else{
      cout<<"YES"<<endl;
      ans=str.substr(0,n-cnt)+"a"+str.substr(n-cnt,cnt);
      cout<<ans<<endl;
    }
 }
  return 0;
}
