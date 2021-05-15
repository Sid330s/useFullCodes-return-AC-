#include<bits/stdc++.h>
using namespace std;
long long int n,m,t,k,temp,ans;
long long int arr[4000000];
int main(){
  cin>>t;
  while(t--){
    cin>>n>>m>>k;
    int i;
    for(i=1;i<=min(n,m);i++) arr[i]=i,arr[n+m-i]=i;
    temp=n+m-i;
    for(;i<=temp;i++) arr[i]=min(n,m);
    ans=0;
    for(int i=1;i<=n+m-1;i++) if(arr[i]%2) ans=ans^(k+i+1);
    cout<<ans<<endl;
 }
  return 0;
}
