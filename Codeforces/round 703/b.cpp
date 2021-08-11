#include<bits/stdc++.h>
using namespace std;
long long int t,ans,arr[100005],brr[100005],n,x,y,idx1,idx2;

int main(){

  cin>>t;

  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i],cin>>brr[i];
    sort(arr,arr+n);
    sort(brr,brr+n);
    if(n%2==1) cout<<"1"<<endl;
    else{
      idx1=(n/2 - 1);
      idx2=(n/2);
      ans=(arr[idx2]-arr[idx1]+1)*(brr[idx2]-brr[idx1]+1);
      cout<<ans<<endl;
    }
 }
  return 0;
}
