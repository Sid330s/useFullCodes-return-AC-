#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}
int t,q,n;
int parent[100005];
int goto1[100005];
vector<int> children[100005];
vector<int> childrenPrune[100005];
int divtest[100005];
int nonLeaf[100005];
long long int max_factor[100005];
map<pair<int, int>, int>  ump;
void prune(){
  for(int u=1;u<=n;u++){
    nonLeaf[u]=0;
    for(auto v:children[u]) if(divtest[v]!=0){
        childrenPrune[u].push_back(v);
        nonLeaf[u]++;
      }
 }
}
int prune2(int u){
    if(divtest[u]==0) return u;
    for(auto v:children[u]) goto1[v]=prune2(v);
    if(divtest[u]==1) return goto1[children[u][0]];
    return u;
}
long long int prepro1(int u){
  if(divtest[u]==0) return 1;
  if(nonLeaf[u]==0) return divtest[u];
  for(auto v:children[u]) max_factor[v]=prepro1(v);
  long long int ans=max_factor[children[u][0]];
  for(auto v:children[u]) ans=gcd(ans,max_factor[v]);
  ans=ans*divtest[u];
  return ans;
}

int dfs(int u,int w){
  u=goto1[u];
  if(divtest[u]==0) return w;
  if(ump.find({u,w}) != ump.end()) return ump[{u,w}];
  if(w%max_factor[u]!=0){
    ump[{u,w}]=0;
    return 0;
  }
  int ans=(w/divtest[u])*(divtest[u]-nonLeaf[u]);
  for(auto v:childrenPrune[u])  ans=ans+dfs(v,w/divtest[u]);
  ump[{u,w}]=ans;
  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=2;i<=n;i++) cin>>parent[i];
    for(int i=2;i<=n;i++) children[parent[i]].push_back(i);
    for(int i=1;i<=n;i++) divtest[i]=children[i].size();
    goto1[1]=prune2(1);
    prune();
    max_factor[1] = prepro1(1);
    cin>>q;
    while(q--){
      int u,w;
      cin>>u>>w;
      printf("%d\n",w-dfs(u,w));
    }
    return 0;
}
