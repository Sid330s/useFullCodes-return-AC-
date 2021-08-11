#include<bits/stdc++.h>
using namespace std;

long long int f(long long int next[],long long int n){
	long long int res = 0;
	bool visited[n];
	for(int i=0;i<n;i++) visited[i]=false;
	for(int i=0;i<n;i++){
		if(visited[i]) continue;
		visited[i]=true;
		int j=next[i];
		while(j!=-1 && !visited[j]){
			visited[j]=true;
			int j=next[j];
		}
		if(visited[j]){
			re
		}
	}
}

int main(){
	long long int t,n,res,max_w;
  cin>>t;
  while(t--){
    cin>>n;
    long long int next[n];
    for(int i=0;i<n;i++) cin>>next[i];
    res=f(next,n);
    cout<<res<<endl;
  }
  return 0;
}
