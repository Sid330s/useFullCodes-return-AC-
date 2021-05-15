#include<bits/stdc++.h>
using namespace std;
long long int a[100005];
long long int lb[100005];
long long int ub[100005];

int findval(int n)
{
   sort(lb, lb+n);
   sort(ub, ub+n);

   long long int iv = 0,mv=0,val=lb[0];
   long long int i=0,j=0;

   while (i<n && j<n)
   {
      if (lb[i] <= ub[j])
      {
          iv++;
        if (iv > mv)
          {
              mv = iv;
              val = lb[i];
          }
          i++;        }
      else
      {
          iv--;
          j++;
      }
   }
    return mv;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,q,m,temp;
        cin>>n>>q>>m;
        for(int i=0;i<n;i++)    cin>>a[i];
        int x=0;
        temp=q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            lb[x]=a[l-1];
            ub[x]=min(m,a[r-1]+a[l-1]-1);
            x++;
        }
        int ans=findval(temp);
        cout<<ans<<"\n";
    }
    return 0;
}
