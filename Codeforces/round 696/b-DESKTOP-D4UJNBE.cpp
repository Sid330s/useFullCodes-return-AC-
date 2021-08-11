#include <bits/stdc++.h>
using namespace std;
bool prime[100000];
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

}

long long int t,d,p1,p2;
int main()
{
    SieveOfEratosthenes(50000);
    cin>>t;
		while(t--){
			cin>>d;
			p1=1+d;
			while(!prime[p1]) p1++;
			p2=p1+d;
			while(!prime[p2]) p2++;

			cout<<p1*p2<<endl;

		}

    return 0;
}
