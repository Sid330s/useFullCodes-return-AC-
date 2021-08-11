#include<bits/stdc++.h>
using namespace std;
long long int t,n;
long long int arr[100005];
int main()
{
  cin>>t;
  while(t--)
  {
      cin>>n;
      for(int i=0;i<n;i++)  cin>>arr[i];
      long long int max_ele=*max_element(arr,arr+n);
      long long int min_ele=*min_element(arr,arr+n);
      cout<<2*abs(max_ele-min_ele)<<endl;
  }
   return 0;
}
