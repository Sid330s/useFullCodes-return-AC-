#include<bits/stdc++.h>
using namespace std;
long long int t,a,b,ans;
long long int calculate(int a,int b){
  int ans=0;
  while(a){
    a=a/b;
    ans++;
  }
  return ans;
}
int main(){

  cin>>t;

  while(t--){
    ans=0;
    cin>>a>>b;
    if(a<b) a=a/b,ans++;
    if(b==1) b++,ans++;
    while(a){
      if(calculate(a,b+1)+1<=calculate(a,b)) b++;
      else a=a/b;
      ans++;
    }
    cout<<ans<<endl;
 }
  return 0;
}
