#include<bits/stdc++.h>
using namespace std;
long long int arr[100005];
long long int brr[100005];
bool flag;

int main(){
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    maxa=0;
    for(int i=0;i<n;i++) maxa=max(arr[i],maxa);
    for(int i=0;i<n-1;i++) brr[i]=arr[i+1]-arr[i];
    n--;
    flag=true;
    for(int i=1;i<n;i++) if(brr[0]!=brr[i]) flag=false;
    if(flag) cout<<"0"<<endl;
    else{
      sort(brr,brr+n);
      result=0;
      for(int i=1;i<n;i++) result=gcd(result,abs(brr[i]-brr[i-1]));
      if(result<=maxa) cout<<"-1"<<endl;
      else cout<<result<<" "<<((brr[0]+result)%result)<<endl;
    }
  }
  return 0;
}
