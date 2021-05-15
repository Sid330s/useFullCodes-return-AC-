#include<bits/stdc++.h>
using namespace std;
long long int t,n,arr[20005];

int main(){
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) if(arr[i]%2) cout<<arr[i]<<" ";
    for(int i=0;i<n;i++) if(arr[i]%2==0) cout<<arr[i]<<" ";
    cout<<endl;
 }
  return 0;
}
