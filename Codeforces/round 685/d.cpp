#include<bits/stdc++.h>
using namespace std;
long long int t,n,arr[30005],leftmin[30005],rightmin[30005];
int main(){

  cin>>t;

  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    leftmin[0]=arr[0];
    for(int i=1;i<n;i++) leftmin[i]=min(arr[i],leftmin[i-1]);
    rightmin[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--) rightmin[i]=min(arr[i],rightmin[i+1]);
    bool ans=true;
    for(int i=1;i<=n-2;i++) if(leftmin[i]+rightmin[i]<arr[i]) ans=false;
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

 }
  return 0;
}
// Docker - A
