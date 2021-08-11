#include <bits/stdc++.h>
using namespace std;
int t,q,n,u,w;
int parent[100005];
int goto1[100005];
vector<int> children[100005];
int divtest[100005];
map<pair<int, int>, int>  ump;
int prune2(int u){
    if(divtest[u]==0) return u;
    for(auto v:children[u]){
      goto1[v]=prune2(v);
    }
    if(divtest[u]==1){
      return goto1[children[u][0]];
    }
    return u;
}

int dfs(int u,int w){
  u=goto1[u];
  if(divtest[u]==0) return w;
  if(ump.find({u,w}) != ump.end()) return ump[{u,w}];
  if(w%divtest[u]!=0){
    ump[{u,w}]=0;
    return 0;
  }
  int ans=0;
  for(auto v:children[u]){
    ans=ans+dfs(v,w/divtest[u]);
  }
  ump[{u,w}]=ans;
  return ans;
}

int main()
{
    cin>>n;
    for(int i=2;i<=n;i++) cin>>parent[i];
    for(int i=2;i<=n;i++) children[parent[i]].push_back(i);
    for(int i=1;i<=n;i++) divtest[i]=children[i].size();
    goto1[1]=prune2(1);
    cin>>q;
    while(q--){

      cin>>u>>w;
      printf("%d\n",w-dfs(u,w));
    }

    return 0;
}
