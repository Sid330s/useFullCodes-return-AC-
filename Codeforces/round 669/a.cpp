#include<bits/stdc++.h>
using namespace std;
int t,n,arr[1003],odd,even,ans;
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    odd=0;
    even=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
      if(i%2==1) even=even+arr[i];
      else odd=odd+arr[i];
    }
    ans=n;
    if(even > odd) for(int i=0;i<n;i=i+2) if(arr[i]==0 && arr[i+1]==1) arr[i]=2, arr[i+1]=2,ans=ans-2;
    if(even < odd) for(int i=0;i<n;i=i+2) if(arr[i]==1 && arr[i+1]==0) arr[i]=2, arr[i+1]=2,ans=ans-2;

    if (ans==0){
      cout<<1<<endl;
      cout<<0<<endl;
    }
    else{
      cout<<ans<<endl;
      for(int i=0;i<n;i++) if(arr[i]!=2) cout<<arr[i]<<" ";
      cout<<endl;
    }

  }
  return 0;
}
