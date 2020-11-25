#include <bits/stdc++.h>
using namespace std;
int t,n,k,graph[1005][1005]={0},ans[1005][1005]={0};

void minCashFlowRec(int amount[])
{
    cout<<"."<<endl;
    int mxCredit = *max_element(amount,amount+n), mxDebit = *min_element(amount,amount+n);
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0) return;
    int min_money = min(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min_money;
    amount[mxDebit] += min_money;
    ans[mxDebit][mxCredit]=min_money;
    minCashFlowRec(amount);
}

void minCashFlow()
{
    int amount[n] = {0};
    for (int p=0; p<n; p++)
       for (int i=0; i<n; i++)
          amount[p] += (graph[i][p] -  graph[p][i]);
    minCashFlowRec(amount);
}

int main() {
	cin>>t;
	while(t--){
	    cin>>n;
	    for(int i=0;i<n;i++) for(int j=0;j<n;j++)  cin>>graph[i][j];
      minCashFlow();
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)  cout<<ans[i][j]<<" ";
        cout<<endl;
      }
	}
	return 0;
}
