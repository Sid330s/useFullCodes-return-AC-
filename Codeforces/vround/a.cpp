#include<bits/stdc++.h>
using namespace std;
long long int t,n,max_eq,eq,arr[1000];
int main(){

  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0;
    max_eq=1;
    while(i<n-1){
      eq=1;
      while(i<n-1 && arr[i]==arr[i+1]) i++,eq++;
      max_eq=max(max_eq,eq);
      i++;
    }
    cout<<max_eq<<endl;
  }
  return 0;
}
