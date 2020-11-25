#include <iostream>
using namespace std;
int t;
string str;

void permute(string str,int l,int r){
  if (l == r)  cout<<str<<endl;
  else
  {
      for (int i = l; i <= r; i++)
      {
          swap(str[l], str[i]);
          permute(str, l+1, r);
          swap(str[l], str[i]);
      }
  }
}


int main() {
  cin>>t;
  while(t--){
    cin>>str;
    permute(str,0,str.length()-1);
  }
	return 0;
}
