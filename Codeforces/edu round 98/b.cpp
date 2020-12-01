#include<bits/stdc++.h>
using namespace std;
long long int t,arr[100005],n,first,last;

int main(){

  cin>>t;

  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    long long int ans=0;
    first=*max_element(arr,arr+n);
    last=*min_element(arr,arr+n);
    for(int i=0;i<n;i++) ans=ans + first-arr[i];
    ans=ans-first+last;
    if(ans > last)  cout<<ans-last<<endl;
    else {
      last=last-ans;
      ans=(n-1)*ceil((long double)last/(n-1));
      cout<<ans-last<<endl;
    }


  }




  return 0;
}
