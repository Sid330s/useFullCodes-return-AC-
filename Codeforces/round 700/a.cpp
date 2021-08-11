#include<bits/stdc++.h>
using namespace std;
long long int t,n;
string str;
int main(){

  cin>>t;

  while(t--){
    cin>>str;
    for(int i=0;i<str.length();i++){
      if(i%2==0){
        if(str[i]=='a') str[i]='b';
        else str[i]='a';
      }
      else {
        if(str[i]=='z') str[i]='y';
        else str[i]='z';
      }
    }
    cout<<str<<endl;
 }
  return 0;
}
