#include<bits/stdc++.h>
using namespace std;
long long int t,c,d,x,ans,p;
set<pair<long long int,long long int>> st;
long long int checkSemiprime(long long int num,long long int g)
{
    int cnt = 0;
    long long int temp;
    long long int cnum=num;
    for (long long int i = 2; cnt < 2 && i * i <= num; ++i){
      if(num%i==0) temp=i;
      while (num % i == 0)
          num /= i, ++cnt;
    }

    if (num > 1) ++cnt;
    if(cnt != 2) return 0;
    if(cnum/temp==temp) return 1;
    st.insert(make_pair(cnum/temp*g, temp*g));
    st.insert(make_pair(temp*g,cnum/temp*g));
    return 2;
}
int main(){
  cin>>t;
  while(t--){
    cin>>c>>d>>x;
    ans=0;
    st.clear();
    for (long long int i=1; i<=sqrt(x); i++)
        if (x%i == 0)
        {
            if((x/i+d)%c==0) {
              p=(x/i+d)/c;
              ans+=checkSemiprime(p,i);
              st.insert(make_pair(p*i,1*i));
              st.insert(make_pair(1*i,p*i));
            }
            if(x/i!=i) if((i+d)%c==0) {
              p=(i+d)/c;
              ans+=checkSemiprime(p,x/i);
              st.insert(make_pair(p*(x/i),1*(x/i)));
              st.insert(make_pair(1*(x/i),p*(x/i)));
            }
        }
        // for(auto i:st){
        //   cout<<i.first<<" "<<i.second<<endl;
        // }
        cout<<st.size()<<endl;
  }

  return 0;
}
