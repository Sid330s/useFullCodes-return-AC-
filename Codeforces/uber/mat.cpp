#include<bits/stdc++.h>
using namespace std;
int duplicatePairsOnSegment(vector<int> arr, int k) {
    int ans=0;
    int n=arr.size();
    unordered_map<int,int> ump;
    int l=0;
    int r=0;
    int m=0;
    while(r<n){
      while(r<n && m<k){
        if(ump.find(arr[r])==ump.end()) ump[arr[r]]=1;
        else {
          ump[arr[r]]++;
          if(ump[arr[r]]%2==0) m++;
          if(m>=k) ans=ans+n-r;
        }
        r++;
      }
      if(r>=n) break;
      ump[arr[l-1]]--;
      if(ump[arr[l-1]]%2==1) m--;
      l++;
    }
    return ans;
}

int main(){
  vector<int> arr{ 1, 0, 1, 0, 1 };
  int k=2;
  cout<<duplicatePairsOnSegment(arr,k)<<endl;
  return 0;
}
