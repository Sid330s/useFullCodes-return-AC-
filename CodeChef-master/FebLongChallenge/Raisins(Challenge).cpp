#include<bits/stdc++.h>
using namespace std;

int arr1[1000006];
int arr2[1000006];
int mat[1024][1024];

long int w,h,r,n,m;

vector<pair<int,int>> q;

void moveRgt(long int x ){

  int temp=mat[n-1][x];
  for(int i=n-1;i>=1;i--){
       mat[i][x]=mat[i-1][x];
  }
   mat[0][x]=temp;

}

void moveUpd(long int x ){

  int temp=mat[x][m-1];
  for(int i=m-1;i>=1;i--){
       mat[x][i]=mat[x][i-1];
  }
  mat[x][0]=temp;



}


int main(){
    
    cin>>w>>h>>r;

     for(int i=0;i<r;i++) cin>>arr1[i]>>arr2[i];
    

    n=18;
    m=18;

    cout<<n<<" "<<m<<" ";

    for( int i=0;i<n;i++) for(int j=0;j<m;j++) mat[i][j]=0;

    for(int i=0;i<r;i++) mat[arr1[i]/(w/n)][arr2[i]/(h/m)]=1;
    
    long int i=n;
    long int j=m;

     while( i>=1 && j >=1 ){

           for(long int k=0;k<(n+m-1);k++){
             if(mat[i-1][j-1]==1){
               moveRgt(j-1);
               q.push_back( make_pair(1,j));
             }
             else{
               moveUpd(i-1);
               q.push_back( make_pair(2,i));

             }


           }


           i--;
           j--;
     }

    i=1;

     while(i<=n){
       j=0;
       while(j<m && mat[i-1][m-1]==1){
            moveUpd(i-1);
            q.push_back( make_pair(2,i));
            j++;
       }
       i++;

     }







  cout<<q.size()<<endl;

  for(int i=0;i<q.size();i++){

    cout<<q[i].first<<" "<<q[i].second<<endl;

  }


  return 0;
}
