#include<bits/stdc++.h>
using namespace std;
int t,n,m,arr[100005],brr[100005],crr[100005],prr[100005],ans,fix;
bool flag;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>m;
    vector<int> ump[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
		for(int i=1;i<=n;i++){
      cin>>brr[i];
      if(arr[i]!=brr[i]) ump[brr[i]].push_back(i);
    }
    for(int i=1;i<=m;i++) cin>>crr[i];
    flag=false;
    for(int i=1;i<=n;i++) if(brr[i]==crr[m]) fix=i,flag=true;
    if(!ump[crr[m]].empty()) fix=ump[crr[m]][0];
    if(flag){
              //cout<<"->"<<endl;
      for(int i=1;i<=m;i++){
        if(ump[crr[i]].empty()) ump[crr[i]].push_back(fix);
        prr[i]=ump[crr[i]].back();
        arr[prr[i]]=crr[i];
        ump[crr[i]].pop_back();
      }
      for(int i=1;i<=n;i++) if(arr[i]!=brr[i]) flag=false;
      if(flag){
        cout<<"YES"<<endl;
        for(int i=1;i<=m;i++) cout<<prr[i]<<" ";
        cout<<endl;
      }
      else cout<<"NO"<<endl;

    }
    else cout<<"NO"<<endl;

  }
  return 0;
}
