#include<bits/stdc++.h>
using namespace std;
long long int t,x,y,ans;
int main(){

  cin>>t;

  while(t--){
    cin>>x>>y;
    ans=2*((max(x,y) - min(x,y))) -1;
    if(ans < 0) ans = 2*min(x,y);
    else  ans = 2*min(x,y)+ans;


    cout<<ans<<endl;

  }

  return 0;
}
