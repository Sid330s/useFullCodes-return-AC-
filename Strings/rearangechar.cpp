#include<bits/stdc++.h>
using namespace std;
int t,n;
string str;
int main()
{
  cin>>t;
  while(t--){
  cin>>str;
  n=str.length();
  int freq[26]={0};
  for(int i=0;i<n;i++) freq[str[i]-97]++;
  bool flag=true;
  for(int i=0;i<26;i++) if(freq[i]>(n+1)/2) flag=false;
  cout<<flag<<endl;
}
  return 0;
}
