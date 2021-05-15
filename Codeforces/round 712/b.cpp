#include<bits/stdc++.h>
using namespace std;
long long int t,n,cnt0,cnt1;
string str1,str2;
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    cin>>str1>>str2;
    vector<long long int> ans0;
    vector<long long int> ans1;
    bool flag = true;
    bool flag2 = true;
    for(int i=0;i<n;){
      cnt0=0;
      cnt1=0;
      if(str1[i]!=str2[i]){
        while(i<n && str1[i]!=str2[i]) {
          if(str1[i]=='0') cnt0++;
          else cnt1++;
          i++;
        }
        flag=false;
      }
      else{
        while(i<n && str1[i]==str2[i]) {
          if(str1[i]=='0') cnt0++;
          else cnt1++;
          i++;
        }
        flag=true;
      }
      ans0.push_back(cnt0);
      ans1.push_back(cnt1);
    }

    if(flag) ans1.pop_back(),ans0.pop_back();
    for(int i=0;i<ans0.size();i++) if(ans0[i]!=ans1[i]) flag2=false;
    if(flag2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
 }
  return 0;
}
