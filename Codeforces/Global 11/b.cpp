#include<bits/stdc++.h>
using namespace std;

long long int t,n,k;
string str1;
int main(){
  cin>>t;
  while (t--) {
    cin>>n>>k;
    cin>>str1;

    long long int first1=0;
    long long int i=0;

    while(i<n && str1[i]=='L') i++;
    first1=i;

    vector<long long int> vec;


    long long int ans = 1;
    if(first1==n) ans = 0;
    long long int count1=0;
    for(i=first1+1;i<n;i++) {
      if(str1[i]=='L'){
        count1++;
      }
      else {
        if(str1[i-1]=='W') ans = ans + 2;
        else ans++;
        if(count1) vec.push_back(count1);
        count1=0;
      }
    }

    sort(vec.begin(),vec.end());


    for(int i=0;i<vec.size();i++){
      k = k - vec[i];
      if(k<0) {
        k=k+vec[i];
        break;
      }
      ans=ans+2*vec[i]+1;
    }

    if(ans) ans=ans+2*(k);
    else ans=ans+2*k-1;

    if(ans<0) cout<<0<<endl;
    else if(ans>=2*n-1) cout<<2*n-1<<endl;
    else cout<<ans<<endl;

  }

  return 0;
}
