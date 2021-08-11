#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> fun(vector<vector<char>> mat) {
    int min_drop=0;
    int n=mat.size();
    int m=mat[0].size();

    for(int i=n-1;i>=0;i--){
      int c=m-1;
      for(int j=m-1;j>=0;j--){
        if(mat[i][j]=='*') c=j-1;
        else if(mat[i][j]=='#'){
          mat[i][j]='.';
          mat[i][c]='#';
          c=c-1;
        }
      }
    }

    for(int j=m-1;j>=0;j--){
      int r=n-1;
      for(int i=n-1;i>=0;i--){
        if(mat[i][j]=='*') r=i-1;
        else if(mat[i][j]=='#'){
          mat[i][j]='.';
          mat[r][j]='#';
          r=r-1;
        }
      }
    }

    return mat;

}

int main(){
  vector<vector<char>> vec;
  int n,m;
  char inp;
  cin>>n>>m;
  cout<<endl;
  for(int i=0;i<n;i++){
    vector<char> v;
    for(int j=0;j<m;j++){
      cin>>inp;
      v.push_back(inp);
    }
    vec.push_back(v);
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cout<<vec[i][j]<<" ";
    cout<<endl;
  }
  vec=fun(vec);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cout<<vec[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
/*

4 5
. # . . .
. . . . .
# . # # .
# . * . #


*/
