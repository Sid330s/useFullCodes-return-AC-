#include <bits/stdc++.h>
using namespace std;

int n,ans,idx,t;
int query(int x)
{
		printf("%d\n",x);
		fflush(stdout);
		scanf("%d", &idx);
    return idx;
}

int main()
{

  n=1000000;
  cin>>t;
  while(t--){
    for(int i=1;i<=1000;i++){
      ans = query(i*i);
      if(ans==1) break;
    }
  }

	return 0;
}
