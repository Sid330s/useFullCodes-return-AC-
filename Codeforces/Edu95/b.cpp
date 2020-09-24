#include<bits/stdc++.h>
using namespace std;
int t,arr[1000],n;
bool locked[1000];
int main(){

  cin>>t;

  while(t--){
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>locked[i];
    for(int i=0;i<n;i++) if(!locked[i]) vec.push_back(arr[i]);
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++) if(!locked[i]){
      arr[i]=vec.back();
      vec.pop_back();
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
  }




  return 0;
}
