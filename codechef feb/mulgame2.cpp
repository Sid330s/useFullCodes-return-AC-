#include <bits/stdc++.h>
using namespace std;
int t,n,q,m,l,r,L1,R1,L2,R2;
int arr[200005];
int qmin[200005];
int qmax[200005];
int main()
{
    cin>>t;
    while(t--){
      cin>>n>>q>>m;
      for(int i=0;i<n;i++) cin>>arr[i];
      for(int i=1;i<=m;i++) qmin[i]=0;
      for(int i=1;i<=m;i++) qmax[i]=0;
      map<pair<int, int>, int>  ump;
      for(int i=1;i<=q;i++) {
        cin>>l>>r;
        l--;
        r--;
        ump[{arr[l],arr[r]}]++;
      }
      for (auto q : ump) {
        L1=q.first.first;
        R1=min(m,q.first.first + q.first.second -1);
        if(L1<=R1){
            qmin[L1]++;
            qmax[R1]++;
        }
        while(L1 + q.first.first + q.first.second<=m){
          L2=L1 + q.first.first + q.first.second;
          R2=min(m,R1  + q.first.first + q.first.second);
          qmin[L2]+=q.second;
          qmax[R2]+=q.second;
          L1=L2;
          R1=R2;
         }
      }
      long long int P_in = qmin[0], max_P = qmin[0];
      for(int i=1;i<=m;i++){
        P_in=P_in+qmin[i]-qmax[i-1];
        max_P=max(max_P,P_in);
      }
      cout<<max_P<<endl;
    }

    return 0;
}
