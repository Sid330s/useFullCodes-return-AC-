#include<bits/stdc++.h>
using namespace std;
long long int t,a,b,n,ans,count1;
string str;
int main(){
  cin>>t;
  while(t--){
    cin>>a>>b;
    cin>>str;
    n=str.length();
    ans=0;
    count1=0;
    for(int i=0;i<n;i++){
      if(str[i]=='0') {
        count1++;
      }
      else{
        if(ans==0) ans=ans+a;
        else ans=min(ans+a,ans+count1*b);
        count1=0;
      }
    }

   cout<<ans<<endl;
  }
  return 0;
}
