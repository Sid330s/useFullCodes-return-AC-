#include<bits/stdc++.h>
using namespace std;

long long int arr[100005],n,d,m;
vector<int> v1,v2;


int main(){
  cin>>n>>d>>m;

  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<n;i++) {
  if(arr[i]<=m) v1.push_back(arr[i]);
  else v2.push_back(arr[i]);
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
}
  int i=0,k=0;
  long long int ans=0;
  while((!v2.empty())){
      arr[i]=v2.back();
      v2.pop_back();
      int it=d;
      i++;
      while((it--)&& k<v1.size()){
        arr[i]=v1[k];
        k++;
        i++;
      }
  }

  while(k<v1.size()){
    arr[i]=v1[k];
    i++;
    k++;
  }

for(int i=0;i<n;i++) cout<<arr[i]<<" : ";
cout<<endl;
  

cout<<ans<<endl;



   return 0;
}
