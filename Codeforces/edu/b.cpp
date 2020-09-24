#include<bits/stdc++.h>
using namespace std;

long long int n,t,ans;
string str1;
int main(){

  cin>>t;

  while(t--){

    cin>>str1;

    n=str1.length();

    vector<int> counts;
    ans=0;
    for(int i=0;i<n;i++){
      if(str1[i]=='1') ans++;
      else{
        if(ans) counts.push_back(ans);
        ans=0;
      }
    }

    if(ans) counts.push_back(ans);

    sort(counts.begin(),counts.end(),greater<int>());
    ans=0;
    for(int i=0;i<counts.size();i=i+2) ans=ans+counts[i];

    cout<<ans<<endl;


  }


  return 0;

}
