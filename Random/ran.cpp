
#include<bits/stdc++.h>
using namespace std;
int random(int l,int r){
  return l + (rand()%(r-l+1));
}
int main()
{
  while(true) cout<<random(3,8)<<endl;;

 return 0;
}
