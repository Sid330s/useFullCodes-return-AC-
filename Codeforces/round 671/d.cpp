#include<bits/stdc++.h>
using namespace std;
long long int t,n,x,arr[100005];
int main(){

    cin>>n;
    vector<long long int> vec(n,0);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end(),greater<int>());
    for(int i=1;i<n;i=i+2) {
      arr[i]=vec.back();
      vec.pop_back();
    }
    int ans=0;
    for(int i=0;i<n;i=i+2) {
      arr[i]=vec.back();
      vec.pop_back();
    }
    x=0;
    for(int i=1;i<=n-2;i++) if(arr[i]<arr[i+1] && arr[i]<arr[i-1] ) x++;

    cout<<ans<<endl;
    for(int i=0;i<=n-1;i++) cout<<arr[i]<<" ";
    cout<<endl;


  return 0;
}
