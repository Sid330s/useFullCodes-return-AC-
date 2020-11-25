#include <bits/stdc++.h>
using namespace std;
long long int t,n,k;
string str1;
int main()
{
  cin>>str1;
  n=str1.length();
  cout<<3<<endl;
  cout<<"L "<<2<<endl;
  n=n+1;
  cout<<"R "<<2<<endl;
  n=2*n-2;
  cout<<"R "<<n-1<<endl;

	return 0;
}
