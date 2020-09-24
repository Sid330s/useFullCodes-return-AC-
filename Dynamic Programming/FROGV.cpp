//-----------------//
// Siddharth Kale  //
//-----------------//
#include <bits/stdc++.h>
using namespace std ;

const int maxN = 1e5+5 ;
long long int arr[maxN];
long long int n,k,p;

void solve()
{
	long long int a, b;
	cin >> a >> b;
  if(abs(arr[b]-arr[a])<=k) cout <<"YES"<< '\n' ;
  else cout <<"NO"<< '\n' ;
}
int main()
{
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++) cin>>arr[i];
    while(p--) solve();
}
