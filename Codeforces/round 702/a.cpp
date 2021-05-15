#include<bits/stdc++.h>
using namespace std;
long long int t,ans,arr[100005],term,min_ele,max_ele,n;
double temp;
long long int nextPowerOf2(long long int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

int main(){

  cin>>t;

  while(t--){
    ans=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<=n-2;i++){
      min_ele=min(arr[i],arr[i+1]);
      max_ele=max(arr[i],arr[i+1]);
      temp=(double)max_ele/min_ele;
      term=ceil(temp);
      if(term==1) term=2;
      else term=nextPowerOf2(term);
      ans=ans+log2(term)-1;
    }
    cout<<ans<<endl;
 }
  return 0;
}
