#include<bits/stdc++.h>
using namespace std;
long long int t,n,arr[100005],q,k,diff[100005],l,r;
int main(){

    cin>>n>>q>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<=n-2;i++) diff[i+1]=arr[i+1]-arr[i]-1;
    // for(int i=0;i<=n-1;i++) cout<<diff[i]<<" ";
    // cout<<endl;
    diff[0]=0;
    for(int i=2;i<=n-1;i++) diff[i]+=diff[i-1];

    for(int i=0;i<q;i++) {
      cin>>l>>r;
      cout<<2*(diff[r-1]-diff[l-1])+(arr[l-1]-1)+(k-arr[r-1])<<endl;
    }

  return 0;
}
