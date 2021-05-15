#include <bits/stdc++.h>
using namespace std;
int t,n,arr[1000005];
void majority()
{
	sort(arr, arr+n);
	int count = 1, max_ele = -1, elem;
	bool flag = false;
	for(int i=1;i<n;i++)
	{
		if(arr[i-1]==arr[i]) count++;
		else count = 1;
		if(max_ele<count)
		{
			max_ele = count;
			elem = arr[i];
			if(max_ele>(n/2))
			{
				flag=true;
				break;
			}
		}
	}
	if (flag) cout << elem << endl;
	else cout << "Does Not Exists" << endl;
}
int main()
{
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    majority();
  }
	return 0;
}
