#include<bits/stdc++.h>
using namespace std;

long long int arr[200005];
long long int n,w,t,lb,idx,sum1,m;
bool flag,isans;
bool comparator(pair<long long int,long long int> a,pair<long long int,long long int> b){
  return (a.first > b.first );
}
int main(){
  cin>>t;
  while(t--){
    cin>>n>>w;
    for(int i=0;i<n;i++) cin>>arr[i];
    lb=(w+1)/2;
    //cout<<"--"<<lb<<endl;
    vector<pair<long long int,long long int>> vec;
    vector<long long int> ans;
    flag=false;
    for(int i=0;i<n;i++){
      if(lb<=arr[i] && arr[i]<=w) {
        flag=true;
        idx=i+1;
        break;
      }
      else if(arr[i] < lb){
        vec.push_back(make_pair(arr[i],i+1));
      }
    }

    if(flag){
      cout<<"1"<<endl;
      cout<<idx<<endl;
    }
    else {
      isans=false;
      sort(vec.begin(),vec.end(),comparator);
      sum1=0;
      for(int i=0;i<vec.size();i++){
          sum1=sum1+vec[i].first;
          ans.push_back(vec[i].second);
          if(sum1>=lb && sum1<=w) {
            isans=true;
            break;
          }
      }

      if(isans) {
        m=ans.size();
        cout<<m<<endl;
        for(int i=0;i<m;i++) cout<<ans[i]<<" ";
        cout<<endl;
      }
      else cout<<"-1"<<endl;


    }

  }
  return 0;
}
