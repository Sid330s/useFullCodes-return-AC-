#include<bits/stdc++.h>
using namespace std;
long long int t,x;
int cube_root;
bool perfectCube(int N)
{

    cube_root = round(cbrt(N));
    if (cube_root * cube_root * cube_root == N) return true;
    else   return false;

}
bool isSumCube()
{
    for(int i=1;i*i*i<x;i++){
      i+cube_root(x-i*i*i)
      if(perfectCube(x-i*i*i)) return true;
    }
    return false;
}
bool isSumCube2()
{
    int a = cbrt(x);
    int b = a - 1;
    if(a==0 || b==0) return false;
    return ((a * a * a + b * b * b) == x);
}
int main(){
  cin>>t;
  while(t--){
    cin>>x;
    if(isSumCube2()) cout<<"YES"<<endl;
    else if(isSumCube()) cout<<"YES"<<endl;
    else  cout<<"NO"<<endl;
 }
  return 0;
}
