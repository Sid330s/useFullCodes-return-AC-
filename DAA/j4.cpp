#include<bits/stdc++.h>
using namespace std;
int t,n;
int msbPosition(int n)
{
	int pos = 0;
	while (n != 0) {
		pos++;
		n = n >> 1;
	}
	return pos;
}
int getPosition()
{
	int position = msbPosition(n);
	int j = 1 << (position - 1);
	n = n ^ j;
	n = n << 1;
	n = n | 1;
	return n;
}
int main()
{
  cin>>t;
  while(t--){
    cout<<"Enter n: "<<endl;
    cin>>n;
    cout<<"Last Man: "<<getPosition()<<endl;
  }
	return 0;
}
