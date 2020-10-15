#include<bits/stdc++.h>
using namespace std;
string str1;
long long int t,ans,n;
int main(){

  cin>>t;

  while(t--){
    cin>>n;
    cin>>str1;
    ans=0;
    int i=0;
    while(i<n){
       char temp = str1[i];
       if(str1[i]==str1[i+1]) {
         ans++;
         while(str1[i]==temp) i++;
       }
       else{
         ans++;
         i=i+2;
       }

    }
    cout<<ans<<endl;

  }

  return 0;
}
