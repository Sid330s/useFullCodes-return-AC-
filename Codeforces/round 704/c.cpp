#include<bits/stdc++.h>
using namespace std;
int t,arr[200005],brr[200005],j,n,m,ans=0;
string str1;
string str2;
int main(){
    cin>>n>>m;
    cin>>str1;
    cin>>str2;
    j=0;
    for(int i=0;i<m;i++){
      while(str1[j]!=str2[i]) j++;
      arr[i]=j;
      j++;
    }
    j=0;
    for(int i=0;i<m;i++){
      while(str1[n-j-1]!=str2[m-i-1]) j++;
      brr[m-i-1]=n-j-1;
      j++;
    }
    for(int i=0;i<m-1;i++) ans=max(ans,brr[i+1]-arr[i]);
    cout<<ans<<endl;

  return 0;
}
