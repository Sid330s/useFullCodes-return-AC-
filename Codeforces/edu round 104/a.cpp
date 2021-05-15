#include<bits/stdc++.h>
using namespace std;
long long int t,n,arr[100005],ans,min_ele;
int main(){

    cin>>t;
    while(t--){
      cin>>n;
      for(int i=0;i<n;i++) cin>>arr[i];
      min_ele=*min_element(arr,arr+n);
      long long int ans=0;
      for(int i=0;i<n;i++) if(min_ele==arr[i]) ans++;
      cout<<n-ans<<endl;
    }


  return 0;
}
