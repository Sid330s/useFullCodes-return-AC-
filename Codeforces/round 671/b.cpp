#include<bits/stdc++.h>
using namespace std;
long long int t,n,ans,term;

int main(){
  cin>>t;
  while(t--){
    cin>>n;
    ans=0;
    while(true){
      ans++;
      term = (pow(2,2*ans-1)-pow(2,ans-1));
      if( term > n ) {
        ans--;
        break;
      }
      n=n-term;
    }

    cout<<ans<<endl;
  }
  return 0;
}
