#include<bits/stdc++.h>
using namespace std;
string str;
long long int t,n;
bool f1,f2;
int main(){

  cin>>t;

  while(t--){
    cin>>str;
    n=str.length();
    f1=false;
    f2=false;
    for(int i=0;i<n-1;i++){
      if(str[i]=='1' && str[i+1]=='1' ) f1=true;
      if(f1 && str[i]=='0' && str[i+1]=='0' ) f2=true;
    }
    if(f1 && f2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

  }

  return 0;
}
