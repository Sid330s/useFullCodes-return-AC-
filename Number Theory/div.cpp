#include <bits/stdc++.h>
using namespace std;
long long int modexp(long long int a,long long int b,long long int mod){
	if(b==0)
		return 1;
	long long int res = modexp(a%mod,((b)/2),mod)%mod;
	res = (res*res)%mod;

	if(b&1)
		return res = (res*a)%mod;
	return res;
}
int modDivide(int a, int b,int m)
{
    a = a % m;
    long long int inv=modexp(b,m-2,m);
    return (inv * a) % m;
}

int main()
{
    int  a  = 50, b = 2, m = 7;
    cout<<modDivide(a, b, m);
    return 0;
}
