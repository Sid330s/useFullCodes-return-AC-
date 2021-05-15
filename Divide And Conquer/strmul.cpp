#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
string str1;
string str2;
string str3="";
void equalize(){
  n=str1.length();
  m=str2.length();
  if(n>m){
    k=n-m;
    while(k--) str2="0"+str2;
  }
  else{
    k=m-n;
    while(k--) str1="0"+str1;
    n=m;
  }
}
string add(string str1, string str2)
{
    if (str1.length() > str2.length()) swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
    int carry = 0;
    for (int i=n1-1; i>=0; i--)
    {
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry) str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
string multiply(string str1,string str2,int n){
  if(n==1){
    int x=(str1[0]-'0')*(str2[0]-'0');
    return to_string(x);
  }
  string str1a = str1.substr(0,(n+1)/2);
  string str1b = str1.substr((n+1)/2,n/2);
  string str2a = str2.substr(0,(n+1)/2);
  string str2b = str2.substr((n+1)/2,n/2);
  string ans1=multiply(str1a,str2a,(n+1)/2);
  string ans2=multiply(str1b,str2b,n/2);
  int k=n/2+n/2);
  while(k--) ans1=ans1+"0";
  int k=n/2;
  while(k--) str1a=str1a+"0",str2a=str2a+"0";
  string final_ans=add(ans1,ans2);
  string final_ans1=add(str1a)
  string final_ans2=
  string ans=add(ans,)

  return ;
}

int main(){
  cin>>t;
  while(t--){
    cin>>str1;
    cin>>str2;
    equalize();
    cout<<add(str1,str2)<<endl;
    cout<<multiply(str1,str2,n)<<endl;
  }
  return 0;
}
