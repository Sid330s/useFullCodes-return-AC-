#include<bits/stdc++.h>
using namespace std;
long long int p,a,b,c,t;

int main(){
  cin>>t;
  while(t--){
    cin>>p>>a>>b>>c;
    a=ceil((long double)p/a)*a;
    b=ceil((long double)p/b)*b;
    c=ceil((long double)p/c)*c;
    cout<<min(a,min(b,c))-p<<endl;
 }
  return 0;
}
