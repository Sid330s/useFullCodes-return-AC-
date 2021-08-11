#include<bits/stdc++.h>
using namespace std;
string s;
long long int n,k,t;
long long int arr[100005],mex,max1;
bool flag;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    set<long long int> st;
    for(int i=0;i<n;i++) st.insert(arr[i]);

    for(long long int ele=0;ele<=n;ele++){
      if(st.find(ele)==st.end()){
        mex=ele;
        break;
      }
    }

    max1=*max_element(arr,arr+n);

    if(k==0) cout<<st.size()<<endl;
    else if(mex>max1){
      cout<<st.size()+k<<endl;
    }
    else if(mex<max1){
      st.insert(ceil((double)(max1+mex)/2));
      cout<<st.size()<<endl;
    }

}
 return 0;
}
