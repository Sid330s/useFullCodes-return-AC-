#include <bits/stdc++.h>
using namespace std;
int t,n,arr[1000005];
void majority()
{
	int maxCount = 0;
	int index = -1;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) if (arr[i] == arr[j]) count++;
		if (count > maxCount) maxCount = count,index = i;
	}
	if (maxCount > n / 2) cout << arr[index] << endl;
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
