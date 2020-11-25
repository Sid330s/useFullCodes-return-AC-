#include<iostream>
using namespace std;
int main(){

   int t;

   cin>>t;

   while(t--){

      int s , w1 , w2 , w3;

      cin>>s>>w1>>w2>>w3;

      if( w1+w2+w3 <= s) cout<<1;
      else if(w1+w2<= s) cout<<2;
      else if(w3+w2<= s) cout<<2;
      else cout<<3;

      cout<<endl;


   }


 return 0;


}
