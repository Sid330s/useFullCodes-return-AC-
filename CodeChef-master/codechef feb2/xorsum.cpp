#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
long long int n,q,M,inp;
string arr[200005];
long long int k[30];
long long int dp[200005][3];
long long int ans[200005];
int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>inp;
        bitset<30> b(inp);
        arr[i]=b.to_string();
    }
    cout<<"Inp's:"<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
    for(int j=0;j<30;j++){
        k[j]=0;
        for(int i=0;i<n;i++){
          if(arr[i][j]=='1') k[j]++;
        }
    }
    cout<<"K's:"<<endl;
    for(int i=0;i<30;i++) cout<<k[i]<<" ";
    cout<<endl;
    long long int term=pow(2,29);
    for(int i=0;i<=n;i++) ans[i]=0;
    for(int j=0;j<30;j++){
      dp[0][1]=0;
      dp[0][0]=0;
      dp[0][2]=0;
      dp[1][0]=n-k[j];
      dp[1][1]=k[j];
      dp[1][2]=n;
      ans[1]=ans[1]+dp[1][1]*term;
      for(int m=2;m<=n;m++){
        dp[m][1]=((dp[m-1][1]*dp[1][0]+dp[m-1][0]*dp[1][1])-(n-(m-1)+1)*dp[m-2][1])/(m);
        dp[m][1]=dp[m][1];
        dp[m][2]=(dp[m-1][2]*(n-m+1))/m;
        dp[m][0]=dp[m][2]-dp[m][1];
        ans[m]=(ans[m]%MOD+(dp[m][1]*term)%MOD)%MOD;
      }
      cout<<"ne po to"<<endl;
      for(int m=1;m<=n;m++){
        cout<<dp[m][0]<<" "<<dp[m][1]<<" "<<dp[m][2]<<endl;
      }
      term=term/2;
    }
    for(int m=1;m<=n;m++){
        cout<<"m:"<<m<<" "<<ans[m]<<endl;
    }
    for(int m=2;m<=n;m++){
        ans[m]=ans[m]+ans[m-1];
    }
    cin>>q;
    while(q--){
      cin>>M;
      cout<<ans[M]<<endl;
    }

    return 0;
}



/*


4
1 3 5 2
2
1
2


   1 1 1 0

   k=3 n-k=1  ( 1 ... m )
   {

   1 - kC1    * 2
   2 - kC1*(n-k)C1 * 2^0
   3 - kC1*(n-k)C2 + kC3(n-k)C0
   4 - kC1*(n-k)C2 + kC3(n-k)C0

 }

  a + b + c + d
  ab + ac





*/
