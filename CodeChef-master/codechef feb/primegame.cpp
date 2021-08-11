#include <bits/stdc++.h>
using namespace std;
int t,x,y,n;
int qx[1000005];
int qy[1000005];
int isPrime[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int i=0;i<t;i++) cin>>qx[i]>>qy[i];
    for(int i=0;i<t;i++) n=max(n,qx[i]);
    for(int i=2;i<n;i++) isPrime[i]=1;
    for (int p = 2; p * p <= n; p++)
        if (isPrime[p] == 1)
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = 0;
    for(int i=1;i<=n;i++) isPrime[i]+=isPrime[i-1];
    for(int i=0;i<t;i++) (isPrime[qx[i]]>qy[i]) ? cout<<"Divyam"<<endl : cout<<"Chef"<<endl;
    return 0;
}
