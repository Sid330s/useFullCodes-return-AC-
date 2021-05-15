#include<bits/stdc++.h>
using namespace std;
int getPosition(int n)
{
  if (n == 1) return 1;
  return (getPosition(n - 1) + 1) % n + 1;
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
