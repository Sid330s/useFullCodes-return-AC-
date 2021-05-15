#include<bits/stdc++.h>
using namespace std;
long long int t,n;
string cal(string str1,string str2){
  string ans="";
  bool flag=true;
  int i=0,j=0;
  while(i<n && j<n){
    if(flag){
      long long int req0=0;
      long long int has0=0;
      while(i<n && str1[i]!='1') req0++,i++;
      while(j<n && str2[j]!='1') has0++,j++;
      req0=max(req0,has0);
      while(req0--){
        ans=ans+'0';
      }
    }
    else{
      long long int req1=0;
      long long int has1=0;
      while(i<n && str1[i]!='0') req1++,i++;
      while(j<n && str2[j]!='0') has1++,j++;
      req1=max(req1,has1);
      while(req1--){
        ans=ans+'1';
      }
    }
    flag=flag^true;
  }
  while(i<n){
    ans=ans+str1[i];
    i++;
  }
  while(j<n){
    ans=ans+str2[j];
    j++;
  }
  return ans;
}
int main(){
  string str1,str2,str3;
  cin>>t;
  while(t--){
    cin>>n;
    n=2*n;
    cin>>str1;
    cin>>str2;
    cin>>str3;
    string ans = cal(str1,str2);
    if(ans.length()<=3*(n/2)) cout<<ans<<endl;
    else {
      ans = cal(str2,str3);
      if(ans.length()<=3*(n/2)) cout<<ans<<endl;
      else cout<<cal(str1,str3)<<endl;
    }

  }
  return 0;
}
