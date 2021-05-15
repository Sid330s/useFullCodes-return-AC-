#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) { return (a / gcd(a, b)) * b; }
int t,q,n,ans;
int parent[100005];
vector<int> children[100005];
vector<int> childrenPrune[100005];
int divtest[100005];
int nonLeaf[100005];
long long int max_factor[100005];
void prune(){
  for(int u=1;u<=n;u++){
    nonLeaf[u]=0;
    for(auto v:children[u]) if(divtest[v]!=0){
        childrenPrune[u].push_back(v);
        nonLeaf[u]++;
      }
 }
}
long long int prepro1(int u){
  if(divtest[u]==0) return 1;
  if(nonLeaf[u]==0) return divtest[u];
  for(auto v:childrenPrune[u]) max_factor[v]=prepro1(v);
  long long int ans=max_factor[childrenPrune[u][0]];
  for(auto v:childrenPrune[u]) {
    ans=lcm(ans,max_factor[v]);
    if(ans>1000000){
      ans=1000003;
      break;
    }
  }
  ans=ans*divtest[u];
  if(ans>1000003) return 1000003;
  return ans;
}

void dfs(int u,int w){
  if(divtest[u]==0){
    ans=ans+w;
    // cout<<"u:w|"<<u<<":"<<w<<endl;
    return;
  }
  if(w%divtest[u]!=0) return;
  if(w%max_factor[u]==0){
    ans=ans+w;
    return ;
  }
  ans=ans+(w/divtest[u])*(divtest[u]-nonLeaf[u]);
  for(auto v:childrenPrune[u]){
    dfs(v,w/divtest[u]);
  }
}

int main()
{
    cin>>n;
    for(int i=2;i<=n;i++) cin>>parent[i];
    for(int i=2;i<=n;i++) children[parent[i]].push_back(i);
    for(int i=1;i<=n;i++) divtest[i]=children[i].size();
    // for(int i=1;i<=n;i++){
    //    cout<<i<<":";
    //    for(auto v:children[i]){
    //      cout<<v<<" ";
    //    }
    //    cout<<endl;
    // }
    // cout<<"Div: "<<endl;
    // for(int i=1;i<=n;i++) cout<<i<<":"<<divtest[i]<<" ";
    // cout<<endl;
    max_factor[1] = prepro1(1);
    prune();

    // cout<<"Pro: "<<endl;
    // for(int i=1;i<=n;i++) cout<<i<<":"<<max_factor[i]<<" ";
    // cout<<endl;
    cin>>q;
    while(q--){
      int u,w;
      cin>>u>>w;
      ans=0;
      dfs(u,w);
      cout<<w-ans<<endl;
    }

    return 0;
}
