#include<bits/stdc++.h>
using namespace std;
long long int t,n,k,ans;

int main(){

  cin>>t;

  while(t--){
    cin>>n>>k;
    if(n%2==0) cout<<(k-1)%n+1<<endl;
    else{
      k=k+(k-1)/(n/2);
      cout<<(k-1)%n+1<<endl;
    }
 }
  return 0;
}
