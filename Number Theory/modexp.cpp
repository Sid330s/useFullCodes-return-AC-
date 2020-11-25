#include <stdio.h>
long mod;
long power(long a,long b){
	if(b==0)
		return 1;
	long res = power(a%mod,((b)/2))%mod;
	res = (res*res)%mod;

	if(b&1)
		return res = (res*a)%mod;
	return res;
}

long power(long,long);
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long a,b;
		scanf("%ld%ld%ld",&a,&b,&mod);
		printf("%ld\n",power(a,b));
	}
}
