#include <iostream>
#include <string>
using namespace std;


int findLongestRepeatingSubSeq(string str,int n)
{

	int dp[n+1][n+1];

	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=n; j++)
		{
            if(i==0 || j==0) dp[i][j]=0;
			else if (str[i-1] == str[j-1] && i != j) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[n][n];
}

int main()
{
	int t,n;
	string str;
	cin>>t;
	while(t--){
	    cin>>n;
	    cin>>str;
	    cout<<findLongestRepeatingSubSeq(str,n)<<endl;
	}
	return 0;
}
