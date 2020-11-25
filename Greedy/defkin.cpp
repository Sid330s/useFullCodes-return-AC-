#include <bits/stdc++.h>
using namespace std;
int t,w,h,n,x[100005],y[100005];
int main() {
	cin>>t;
  while(t--){
    cin>>w>>h>>n;
    for(int i=0;i<n;i++) {
      cin>>x[i];
      cin>>y[i];
    }
    n=n+2;
    x[n]=0;
    x[n+1]=w+1;
    y[n]=0;
    y[n+1]=h+1;
    sort(x,x+n);
    sort(y,y+n);
    int max_udx=0;
    int max_udy=0;
    for(int i=0;i<=n-2;i++) {
      max_udx=max(max_udx,x[i+1]-x[i]-1);
      max_udy=max(max_udy,y[i+1]-y[i]-1);
    }
    cout<<max_udx*max_udy<<endl;
  }
	return 0;
}
