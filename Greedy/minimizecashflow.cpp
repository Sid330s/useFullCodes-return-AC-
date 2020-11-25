#include <bits/stdc++.h>
using namespace std;
bool sortbydesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.first>b.first;
}
int main() {
	int t,n,k,graph[1005][1005],min_money,bought;
  pair<int,int> creditor[1005],debitor[1005];
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    for(int i=0;i<n;i++) for(int j=0;j<n;i++)  cin>>graph[i][j];
      for(int i=0;i<n;i++) creditor[i].first=0,debitor[i].first=0;
      for(int i=0;i<n;i++) for(int j=0;j<n;i++)  {
        debitor[i].first+=graph[i][j];
        creditor[j].first+=graph[i][j];
        debitor[i].second=i;
        creditor[j].second=j;
      }
      for(int i=0;i<n;i++){
        if(debitor[i].first == creditor[i].first ) debitor[i].first=0,creditor[i].first=0;
        else if(debitor[i].first > creditor[i].first ) debitor[i].first-=creditor[i].first,creditor[i].first=0;
        else debitor[i].first=0,creditor[i].first-=debitor[i].first;
      }

      for(int i=0;i<n;i++) for(int j=0;j<n;i++) graph[i][j]=0;
      sort(creditor,creditor+n,sortbydesc);
      sort(debitor,debitor+n,sortbydesc);
      int i=0;
      int j=0;
      while(true){
        if(creditor[j].first > debitor[i].first) {
          graph[i][j]=debitor[i].first;
          i++;
        }
        else if(creditor[j].first < debitor[i].first){
            graph[i][j]=creditor[j].first;

        }

      }


	}
	return 0;
}
