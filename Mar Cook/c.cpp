#include<bits/stdc++.h>
using namespace std;
int arr[200005],min_val,t,n,k;
int brr[200005];
long long int ans;
bool flag;

int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    brr[0]=0;
    for(int i=1;i<=n;i++) brr[i]=brr[i-1]+arr[i];
    min_val=n;
    for(int i=k;i<=n;i++) min_val=min(brr[i]-brr[i-k],min_val);
    ans=min_val*(min_val+1)/2;
    ans+=brr[n]-min_val;
    cout<<ans<<endl;
  }
  return 0;
}
