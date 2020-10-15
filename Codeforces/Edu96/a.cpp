#include<bits/stdc++.h>
using namespace std;
long long int t,n,x,y,z;
int main(){

  cin>>t;

  while(t--){
    cin>>n;
    bool flag=false;
    for(int i=0;i<=n/7;i++) {
      for(int j=0;j<=n/5;j++){
        if((n-7*i-5*j)%3==0 && (n-7*i-5*j)>=0 ) {
          flag=true;
          x=(n-7*i-5*j)/3;
          y=j;
          z=i;
        }
      }
    }
    if(flag) cout<<x<<" "<<y<<" "<<z<<endl;
    else cout<<"-1"<<endl;
  }

  return 0;
}
