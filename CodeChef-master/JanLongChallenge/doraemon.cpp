
#include<bits/stdc++.h>
using namespace std;

int t;

int n,m;

int len;

int arr[100][100];



int main(){

   cin>>t;

   while(t--){



            cin>>n>>m;

            int count=n*m;



            for(int i=0;i<n;i++)  for(int j=0;j<m;j++) cin>>arr[i][j];

          for(int i=0;i<n;i++)  {




                     for(int j=0;j<m;j++){


                      len=1;
                      while( i+len < n &&  i-len >=0 && j+len < m && j-len>=0 && i<n && j<m){



                                   if( arr[i+len][j]!=arr[i-len][j] || arr[i][j+len]!=arr[i][j-len] ) break;

                                   else count++;

                                   len++;

                      }

          }

}

                    cout<<count<<endl;





   }


 return 0;


}
