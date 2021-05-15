#include<bits/stdc++.h>
using namespace std;
long long int n,t,x;
long long int getSum(long long int n)
{
    long long int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    x=n;
    while(__gcd(x,getSum(x))<=1) x++;
    cout<<x<<endl;
 }
  return 0;
}
