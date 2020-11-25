#include<bits/stdc++.h>

using namespace std;

int t,n;

long int arr1[10000];

long int arr2[10000];

long int ans;
int main(){


   cin>>t;

   while(t--){


     cin>>n;

     for(int i=0;i<n;i++) cin>>arr1[i];
     for(int i=0;i<n;i++) cin>>arr2[i];

     sort(arr1,arr1+n);
     sort(arr2,arr2+n);

     ans=0;

     for(int i=0;i<n;i++) ans=ans+min(arr1[i],arr2[i]);

     cout<<ans<<endl;


   }


return 0;



}
