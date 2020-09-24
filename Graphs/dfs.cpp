#include<bits/stdc++.h>
using namespce std;

vector<int,vector<int>> adj; //adjecency list
bool vistied[100005]={false}

void dfs(int u){
   vistied[u]=true;
   cout<<u<<" ";
   if(!vistied[u]){
     for(int i=0;i<adj[u].size();i++){
       if(!vistied[adj[u][i]]) dfs(adj[u][i]);
     }
   }
}

int main(){

   int n,e,v,u;

   for(int i=0;i<e;i++){
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
   }

   dfs(0);

}
