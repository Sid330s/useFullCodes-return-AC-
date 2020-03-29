#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007




long long int modexp(long long int a,long long int b)
{
	a%=mod;
	if(a==0||a==1)
	return a;
	if(b==0)
	return 1;
	if(b%2==0)
	{
		long long int res=modexp(a,b/2);
		return (res*res)%mod;
	}
	return (a*modexp(a,b-1))%mod;
}

int main()
{

	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int edg=(modexp(2,n+1)-2+mod)%mod;
		long long int denm=(2*edg*(edg+1))%mod;
		long long int num=0;
		for(long long int i=1;i<=n;i++)
		{
			long long int cf=modexp(2,i);
			cf=(cf*(i/2+i%2))%mod;
			num=(num+cf)%mod;
		}

		long long int ans=(2*modexp(denm,mod-2)*num)%mod;
		cout<<ans<<endl;


	}

	return 0;
}
