#include<bits/stdc++.h>
using namespace std;
int fun(string str) {
    int n = str.length();
    int rem1=0,rem2=0,rem3=0,ans=0;
    int sum1=0;
    for(int i=0;i<n;i++){
      if((str[i]-'0')%3==0) ans=ans+rem3,ans++;
      else if((str[i]-'0')%3==1) ans=ans+rem2;
      else ans=ans+rem1;
      sum1=sum1+(str[i]-'0');
      if(sum1%3==0) rem3++;
      else if(sum1%3==1) rem1++;
      else ans=rem2++;
    }
    return ans;
}
int main(){
  string str="200";
  cout<<fun(str)<<endl;
  return 0;
}
