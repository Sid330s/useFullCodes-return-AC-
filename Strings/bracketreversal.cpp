#include<bits/stdc++.h>
using namespace std;
int t,n;
string str;

int main(){
  cin>>t;
  while(t--){
  cin>>str;
  n=str.length();
  vector<char> stack;
  for(int i=0;i<n;i++) {
    if(str[i]=='{') stack.push_back('{');
    else if(!stack.empty() && stack.back()=='{') stack.pop_back();
    else stack.push_back('}');
  }
  int c1=0,c2=0;
  for(int i=0;i<stack.size();i++) {
    if(stack[i]=='}') c1++;
    else c2++;
  }
  int ans = (c1/2 + c2/2 + c1%2 + c2%2);
  if((c1+c2)%2) cout<<"-1"<<endl;
  else cout<<ans<<endl;
}
  return 0;
}
