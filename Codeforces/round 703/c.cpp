#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int n,ans;
int query(int l,int r)
{

  int idx;
	if (1 <= l && l < r && r <= n)
	{
		printf("? %d %d\n",l,r);
		fflush(stdout);
		scanf("%d", &idx);
	}
  return idx;
}

int main()
{
	scanf("%d", &n);
	int L = 1, R = n;
  bool flag=true;
  int full;
	while (L <= R)
	{
    if(L==R) {
      ans=L;
      break;
    }
    if(flag) full = query(L,R);
    if(R-L==1){
      if(full==R) ans=L;
      else ans=R;
      break;
    }
		int m = L+(R-L)/2;
    int left = query(L,m);
		if(left==full){
      R=m-1;
      full=left;
      flag=false;
    }
    else{
      L=m+1;
      flag=true;
    }

	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}
