#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
long long int n,q,M,inp;
string arr[200005];
long long int k[30];
long long int dp[200005][3];
long long int ans[200005];
long long int modexp(long long int x,long long int y,long long int p)
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

long long int modDivide(long long int a, long long int b)
{
    a = a % MOD;
    return (modexp(b,MOD-2,MOD) * a) % MOD;
}
int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>inp;
        bitset<30> b(inp);
        arr[i]=b.to_string();
    }
    for(int j=0;j<30;j++){
        k[j]=0;
        for(int i=0;i<n;i++) if(arr[i][j]=='1') k[j]++;
    }
    long long int term=pow(2,29);
		term=term%MOD;
    for(int i=0;i<=n;i++) ans[i]=0;
    for(int j=0;j<30;j++){
      dp[0][1]=0;
      dp[0][0]=0;
      dp[0][2]=0;
      dp[1][0]=(n-k[j])%MOD;
      dp[1][1]=(k[j])%MOD;
      dp[1][2]=n;
      ans[1]=(ans[1]+(dp[1][1]*term)%MOD)%MOD;
      for(int m=2;m<=n;m++){
        dp[m][1]=modDivide(((dp[m-1][1]*dp[1][0])%MOD+(dp[m-1][0]*dp[1][1])%MOD-((n-m+2)*dp[m-2][1])%MOD+MOD)%MOD,m);
        dp[m][1]=dp[m][1]%MOD;
        dp[m][2]=modDivide((dp[m-1][2]*(n-m+1))%MOD,m);
        dp[m][0]=(dp[m][2]-dp[m][1]+MOD)%MOD;
        ans[m]=(ans[m]+(dp[m][1]*term)%MOD)%MOD;
      }
      term=term/2;
    }
    for(int m=2;m<=n;m++) ans[m]=(ans[m]+ans[m-1])%MOD;
    for(int m=1;m<=n;m++){
        cout<<"m:"<<m<<" "<<ans[m]<<endl;
    }
    cin>>q;
    while(q--){
      cin>>M;
      cout<<ans[M]<<endl;
    }
    return 0;
}
