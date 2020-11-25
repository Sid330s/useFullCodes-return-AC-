#include<bits/stdc++.h>

using namespace std;

int t,n;
long int k;
long int arr1[10000];

long int ans;

int main(){


   cin>>t;

   while(t--){


     cin>>n>>k;

     for(int i=0;i<n;i++) cin>>arr1[i];

     ans=0;

     for(int i=0;i<n;i++) ans=ans+arr1[i];

     cout<<ans%k<<endl;


   }


return 0;



}
