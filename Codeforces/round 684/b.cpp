#include<bits/stdc++.h>
using namespace std;
long long int t,n,k,m,arr[200005],ans;
string str;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=0;i<n*k;i++) cin>>arr[i];
    ans=0;
    m=n-(n+1)/2;
    for(int i=1;i<=k;i++){
        ans=ans+arr[n*k-(m+1)*i];
    }
   cout<<ans<<endl;
  }
  return 0;
}
