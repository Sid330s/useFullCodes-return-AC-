#include<bits/stdc++.h>
using namespace std;
long long int t,x11,y11,x22,y22,ans;
int main(){

  cin>>t;

  while(t--){
    cin>>x11>>y11>>x22>>y22;
    if(x11==x22 || y11==y22) ans=abs(x11-x22)+abs(y11-y22);
    else  ans=abs(x11-x22)+abs(y11-y22)+2;
    printf("%lld\n",ans);
  }

  return 0;
}
