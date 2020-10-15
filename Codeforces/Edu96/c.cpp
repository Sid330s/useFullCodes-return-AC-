#include<bits/stdc++.h>
using namespace std;
long long int t,n,j,k;
int main(){

  cin>>t;

  while(t--){
    cin>>n;
    j=n;
    k=n-1;
    vector<int> vec;
    for(int i=0;i< n-1;i++){
       vec.push_back(j);
       vec.push_back(k-i);
       j=(j+k-i+1)/2;
    }
    cout<<j<<endl;
    for(int i=0;i< 2*n-2;i=i+2){
      cout<<vec[i]<<" "<<vec[i+1]<<endl;
    }

  }

  return 0;
}
