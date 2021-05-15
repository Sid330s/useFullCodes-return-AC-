#include<bits/stdc++.h>
using namespace std;
long long int t,n,A,B,arr[100005],brr[100005],m;
int main(){
  cin>>t;
  while(t--){
    cin>>A>>B>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>brr[i];
    long long int totalbrr=0;
    long long int times=0;
    for(int i=0;i<n;i++) {
      long long int temp=brr[i];
      brr[i]=brr[i]-A*(brr[i]/A);
      B=B-arr[i]*(temp/A);
      if(brr[i]==0) arr[i]=0;
      if(B<=0 && temp>0) times++;
      totalbrr=totalbrr+brr[i];
    }
    long long int max_ele=*max_element(arr,arr+n);
    long long int total=0;
    //cout<<"max_ele:"<<max_ele<<endl;
    for(int i=0;i<n;i++) total+=arr[i];
    if(times<=1){
      if(totalbrr==0) cout<<"YES"<<endl;
      else if(total<=B && B>0) cout<<"YES"<<endl;
      else if(total-max_ele<B && B>0) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
  }
  return 0;
}
