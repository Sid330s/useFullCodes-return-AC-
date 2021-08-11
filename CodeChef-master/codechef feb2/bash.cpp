#include <bits/stdc++.h>
using namespace std;
int prime[1000005];
void SieveOfEratosthenes(int n)
{
  for(int i=2;i<n;i++) prime[i]=1;
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == 1)
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
}
pair<int,int> q[1000005];
int main()
{
    int t,x,y,n=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>q[i].first>>q[i].second;
        n=max(n,q[i].first);
    }
    SieveOfEratosthenes(n);
    for(int i=1;i<=n;i++) prime[i]+=prime[i-1];
    for(int i=0;i<t;i++)
    {
      if(prime[q[i].first]<=q[i].second) cout<<"Chef"<<"\n";
      else cout<<"Divyam"<<"\n";
    }
    return 0;
}
