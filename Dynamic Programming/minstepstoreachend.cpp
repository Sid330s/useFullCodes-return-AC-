#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }

	    int from=1;
	    int range=arr[0]+0;
	    int ans=1;
	    while(range<n-1){
	        int newrange=0;
	        for(int j=from;j<=range;j++){
	            newrange=max(arr[j]+j,newrange);
	        }
	        if(newrange==range){
	            ans=-1;
	            break;
	        }
	        ans++;
	        from=range+1;
	        range=newrange;
	    }
	    cout<<ans<<endl;

	}
	return 0;
}
