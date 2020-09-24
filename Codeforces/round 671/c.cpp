#include<bits/stdc++.h>
using namespace std;
int t,n,x,arr[10000],increase,decrease;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>x;
    increase=0;
    decrease=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) {
      cout<<x-arr[i]<<" ";
      if(arr[i]<x) increase=increase+x-arr[i];
      else decrease=decrease+ arr[i]-x;
    }
    cout<<endl;
    cout<<increase<<"-- "<<decrease<<endl;

  }
  return 0;
}
