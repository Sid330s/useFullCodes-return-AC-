#include<bits/stdc++.h>
using namespace std;
int t,n,odd1,odd2,even1,even2;
string str1;

int main(){
  cin>>t;
  while(t--){
    cin>>n;
    cin>>str1;
    even1=0;
    odd1=0;
    even2=0;
    odd2=0;
    for(int i=0;i<n;i++) {
      if(i%2==0){
        if((str1[i]-48)%2==0) even1++;
        else odd1++;
      }
      else{
        if((str1[i]-48)%2==0) even2++;
        else odd2++;
      }
    }

  if(n%2==1){
    if(odd1) cout<<1<<endl;
    else cout<<2<<endl;
  }
  else{
    if(even2) cout<<2<<endl;
    else cout<<1<<endl;
  }

  }
  return 0;
}
