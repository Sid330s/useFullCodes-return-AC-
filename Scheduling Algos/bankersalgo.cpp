#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n, m;
  cout<<"Enter n (no of process) m (n of resources):"<<endl;
	cin>>n>>m;

	int allocation[n][m];
  int maximum[n][m];
  int available[m];
  cout<<"Enter allocation matrix:"<<endl;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>allocation[i][j];
  cout<<"Enter maximum allocation matrix:"<<endl;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>maximum[i][j];
  cout<<"Enter available resources:"<<endl;
  for(int i=0;i<m;i++) cin>>available[i];


	int finish[n], ans[n], ind = 0;
	for (int k = 0; k < n; k++) {
		finish[k] = 0;
	}

	int need[n][m];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) need[i][j] = maximum[i][j] - allocation[i][j];
	for (int k = 0; k < n; k++) 
		for (int i = 0; i < n; i++) {
			if (finish[i] == 0) {

				bool Possible = true;
				for (int j = 0; j < m; j++) {
					if (need[i][j] > available[j]){
						Possible = false;
						break;
					}
				}

				if (Possible) {
					ans[ind++] = i;
					for (int y = 0; y < m; y++) available[y] += allocation[i][y];
					finish[i] = 1;
				}
			}
		}


	cout << "Safe Sequence:" << endl;
	for (int i = 0; i < n ; i++)
		cout << " P" << ans[i] << " ->";

	return 0;
}
