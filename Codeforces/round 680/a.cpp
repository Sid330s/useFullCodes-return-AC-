#include<bits/stdc++.h>
using namespace std;
int t,x,n,a[100],b[100];
int main(){

  cin>>t;

  while(t--){
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    bool flag=true;
    for(int i=0;i<n;i++) if(a[i]+b[i]>x) {
      cout<<"No"<<endl;
      flag=false;
      break;
    }
    if(flag) cout<<"Yes"<<endl;
  }

  return 0;
}
