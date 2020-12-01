#include<bits/stdc++.h>
using namespace std;
string X,Y;
long long int n,m;

int solve()
{


    int LCSuff[m+1][n+1];
    int result = 0;

    {
        for (int j=0; j<=n; j++)
        {

            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    int x,y;
    for(int i=0;i<=m;i++){
      for(int j=0;j<=n;j++){
          if(LCSuff[i][j]==result){
            x=i;
            y=j;
            break;
          }
      }
    }

    

    return result;
}

int main(){

  cin>>t;

  while(t--){
    cin>>m>>n;
    cin>>X;
    cin>>Y;
    cout<<solve()<<endl;

 }
  return 0;
}
