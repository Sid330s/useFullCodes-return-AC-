//-----------------//
// Siddharth Kale  //
//-----------------//
#include <bits/stdc++.h>
using namespace std ;

const int maxN = 1e5+5 ;
int p_count[maxN]={0};
int dp[5][maxN] ={0};

void solve()
{
	int a, b, k ;
	cin >> a >> b >> k;
	cout << dp[k-1][b]-dp[k-1][a-1] << '\n' ;
}

int main()
{
	for(int i=2; i<maxN; ++i)
	{
		if(p_count[i]!=0)
			continue;
		for(int j=i; j<maxN; j+=i)
			p_count[j]++ ;
	}

	for(int i=2; i<maxN; ++i)
	{
		if(p_count[i]>=1 && p_count[i]<=5)
		{
			dp[p_count[i]-1][i]++ ;
		}
		for(int j=0; j<5; ++j)
			dp[j][i]+=dp[j][i-1];
	}

	int t;
	cin >> t;
	while(t--)
		solve();
}
