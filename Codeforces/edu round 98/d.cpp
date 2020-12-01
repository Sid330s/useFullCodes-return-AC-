#include<bits/stdc++.h>
using namespace std;
long long int t,n,ans,den;


int main(){

  cin>>t;

  while(t--){
    cin>>n;
    cout<<(~n)<<" --> "<<bitset<8>(n)<<" <---> "<<bitset<8>(n && (~(n-1)))<<endl;

  }

  return 0;
}
