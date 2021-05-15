#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
            int n;
            cin>>n;
            long long  min=LLONG_MAX,max=0,ans=0;
            for(int i=0;i<n;i++)    cin>>a[i];
            for(int i=0;i<n;i++)
            {
                if(a[i]<min)    min=a[i];
                if(a[i]>max)    max=a[i];
            }
            for(int i=0;i<n;i++)
                if(ans<(abs(min-max)+abs(max-a[i])+abs(a[i]-min)))  ans=(abs(min-max)+abs(max-a[i])+abs(a[i]-min));
            cout<<ans<<"\n";
    }
   return 0;
}
