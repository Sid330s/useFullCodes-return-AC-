#include<bits/stdc++.h>
using namespace std;
bool arr[200005];
int t,n,ans;
int main(){

  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    ans=0;
    if(arr[0]) ans++;
    vector<int> vec;
    int term=0;
    for(int i=1;i<n;i++){
      if(arr[i]) term++;
      else {
        vec.push_back(term);
        term=0;
      }
    }
    vec.push_back(term);
    for(int i=0;i<vec.size();i++) ans=ans+vec[i]/3;
    cout<<ans<<endl;
  }


  return 0;
}
