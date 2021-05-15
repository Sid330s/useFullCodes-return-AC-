#include<bits/stdc++.h>
using namespace std;
long long int t,n,m,ele,k;

long long int max_factorize(long long int n)
{
	long long int count = 0;
  long long int ans = 0;
	while (!(n % 2)) {
		n >>= 1;
		count++;
	}

	if (count > ans) {
      ans=count;
      ele=2;
  }

	for (long long i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			count++;
			n = n / i;
		}
    if (count > ans) {
        ans=count;
        ele=i;
    }
	}

	if (n > 2) if ( 1 > ans) {
      ans=1;
      ele=n;
  }

  return ans;
}


int main(){

  cin>>t;

  while(t--){
    cin>>n;
    m=n;
    k = max_factorize(n);
    cout<<k<<endl;
    if(k==1) cout<<m<<endl;
    else{

      for(int i=0;i<k-1;i++){
        cout<<ele<<" ";
        m=m/ele;
      }
      cout<<m<<endl;
    }
 }
  return 0;
}
