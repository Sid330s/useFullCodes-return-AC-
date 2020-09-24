#include<bits/stdc++.h>
using namespace std;
long long int t,k,x,y;
int main(){

  cin>>t;

  while(t--){
    cin>>x>>y>>k;
    long long int ans = ((y+1)*k-1)/(x-1) + k;
    if(((y+1)*k-1)%(x-1)) ans=ans+1;
    printf("%lld\n",ans);
  }

  return 0;
}
