#include <bits/stdc++.h>
using namespace std;
int t;
long long int n;
long long int m;
int j;
void rec(string str,string temp){
  if(str.empty()){
    cout<<temp<<endl;
    return;
  }
  string str2=str.substr(1);
  rec(str2,temp);
  temp+=str[0];
  rec(str2,temp);
}
int main() {
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    rec(str,"");
  }
	return 0;
}
