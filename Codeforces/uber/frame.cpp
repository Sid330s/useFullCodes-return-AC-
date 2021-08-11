#include<bits/stdc++.h>
using namespace std;
vector<string> fun(int n) {
    string str1="";
    string str2="";
    for(int j=0;j<n;j++) str1=str1+"*";
    str2=str2+"*";
    for(int j=1;j<n-1;j++) str2=str2+" ";
    str2=str2+"*";
    vector<string> ans;
    ans.push_back(str1);
    for(int i=1;i<n-1;i++){
      ans.push_back(str2);
    }
    ans.push_back(str1);
    return ans;
}

int main(){
  int n=8;
  vector<string> ans = fun(n);
  for(int i=0;i<n;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
