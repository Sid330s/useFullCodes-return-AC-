#include<bits/stdc++.h>
using namespace std;
long long int t,n,ans,count1,count2;
string str1;
int main(){

  cin>>t;
  while(t--){
    cin>>str1;
    n=str1.length();
    if(n%2==1) str1=str1+'A';
    ans=0;
    count1=0;
    count2=0;
    for(int i=0;i<str1.length();i=i+2){
      if(str1[i]=='A' && str1[(i+1)%n]=='A') ans=ans+0,count1=count1+2;
      else if(str1[i]=='A' && str1[(i+1)]=='B') ans=ans+1;
      else if(str1[i]=='B' && str1[(i+1)]=='A' && count1) ans=ans+1;
      else if(str1[i]=='B' && str1[(i+1)]=='A' && count2) ans=ans+1,count1=count1+1;
      else if(str1[i]=='B' && str1[(i+1)]=='A') count2++,count1++;
      else if(str1[i]=='B' && str1[(i+1)]=='B'&& count1>=2) ans=ans+2, count1=count1-2;
      else if(str1[i]=='B' && str1[(i+1)]=='B'&& count1==1 && count2>=1) ans=ans+2,count2--,count1--;
      else if(str1[i]=='B' && str1[(i+1)]=='B') ans=ans+1;
    }

    cout<<n-2*ans<<endl;
  }

  return 0;
}
