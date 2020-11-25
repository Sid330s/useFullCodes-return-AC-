#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n,k,arr[1000],dp[1000];
	cin>>t;
	while(t--){
	    cin>>n;
	    for(int i=0;i<n;i++) cin>>arr[i];
	    cin>>k;
	    for(int i=0;i<n;i++) dp[i]=0;
	    sort(arr,arr+n);

	    if(arr[1]-arr[0]<k) dp[1]=arr[1]+arr[0];
	    for(int i=2;i<n;i++){
	        if(arr[i]-arr[i-1]<k) {
	            dp[i]=arr[i]+arr[i-1]+dp[i-2];
	        }
	        else dp[i]=dp[i-1];
	    }

	    cout<<dp[n-1]<<endl;
	}
	return 0;
}
