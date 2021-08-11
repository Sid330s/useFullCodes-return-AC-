#include <bits/stdc++.h>
using namespace std;
int t,q,n,ans;
int parent[100005];
vector<int> children[100005];
int divtest[100005];
void dfs(int u,int w){
  if(divtest[u]==0){
    ans=ans+w;
    cout<<"u:w|"<<u<<":"<<w<<endl;
    return;
  }
  if(w%divtest[u]!=0) return;
  for(auto v:children[u]){
    dfs(v,w/divtest[u]);
  }
}
int main()
{
    cin>>n;
    for(int i=2;i<=n;i++) cin>>parent[i];
    for(int i=2;i<=n;i++) children[parent[i]].push_back(i);
    for(int i=1;i<=n;i++) divtest[i]=children[i].size();
    for(int i=1;i<=n;i++){
       cout<<i<<":";
       for(auto v:children[i]){
         cout<<v<<" ";
       }
       cout<<endl;
    }
    cout<<"Div: "<<endl;
    for(int i=1;i<=n;i++) cout<<i<<":"<<divtest[i]<<" ";
    cout<<endl;
    cin>>q;
    while(q--){
      int u,w;
      cin>>u>>w;
      ans=0;
      dfs(u,w);
      cout<<w<<endl;
      cout<<w-ans<<endl;
    }

    return 0;
}
