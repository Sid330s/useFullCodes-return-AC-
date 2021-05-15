#include<bits/stdc++.h>
using namespace std;
long long int t,x,y,u,d,l,r,n;
bool f1,f2;
string str;
int main(){
  cin>>t;
  while(t--){
    cin>>x>>y;
    cin>>str;
    n=str.length();
    l=0,r=0,u=0,d=0,f1=false,f2=false;
    for(int i=0;i<n;i++){
      if(str[i]=='U') u++;
      else if(str[i]=='D') d++;
      else if(str[i]=='R') r++;
      else l++;
    }
    //cout<<l<<" "<<r<<" "<<u<<" "<<d<<endl;
    if(x>=0 && x<=r) f1=true;
    else if(x < 0 && abs(x)<=l ) f1=true;

    if(y>=0 && y<=u) f2=true;
    else if(y < 0 && abs(y)<=d ) f2=true;

    if(f1&&f2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
