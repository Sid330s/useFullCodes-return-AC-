#include<bits/stdc++.h>
using namespace std;
int fun(vector<vector<char>> mat) {
    int min_drop=0;
    int n=mat.size();
    int arr[n][n]={0};
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(mat[i][j]=='*') arr[i][j]=1;
    int min_val=n;
    for(int j=0;j<n;j++){
      int val=0;
      int i=n-1;
      while(i>=0 && arr[i][j]!=1) i--,val++;
      min_val=min(min_val,val);
    }
    for(int j=0;j<n;j++){
      int k=0;
      for(int i=0;i<n;i++){
        while(i<=k){
          if(arr[i][j]==1) k=i+min_val;
          arr[i][j]=1;
          i++;
        }
        if(arr[i][j]==1) k=i+min_val;
      }
    }
    int ans=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(mat[i][j]=='#' && arr[i][j]==1 ) ans++;
      }
    }
   return ans;
}

int main(){
  vector<vector<char>> vec;
  int n,m;
  char inp;
  cin>>n;
  for(int i=0;i<n;i++){
    vector<char> v;
    for(int j=0;j<n;j++){
      cin>>inp;
      v.push_back(inp);
    }
    vec.push_back(v);
  }
  int ans = fun(vec);
  cout<<ans<<endl;
  return 0;
}

/*

4
* * * .
* # * .
* # * *
. . # .


*/
