#include <bits/stdc++.h>
using namespace std;
int t;
string str;
long long int n;
long long int m;
string temp;
int j;
int main() {
  cin>>t;
  while(t--){
    cin>>str;
    n=pow(str.length(),2)-1;
    for(int i=0;i<=n;i++){
      temp="";
      m=i;
      j=str.length()-1;
      while(j>=0){
        if(m%2) temp= str[j]+temp;
        m=m/2;
        j--;
      }
      cout<<temp<<endl;
    }

  }
	return 0;
}
