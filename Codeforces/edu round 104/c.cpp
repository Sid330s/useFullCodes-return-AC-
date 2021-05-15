#include<bits/stdc++.h>
using namespace std;
long long int t,n,k,ans;
int arr[100005];
int main(){

  cin>>t;

  while(t--){
    cin>>n;

    if(n%2==1){
      k=0;
      for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
          if(k%2==0){
            arr[k]=1;
          }
          else{
            arr[k]=-1;
          }
          k++;
        }
      }
    }
    else{
      k=0;
      int p=0;
      for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
          if(p%2==0){
            arr[k]=1;
          }
          else{
            arr[k]=-1;
          }
          k++;

        }
        p++;
      }
      k=0;
      int m=1;
      for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
          if(i==m){
            arr[k]=0;
            m=m+2;
          }
          k++;
        }
      }
    }

    for(int i=0;i<k;i++) cout<<arr[i]<<" ";
    cout<<endl;

 }
  return 0;
}
