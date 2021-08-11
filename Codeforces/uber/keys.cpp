#include<bits/stdc++.h>
using namespace std;
int fun(string str,vector<char> arr) {
  int n=arr.size();
  bool isKey[26]={0};
  for(int i=0;i<n;i++) isKey[arr[i]-'a']=true;
  vector <string> tokens;
  stringstream check1(str);
  string intermediate;
  int ans=0;
  while(getline(check1, intermediate, ' ')) tokens.push_back(intermediate);
  for(int i = 0; i < tokens.size(); i++) {
    bool flag=true;
    cout<<tokens[i]<<" "<<tokens[i].size()<<endl;
    for(int j=0;j<tokens[i].size();j++){
      if('a'<=tokens[i][j] && tokens[i][j]<='z' && !isKey[tokens[i][j]-'a'] ) flag=false;
      if('A'<=tokens[i][j] && tokens[i][j]<='Z' && !isKey[tokens[i][j]-'A'] ) flag=false;
    }
    if(flag) ans++;
  }
  return ans;
}
int main(){
  string str="Hello, Bro Bhe";
  vector<char> arr{'h','e','o','l','b'};
  cout<<fun(str,arr)<<endl;
  return 0;
}
