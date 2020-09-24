#include<bits/stdc++.h>
using namespace std;

int parent[100005];
int size[100005];

void union(int u, int v){
  int root1=find(u);
  int root2=find(v);

  if(size[root1]>size[root2]) parent[v]=root1, size[root1] = size[root1] + size[root2];
  else parent[u]=root2, size[root2] = size[root2] + size[root1];

}

int find(int u){
  int root=u;

  while(root!=parent[root]) root=parent[root];

  while(root!=u){
    int next=parent[u];
    parent[u]=root;
    u=next;
  }

  return root;

}
struct edge{
  int value;
  int v;
  int u;
}
vector<edge> edges;

bool cmp(edge e1,edge e2){
  return (e1.value < e2.value);
}

int main(){
  int n,e,v,u;
  cin>>n>>e;

  for(int i=0;i<n;i++) parent[i]=i,size[i]=1;

  while (e--) {
    edge ed;
    cin>>ed.u>>ed.v;
    edges.push_back(ed);
  }

  sort(edges.begin(),egdes.end(),cmp);

  e=edges.size();

  while(e--){
    if()
  }




  return 0;
}
