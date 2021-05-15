#include<bits/stdc++.h>
using namespace std;
int ismajority(int arr[],int n,int x)
{
    int i,l;
    if(n%2==0)  l=n/2;
    else l=n/2+1;
    for (i = 0; i < l; i++)    if (arr[i] == x && arr[i+n/2] == x) return 1;
    return 0;
}

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
      int n,i;
      cin>>n;
      int arr[n];
      for(i=0;i<n;i++)  cin>>arr[i];
      int m=-1;
      for(i=0;i<n;i++){
        int x = arr[i];
				if (ismajority(arr, n, x))
								m = x;
      }
      int x = n/2;
      if (m!=-1) cout<<m<<endl;
      else  cout << "Does Not Exists" << endl;
	}
}
