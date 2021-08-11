#include <bits/stdc++.h>
using namespace std;
long long int n,q,m,l,r,t;
long long int arr[1000005];
long long int qmin[1000005];
long long int qmax[1000005];
long long int findMaxP()
{

   sort(qmin, qmin+q);
   sort(qmax, qmax+q);
   long long int P_in = 0, max_P = 0;
   long long int i = 0, j = 0;
   while (i < q && j < q)
   {
      if (qmin[i] <= qmax[j])
      {
          P_in++;
          max_P = max(max_P,P_in);
          i++;
      }
      else
      {
          P_in--;
          j++;
      }
   }

   return max_P;
}
int main()
{
    cin>>t;
    while(t--){
      cin>>n>>q>>m;
      for(int i=0;i<n;i++) cin>>arr[i];
      for(int i=0;i<q;i++) {
        cin>>l>>r;
        l--;
        r--;
        qmin[i]=arr[l];
        qmax[i]=min(m,arr[r]+arr[l]-1);
      }
      cout<<findMaxP()<<endl;
    }

    return 0;
}
