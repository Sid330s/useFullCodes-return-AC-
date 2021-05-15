#include<bits/stdc++.h>
using namespace std;
string a[200005];
long long int mod=998244353;
long long int sb1,sbi,nsb1,nsbi,t1,t2,t3,val;
long long int sb[30];
long long int tv[200005];
long long int ans[200005];
long long int sv[200005];
long long int nsv[200005];
long long int mv[200005];
long long int pv[200005];
long long int modadd(long long int x,long long int y){
    x=x%mod;
    y=y%mod;
    long long int ans=x+y;
    return ans%mod;
}
long long int modsub(long long int x,long long int y){
    x=x%mod;
    y=y%mod;
    long long int ans=x-y+mod;
    return ans%mod;
}
long long int modmul(long long int x,long long int y){
    x=x%mod;
    y=y%mod;
    long long int ans=x*y;
    return ans%mod;
}
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y);
int modInverse(long long int b, long long int m)
{
    long long int x, y;
    long long int g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x%m + m) % m;
}
int modDivide(long long int a, long long int b, long long int m)
{
    a = a % m;
    long long int inv = modInverse(b, m);
    return (inv * a) % m;
}
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
{

    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    long long int x1, y1;
    long long int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int main()
{
    long long int max1=0,max2=0,ti,num,den,pow=1,index,n,q,x,v,val;
    sv[0]=0;
    nsv[0]=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        max1=max(max1,x);
        bitset<30> b(x);
        a[i]=b.to_string();
    }
    //for(int i=0;i<n;i++)    cout<<i<<"=>"<<a[i]<<endl;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>mv[i];
        max2=max(max2,mv[i]);
    }
    tv[0]=1;
    tv[1]=n;
    for(int i=2;i<=n;i++)   tv[i]=modDivide((tv[i-1]*(n-(i-1))),i,mod);
   // for(int i=0;i<=max2;i++)    cout<<i<<"=>"<<tv[i]<<endl;
    index=(int)log2(max2)+1;
    for(int i=29;i>=29-index;i--)
    {
        v=0;
        for(int j=0;j<n;j++)
            if(a[j][i]=='1')    v++;
        sb[29-i]=v;
    }
    //for(int i=0;i<n;i++)    cout<<i<<"=>"<<sb[i]<<endl;
    for(int i=0;i<=index;i++)
    {
        ans[1]=(ans[1]+(pow%mod*sb[i])%mod)%mod;
        ans[1]=ans[1]%mod;
        sv[1]=sb[i]%mod;
        nsv[1]=(tv[1]-sv[1]+mod)%mod;
       // cout<<sv[1]<<" "<<nsv[1]<<" "<<pow<<" "<<ans[1]<<endl;
        for(int j=2;j<=max2;j++)
        {
            num=((sv[1]*nsv[j-1])%mod+(sv[j-1]*nsv[1]))%mod;
            val=(((n-j+2)*sv[j-2])%mod);
            num=(num-val+mod)%mod;
            den=j%mod;
            sv[j]=modDivide(num,den,mod)%mod;
            ans[j]=(ans[j]+ ((pow%mod*sv[j])%mod))%mod;
            ans[j]=ans[j]%mod;
            nsv[j]=(tv[j]-sv[j]+mod)%mod;


          // cout<<j<<"=>"<<sv[j]<<" "<<nsv[j]<<" "<<pow<<" "<<ans[j]<<endl;
        }
        pow=(pow*2)%mod;
    }
    for(int i=2;i<=max2;i++)    ans[i]=(ans[i-1]+ans[i])%mod;
    for(int i=0;i<=n;i++)   cout<<i<<"=>"<<ans[i]<<endl;
    for(int i=0;i<q;i++)    cout<<ans[mv[i]]<<"\n";

}
