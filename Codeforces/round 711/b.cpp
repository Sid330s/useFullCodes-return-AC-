#include<bits/stdc++.h>
using namespace std;
long long int n,t,arr[100005],W,freq[21],temp1,temp2,ans,cnt,term,prev_temp;
bool notFreq(){
  for(int i=0;i<=20;i++) if(freq[i]>=0) return true;
  return false;
}
int main(){
  cin>>t;
  while(t--){
    cin>>n>>W;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<=20;i++) freq[i]=0;
    for(int i=0;i<n;i++) {
      int j=0;
      while(arr[i]){
        if(arr[i]%2) freq[j]++;
        arr[i]/=2;
        j++;
      }
    }
    temp1=W;
    ans=0;
    while(true){
      term=pow(2,20);
      for(int i=20;i>=0;i--) {
        if(freq[i]!=0){
            temp2=min(freq[i],temp1/term);
            temp1=temp1-temp2*term;
            freq[i]-=temp2;
        }
        term=term/2;
      }
      if(temp1==W) break;
      temp1=W;
      ans++;
    }
    cout<<ans<<endl;
 }
  return 0;
}
