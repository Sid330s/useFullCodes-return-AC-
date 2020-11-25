#include<bits/stdc++.h>
using namespace std;

int arr[200005];
int t,n,zero,
int main(){

  cin>>t;

  while(t--){

     cin>>n;

     for(int i=0;i<26;i++) ump[i]=0;
     int it=n;
     while(it--){
       cin>>str1;
       for(int i=0;i<str1.length();i++){
         ump[str1[i]-'a']++;
       }
     }

     bool ans=true;
     for(int i=0;i<26;i++) if(ump[i]%n!=0) ans=false;

     if(ans) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;

  }



  return 0;

}
