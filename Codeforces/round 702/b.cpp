#include<bits/stdc++.h>
using namespace std;
long long int t,ans,arr[100005],term,n;
long long int freq[3];

int main(){

  cin>>t;

  while(t--){
    ans=0;
    cin>>n;
    freq[0]=0;
    freq[1]=0;
    freq[2]=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      freq[arr[i]%3]++;
    }
    n=n/3;
    if(freq[0]>=n){
      ans=ans+(freq[0]-n);
      freq[1]=freq[1]+(freq[0]-n);
      if(freq[1]>=n) ans=ans+(freq[1]-n);
      else ans=ans+abs(n-freq[2])*2;
    }
    else if(freq[1]>=n){
      ans=ans+(freq[1]-n);
      freq[2]=freq[2]+(freq[1]-n);
      if(freq[2]>=n) ans=ans+(freq[2]-n);
      else ans=ans+abs(n-freq[0])*2;
    }
    else if(freq[2]>=n){
      ans=ans+(freq[2]-n);
      freq[0]=freq[0]+(freq[2]-n);
      if(freq[0]>=n) ans=ans+(freq[0]-n);
      else ans=ans+abs(n-freq[1])*2;
    }

    cout<<ans<<endl;
 }
  return 0;
}
