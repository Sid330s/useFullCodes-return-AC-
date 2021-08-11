#include<bits/stdc++.h>
using namespace std;
long long int t,n,res,max_w;
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    long long int next[n];
    long long int w[n]={0};
    for(int i=0;i<n;i++) cin>>next[i];
    for(int i=0;i<n;i++) if(next[i]!=-1) w[next[i]]+=i;
    res=0;
    max_w=0;
    for(int i=0;i<n;i++)
      if(max_w<w[i])
        max_w=w[i],res=i;
    cout<<res<<endl;
  }
  return 0;
}
