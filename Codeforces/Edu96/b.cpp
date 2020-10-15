#include<bits/stdc++.h>
using namespace std;
long long int t,arr[200005],n,k;
int main(){

  cin>>t;

  while(t--){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,greater<int>());
    for(int i=1;i<=k;i++) {
      arr[0]=arr[0]+arr[i];
      arr[i]=0;
    }

    if(k) cout<<arr[0]-arr[1]<<endl;
    else cout<<arr[0]-arr[n-1]<<endl;

  }

  return 0;
}
