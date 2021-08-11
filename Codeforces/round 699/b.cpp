#include<bits/stdc++.h>
using namespace std;
long long int t,n,k,arr[200],ans;
bool flag;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
		flag=false;
    for(int m=0;m<k;m++){
			for(int i=0;i<n-1;i++){
				if(arr[i]<arr[i+1]){
					arr[i]++;
					ans=i;
					break;
				}
				else if(i+1==n-1) {
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag || n==1) cout<<"-1"<<endl;
		else cout<<ans+1<<endl;
  }
  return 0;
}
