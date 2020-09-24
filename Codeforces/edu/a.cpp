#include<bits/stdc++.h>
using namespace std;

long long int n,t,arr[100005],ans;

int main(){

  cin>>t;

  while(t--){

     cin>>n;
     for(int i=0;i<n;i++) cin>>arr[i];
     if(arr[0]+arr[1] <= arr[n-1]) cout<<"1 2 "<<n<<endl;
     else cout<<"-1"<<endl;

  }


  return 0;

}
