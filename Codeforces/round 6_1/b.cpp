#include<bits/stdc++.h>
using namespace std;

long long int arr[100005],n,sum1,ans,ans2;

int main(){

  cin>>n;
  sum1=0;
  for(int i=0;i<n;i++)  cin>>arr[i];
  for(int i=0;i<n;i++)  sum1=sum1+arr[i];

  sort(arr,arr+n);
  long long int c=1;
  ans2=sum1;
  while(pow(c,n-1)<=2*sum1){
    ans=0;
    for(int i=0;i<n;i++) ans=ans+abs(arr[i]-pow(c,i));
    ans2=min(ans,ans2);
    c++;
  }

  cout<<ans2<<endl;
  return 0;
}
