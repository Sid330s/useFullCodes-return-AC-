#include <iostream>
using namespace std;
int t,n;
string dict[100005];
string str;

bool contains(string str){
   for(int i=0;i<n;i++) if(dict[i].compare(str)==0) return true;
   return false;
}

bool wordbreak(string str){
  int m=str.size();
  if(m==0) return true;
  for(int i=1;i<=m;i++){
    if(contains(str.substr(0,i)) && wordbreak(str.substr(i,m-i))) return true;
  }
  return false;
}

int main() {
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>dict[i];
    cin>>str;
    cout<<wordbreak(str)<<endl;
  }
	return 0;
}
