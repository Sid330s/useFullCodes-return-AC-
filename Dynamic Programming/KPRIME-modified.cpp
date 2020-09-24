#include <bits/stdc++.h>
using namespace std;

int t,a,b,n=100004,k;

int prime[6][100005];

void SieveOfSiddharth()
{
  for (int p=0; p<=n; p++) prime[0][p]=1;
  prime[1][0]=0;
  prime[2][0]=0;
  prime[3][0]=0;
  prime[4][0]=0;
  prime[5][0]=0;

  prime[0][1]=0;

	for (int p=2; p*p<=n; p++) for (int i=p*p; i<=n; i += p) prime[0][i]=prime[0][p]+prime[0][i/p];



  for (int p=1; p<=n; p++) {
    if( prime[0][p] <=5 ){
      for(int i=1;i<=5;i++){
        if(i==prime[0][p]) prime[i][p]=prime[i][p-1]+1;
        else prime[i][p]=prime[i][p-1];
        cout<<"working"<<endl;
      }
    }
  }

}

int main()
{
  cin>>t;
  SieveOfSiddharth();

  while(t--){
    cin>>a>>b>>k;
    cout<<prime[k][b]-prime[k][a-1]<<endl;
  }
	return 0;
}
