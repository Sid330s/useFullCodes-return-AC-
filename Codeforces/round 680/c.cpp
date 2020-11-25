#include <bits/stdc++.h>
using namespace std;

long long int  getTerm(long long int p,long long int q)
{

  long long int term=p;

  while(term){
    if(term%q!=0) return term;
    term=term/q;
  }

  return term;

}

long long int  getPow(long long int p,long long int q)
{
	long long int ans=0;
  long long int term=p;
  while(term){
    if(term%q!=0) return ans;
    term=term/q;
    ans++;
  }

  return ans;

}


long long int final(long long int p,long long int q)
{
  long long int term=getTerm(p,q);
  long long int x=getPow(p,q);
  if(x==0) return p;
  long long int ans=1;
	for (int i=1; i<=sqrt(q); i++)
	{
		if (q%i == 0)
		{
        long long int fact1=pow(i,x);
        long long int fact2=pow((q/i),x);

			  if((term*fact1)%q!=0 && p%(term*fact1)==0) ans=max(ans,(term*fact1));
        if((term*fact2)%q!=0 && p%(term*fact2)==0) ans=max(ans,(term*fact2));
		}
	}
  return ans;
}


long long int t,p,q;
int main()
{
	cin>>t;
  while(t--){
    cin>>p>>q;
    cout<<final(p,q)<<endl;
  }
	return 0;
}
