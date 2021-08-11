#include<bits/stdc++.h>
using namespace std;
long long int t,ans,arr[100005],n;
bool flag;


int main(){

  cin>>t;

  while(t--){
    cin>>n;
    ans=0;
    flag=true;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) {
      ans=ans+arr[i];
      if(ans<((i+1)*(i))/2) flag=false;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
 }
  return 0;
}
