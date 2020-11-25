#include<bits/stdc++.h>
using namespace std;

long modexp(long long int a,long long int b,long long int mod){
	if(b==0)
		return 1;
	long long int res = modexp(a%mod,((b)/2),mod)%mod;
	res = (res*res)%mod;

	if(b&1)
		return res = (res*a)%mod;
	return res;
}

int main()
{

	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,mod;
		cin>>n>>mod;

		long long int ans=modexp(n,mod-2,mod);
		cout<<ans<<endl;

	}

	return 0;
}
