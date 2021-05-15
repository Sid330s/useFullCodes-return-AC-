#include<bits/stdc++.h>
using namespace std;
int getPosition(int n)
{
  if (n == 1 || n==2) return 1;
  if(n%2) return 2*getPosition(n/2) + 1;
  return 2*getPosition(n/2) - 1;
}
int t,m,n;
int main()
{
  cin>>t;
  while(t--){
    cout<<"Enter n: "<<endl;
    cin>>n;
    cout<<"Last Man: "<<getPosition(n)<<endl;
  }
	return 0;
}
