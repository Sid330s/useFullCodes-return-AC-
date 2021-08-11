#include<bits/stdc++.h>
using namespace std;
long long int t,x,y,ans,b;

int main(){

  cin>>t;

  while(t--){
    cin>>x>>y;
    ans=0;
    b=sqrt(x+1);
    if(y<sqrt(x+1)){
      for(long long int i=2;i<=y;i++){
        ans=ans+min(x/(i+1),i-1);
      }
    }
    else{
      ans=ans+((b-1)*b)/2;
      for(int i=b+1;i<=y;i++){
        ans=ans+x/(i+1);
      }
    }

    cout<<ans<<endl;
 }
  return 0;
}
