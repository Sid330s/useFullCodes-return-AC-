#include<bits/stdc++.h>
using namespace std;
long long int t,n;
string strb,stra;
int main(){

  cin>>t;

  while(t--){
    cin>>n;
    cin>>strb;
    stra="1";
    for(int i=1;i<n;i++){
      if((stra[i-1]-48)+(strb[i-1]-48)==1+(strb[i]-48)) stra=stra+'0';
      else stra=stra+'1';
    }
    cout<<stra<<endl;
 }
  return 0;
}
