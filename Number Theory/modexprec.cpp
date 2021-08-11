#include <stdio.h>
long long int power(long long int x,long long int y,long long int p)
{
    long long int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int a,b,mod;
		scanf("%lld%lld%lld",&a,&b,&mod);
		printf("%lld\n",power(a,b,mod));
	}
}
