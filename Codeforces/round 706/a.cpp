#include<bits/stdc++.h>
using namespace std;
string s;
long long int n,k,t;
long long int m;
bool flag;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    cin>>s;
    m=0;
    flag=true;
    for(int i=0;i<n/2;i++){
      if(s[i]==s[n-i-1]) m+=2;
      else{
        m++;
        flag=false;
        break;
      }
    }
    if((flag && n%2)||(m>=2*k+1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
 }
  return 0;
}
