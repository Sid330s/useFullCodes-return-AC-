#include<bits/stdc++.h>
using namespace std;
long long int t,n,ans;
string str1;
int main(){

  cin>>t;
  while(t--){
    cin>>n;
    cin>>str1;
    ans=0;
    vector<int> vec;
    bool flag=false;
    int i=0;
    while(i<n){
      if(str1[i]=='>' && str1[(i+1)%n]=='<'){
        vec.push_back((i+1)%n);
        break;
      }
      i++;
    }
    i++;
    for(int j=0;j<n;j++){
      if(str1[i]=='>' && str1[(i+1)%n]=='<'){
        if(flag) vec.push_back();
        flag=false;
        vec.push_back((i+1)%n);
      }
      else if(str1[i]=='i') flag=true;
    }


  }

  return 0;
}
