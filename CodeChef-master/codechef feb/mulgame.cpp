#include <bits/stdc++.h>
using namespace std;
int t,n,q,m,l,r,L1,R1,L2,R2,cnt;
int arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
      cin>>n>>q>>m;
      for(int i=0;i<n;i++) cin>>arr[i];
      int qmin[m+1]={0};
      int qmax[m+1]={0};
      cnt=0;
      for(int i=0;i<q;i++) {
        cin>>l>>r;
        l--;
        r--;
        if(l==r && arr[l]==1){
          cnt++;
          continue;
        }
        L1=arr[l];
        R1=min(m,arr[r]+arr[l]-1);
        if(L1<=R1){
            qmin[L1]++;
            qmax[R1]++;
        }
        while(R1+1+arr[l]<=m){
          L2=R1+1+arr[l];
          R2=min(m,R1+arr[l]+arr[r]);
          qmin[L2]++;
          qmax[R2]++;
          L1=L2;
          R1=R2;
         }
        }
      int P_in = qmin[0], max_P = qmin[0];
      for(int i=1;i<=m;i++){
        P_in=P_in+qmin[i]-qmax[i-1];
        if(i%2) P_in=P_in+cnt;
        max_P=max(max_P,P_in);
        if(i%2) P_in=P_in-cnt;
      }
      printf("%d\n",max_P);
    }
    return 0;
}
