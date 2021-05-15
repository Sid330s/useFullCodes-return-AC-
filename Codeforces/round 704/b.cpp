#include<bits/stdc++.h>
using namespace std;
long long int t,arr[100005],brr[100005],j,k,n;
bool visited[100005];
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) visited[i]=false;
    stack<long long int> st;
    j=0;
    k=n;
    for(int i=n-1;i>=0;i--){
      st.push(arr[i]);
      visited[arr[i]]=true;
      if(arr[i]==k){
        while(!st.empty()){
          brr[j]=st.top();
          st.pop();
          j++;
        }
        while(visited[k]) k--;
      }
    }
    for(int i=0;i<n;i++) cout<<brr[i]<<" ";
    cout<<endl;
 }
  return 0;
}
