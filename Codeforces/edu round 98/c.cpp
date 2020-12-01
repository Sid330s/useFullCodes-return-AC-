#include<bits/stdc++.h>
using namespace std;
long long int t,n;
string str;

long long int solve(string expr)
{
    long long int ans=0;
    long long int cnt1=0;
    long long int cnt2=0;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(')
        {
            cnt1++;
        }
        else if(expr[i] == '['){
            cnt2++;
        }
        else if(expr[i]==']') {
          if(cnt2>0){
            ans++;
            cnt2--;
          }
        }
        else if(expr[i]==')'){
          if(cnt1>0){
            ans++;
            cnt1--;
          }
        }
    }

    return ans;
}

int main(){

  cin>>t;

  while(t--){
    cin>>str;
    cout<<solve(str)<<endl;
  }

  return 0;
}
