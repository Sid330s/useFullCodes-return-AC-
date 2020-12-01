#include<bits/stdc++.h>
using namespace std;
long long int t,n,c0,c1,h,cnt0,cnt1;
string str1;
int main(){

  cin>>t;

  while(t--){
    cin>>n>>c0>>c1>>h;
    cin>>str1;
    cnt0=0;
    cnt1=0;
    for(int i=0;i<n;i++) {
      if(str1[i]=='0') cnt0++;
      else cnt1++;
    }

    if( max(c0,c1) > h + min(c0,c1) ) {
      if(c0 > c1) cout<<(h+c1)*cnt0+c1*cnt1;
      else cout<<(h+c0)*cnt1 +c0*cnt0;

    }
    else cout<<c1*cnt1+c0*cnt0;
    cout<<endl;
 }
  return 0;
}
