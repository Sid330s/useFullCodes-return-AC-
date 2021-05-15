#include<bits/stdc++.h>
using namespace std;
long long int t,n,k1,k2,b,w,mb,mw,l;
int main(){

  cin>>t;

  while(t--){
    cin>>n>>k1>>k2;
    cin>>w>>b;
    mb=min(n-k1,n-k2);
    mw=min(k1,k2);
    l=(n-mb-mw);
    mb=mb+l/2;
    mw=mw+l/2;
    if(mw>=w && mb>=b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

  return 0;
}
