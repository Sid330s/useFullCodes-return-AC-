#include<bits/stdc++.h>

using namespace std;

int t,n;
int time1;
char movie;
long int mat[4][4];


int ans[4];
int ans2[4];
long int profit;
long long int final;

long int max_profit;


int main(){


   cin>>t;

   final=0;

   while(t--){


     cin>>n;

     for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) mat[i][j]=0;


     while(n--){

        cin>>movie>>time1;

        mat[movie-65][(time1%12)/3]++;
     }


  


max_profit=-9999999;

for(int i=0;i<4;i++){

 ans[0]=mat[0][i];

  for(int j=0;j<4;j++){

   if(j==i) continue;
   ans[1]=mat[1][j];

   for(int k=0;k<4;k++){
    if(k==i || k==j) continue;
    ans[2]=mat[2][k];

    for(int m=0;m<4;m++){
     if( m==i || m==j || m==k ) continue;
     ans[3]=mat[3][m];


     for(int p=0;p<4;p++) ans2[p]=ans[p];
     sort(ans2,ans2+4,greater<int>());
     profit=0;
     for(int p=0;p<4;p++){
       profit=profit+ans2[p]*(100-25*p);
       if(ans2[p]==0) profit=profit-100;
     }

     if(profit > max_profit) max_profit=profit;
    }  }  }  }

cout<<max_profit<<endl;


final=final+max_profit;

   }

cout<<final<<endl;


return 0;



}
