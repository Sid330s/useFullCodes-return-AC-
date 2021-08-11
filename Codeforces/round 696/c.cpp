#include<bits/stdc++.h>
using namespace std;
int t,n,arr[200005],ans;

int main(){
  cin>>t;
  while(t--){
    unordered_map<int, int> m;
    vector<int> v;

    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    ans=INT_MAX;
    v.push_back(arr[0]);
    for(int i=1;i<n;i++) if(v.back()!=arr[i]) v.push_back(arr[i]);
    n=v.size();

    if( n==1 ) ans=0;
    else if(n==2) ans=1;
    for (int i = 1; i <=n-2; i++) m[v[i]]++;

  	for (auto e : m)  ans=min(ans,e.second+1);

    if(m[v[0]]==0) ans=min(ans,1);
    if(m[v[n-1]]==0) ans=min(ans,1);

    cout<<ans<<endl;
  }
  return 0;
}
