#include<bits/stdc++.h>
using namespace std;
long long int n,k,t,arr[1000006];
bool flag;

int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n)
    queue<long long int> q;
    for(int i=0;i<n;i++) q.push(arr[i]);
    set<long long int> st;
    long long int ans=0;
    long long int cnt = 0;
    while(!q.empty()){
      if(st.find(q.front())==st.end()){
        cnt=0;
        long long int temp = q.front();
        q.pop();
        st.insert(temp);
        if(st.size()==k) ans++,st.clear();
      }
      else {
        long long int temp = q.front();
        q.pop();
        q.push(temp);
        cnt++;
      }
      if(cnt>q.size()) break;
    }
    cout<<ans<<endl;
  }
  return 0;
}
