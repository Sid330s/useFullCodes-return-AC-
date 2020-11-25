#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,k,arr[10005],max_money,min_money,bought;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    for(int i=0;i<n;i++) cin>>arr[i];
	    sort(arr,arr+n);
	    max_money=0;
	    min_money=0;
	    bought=0;
	    for(int i=0;i<n;i++){
	        if(bought < n) {
	            bought+=k+1;
	            min_money+=arr[i];
	            max_money+=arr[n-i-1];
	        }

	    }

	    cout<<min_money<<" "<<max_money<<endl;;
	}
	return 0;
}
