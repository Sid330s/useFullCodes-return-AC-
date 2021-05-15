#include<bits/stdc++.h>
using namespace std;
int t,n,arr[200005],copy1[200005],m;

int removeDuplicates( int n)
{
	if (n==0 || n==1)
		return n;

	int j = 0;

  int i;
	for ( i=0; i < n-1; i++)
    if( arr[i] == arr[i+1]) i++ ;
    else if(i!=0 && arr[i]==arr[i-1]) ;
    else arr[j]=arr[i],j++;
    if(arr[n-1]!=arr[n-2]) arr[j]=arr[n-1],j++;
  	return j;
}

int main(){
  cin>>t;
  while(t--){
    cin>>n;

    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) copy1[i]=arr[i];
    sort(arr,arr+n);
    m=n;
    n = removeDuplicates(n);
    if(n==0) cout<<"-1"<<endl;
    else {
      for(int i=0;i<m;i++) if(arr[0]==copy1[i]) {
        cout<<i+1<<endl;
        break;
      }
    }
  }
  return 0;
}
