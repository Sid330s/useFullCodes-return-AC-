#include <stdio.h>
long long int mod;
long long int power(long long int a,long long int b){
	if(b==0)
		return 1;
	long long int res = power(a%mod,((b)/2))%mod;
	res = (res*res)%mod;

	if(b&1)
		return res = (res*a)%mod;
	return res;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int a,b;
		scanf("%lld%lld%lld",&a,&b,&mod);
		printf("%lld\n",power(a,b));
	}
}
