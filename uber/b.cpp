#include <bits/stdc++.h>
using namespace std;
struct node{
  long long val;
  int i;
  int j;
};
bool compare(node a, node b)
{
  return a.val < b.val;
}
int main(){

  int t,n,k,p;
  cin>>t;
  while(t--){
    cin>>n>>k>>p;
    long long  drr[n];
    long long  brr[k];
    for(int i=0;i<n;i++) cin>>drr[i];
    for(int j=0;j<k;j++) cin>>brr[j];

    vector<node> arr;
    for(int i=0;i<n;i++) for(int j=0;j<k;j++){
        node temp;
        if((drr[i]<=brr[j] && brr[j]<=p )||(p<=brr[j] && brr[j]<=drr[i])) temp.val=abs(drr[i]-p);
        else temp.val=abs(drr[i]+p-2*brr[j]);
        temp.i=i;
        temp.j=j;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end(),compare);
    set<int> sb;
    set<int> sd;
    // for(int i=0;i<arr.size();i++) cout<<arr[i].val<<" "<<arr[i].i<<" "<<arr[i].j<<endl;
    long long ans;
    for(int i=0;i<arr.size();i++){
        arr[i].i;
        arr[i].j;
        sd.insert(arr[i].i);
        sb.insert(arr[i].j);
        if(sb.size()==n  && sd.size()==n) ans=arr[i].val;
    }
    cout<<ans<<endl;

  }
  return 0;
}
