#include<bits/stdc++.h>
using namespace std;

int t,n,arr[1000];

int main(){
  cin>>t;
  while (t--) {
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum1=0;
    for(int i=0;i<n;i++) sum1=sum1+arr[i];

    if(sum1>0) sort(arr,arr+n,greater<int>());
    if(sum1<0) sort(arr,arr+n);

    if(sum1){
      cout<<"YES"<<endl;
      for(int i=0;i<n;i++) cout<<arr[i]<<" ";
      cout<<endl;
    }
    else cout<<"NO"<<endl;

  }

  return 0;
}
