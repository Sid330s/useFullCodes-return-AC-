#include <bits/stdc++.h>
using namespace std;
long long int t,n,ans;
string arr[500];
int main()
{
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    if(arr[0][1]==arr[1][0] && arr[n-2][n-1]==arr[n-1][n-2]){
      if(arr[0][1]!=arr[n-2][n-1])  cout<<0<<endl;
      else {
        cout<<2<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<1<<endl;
      }
    }
    else if(arr[0][1]==arr[1][0] && arr[n-2][n-1]!=arr[n-1][n-2]){
      cout<<1<<endl;
      if(arr[0][1]==arr[n-2][n-1]) cout<<n-1<<" "<<n<<endl;
      else if(arr[0][1]==arr[n-1][n-2]) cout<<n<<" "<<n-1<<endl;

    }
    else if(arr[0][1]!=arr[1][0] && arr[n-2][n-1]==arr[n-1][n-2]){
      cout<<1<<endl;
      if(arr[0][1]==arr[n-2][n-1]) cout<<1<<" "<<2<<endl;
      else if(arr[1][0]==arr[n-2][n-1]) cout<<2<<" "<<1<<endl;
    }
    else{
      cout<<2<<endl;
      if(arr[0][1]==arr[n-2][n-1]){
        cout<<1<<" "<<2<<endl;
        cout<<n<<" "<<n-1<<endl;
      }
      else {
        cout<<2<<" "<<1<<endl;
        cout<<n-1<<" "<<n<<endl;
      }

    }
  }
	return 0;
}
