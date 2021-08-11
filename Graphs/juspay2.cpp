#include<bits/stdc++.h>
using namespace std;

int f(int next[],int n,int u,int v){
  bool set1[n];
  bool set2[n];
  //cout<<"hi"<<endl;
  for(int i=0;i<n;i++) set1[i]=false;
  for(int i=0;i<n;i++) set2[i]=false;
  int start = u;
  while(u!=-1 && !set1[u]) set1[u]=true,u=next[u];
  if(start==u && set1[v]) {
     int uv=0,vu=0;
     while(u!=v) u=next[u],uv++;
     while(v!=start) v=next[v],vu++;
     if(uv<=vu) return u;
     return v;
  }
  while(v!=-1 && !set2[v] && !set1[v]) set2[v]=true,v=next[v];
  if(set2[v]) v=-1;

  return v;
}

int main(){
  int t,n,u,v;
  cin>>t;
  while(t--){
    cin>>n;
    int next[n];
    for(int i=0;i<n;i++) cin>>next[i];
    cin>>u>>v;
    cout<<f(next,n,u,v)<<endl;
  }
  return 0;
}
