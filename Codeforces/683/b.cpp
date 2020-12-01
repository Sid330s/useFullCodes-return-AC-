#include<bits/stdc++.h>
using namespace std;
int arr[100][100],n,m,numofneg,ans,min_val,t;

int main(){
  cin>>t;
  while(t--){
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    ans=0;
    numofneg=0;
    min_val=10000;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
      if(arr[i][j]<0) numofneg++;
      ans=ans+abs(arr[i][j]);
      min_val=min(min_val,abs(arr[i][j]));
    }
   if(numofneg%2==1) ans=ans-2*min_val;

   cout<<ans<<endl;
  }
  return 0;
}
