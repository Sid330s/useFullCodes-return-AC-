#include<bits/stdc++.h>
using namespace std;

long long int n,t,arr[26],ans;


/*

   1 1 - > hl

   1 -> T

  2 -> T

  3 -> t

  3 3 -> HL

  2 2 -> HL

  2 2 2 -> 1 2 2 -> 1 1 2 -> 0 1 2 ->
                          -> 1 1 1 -> HL

  2

  3 3 3->

  1 1 1-> T

  1 1 2 -> HL



   2 1 --> 0

   3 ---> 3






*/
int main(){

  cin>>t;

  while(t--){

     cin>>n;
     ans=0;
     for(int i=0;i<n;i++) cin>>arr[i];
     for(int i=0;i<n;i++) ans=ans^arr[i];
     cout<<"->"<<ans<<endl;

  }




  return 0;

}
