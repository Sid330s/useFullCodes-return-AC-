#include<bits/stdc++.h>
using namespace std;
string fun(string str,vector<int> arr) {
  int n=arr.size();
  if(n%2) arr.push_back(0),n++;
  int idx=0;
  string ans="";
  for(int i=0;i<n;i+=2){
    string s1=str.substr(idx,arr[i]);
    string s2=str.substr(idx+arr[i],arr[i+1]);
    idx=idx+arr[i]+arr[i+1];
    ans=ans+s2+s1;
  }
  return ans;
}
int main(){
  string str="siddharth";
  vector<int> arr{2,3,4};
  cout<<fun(str,arr)<<endl;
  return 0;
}
