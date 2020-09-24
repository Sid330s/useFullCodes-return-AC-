#include<bits/stdc++.h>
using namespace std;

struct edge{
  int u;
  int v;
  long long int val;
};

struct cmp {
    bool operator()(Person const& e1, Person const& e2)
    {
        return e1.val < e2.val;
    }
};

priority_queue<edge,vector<edge>,cmp> pq;

vector<int> adj[100005];
bool visited[100005];

int main(){
  int n,,e,v,u;
  cin>>n>>e;
  while(e--){
    cin>>u>>v;
    adj[]
  }




  return 0;
}
