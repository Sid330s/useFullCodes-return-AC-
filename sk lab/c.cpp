#include<bits/stdc++.h>
using namespace std;
int n,ans,count1;
int arr[2002][2002];
unordered_map<int,int> ump9;
unordered_map<int,int> ump45;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    for(int i=-(n-1);i<=(n-1);i++) ump9[i]=0,ump45[i]=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
      ump9[i+j]+=arr[i][j];
      ump45[i-j]+=arr[i][j];
    }
    int max_odd=0;
    int max_even=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
      if((i+j)%2==0) max_even=max(max_even,ump9[i+j]+ump45[i-j]-arr[i][j]);
      else max_odd=max(max_odd,ump9[i+j]+ump45[i-j]-arr[i][j]);
    }
    cout<<max_odd+max_even<<endl;
    return 0;
}
