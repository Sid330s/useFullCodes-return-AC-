#include <iostream>
using namespace std;
int t,n,m;
string dict[100005];
bool dp[100005];
string str;

bool contains(string str){
   for(int i=0;i<n;i++) if(dict[i].compare(str)==0) return true;
   return false;
}

bool wordbreak(string str){
  int m=str.size();
  if(m==0) return true;
  for(int i=1;i<=m;i++){
    if(dp[i]==false && contains(str.substr(0,i))) dp[i]=true;
    if(dp[i]==true){
      if(i==m) return true;
      for(int j=i+1;j<=m;j++){
        if(dp[j]==false && contains(str.substr(i,j-i))) dp[j]=true;
        if(j==m && dp[j]==true) return true;
      }
    }
  }
  return false;
}

int main() {
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>dict[i];
    cin>>str;
    m=str.length();
    for(int i=0;i<=m;i++) dp[i]=false;
    cout<<wordbreak(str)<<endl;
  }
	return 0;
}
