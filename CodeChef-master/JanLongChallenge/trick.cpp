#include<bits/stdc++.h>
using namespace std;
int t;
int n , a , max_s , b , c , d , e , val;
int main(){



   cin>>t;

   while(t--){



      cin>>n;

      cin>>a;

      max_s=pow(10,n);


      cout<<max_s*2+a<<endl;
      fflush(stdout);

      cin>>b;

      cout<<max_s-b<<endl;
      fflush(stdout);

      cin>>d;


      cout<<max_s-d<<endl;
      fflush(stdout);



      cin>>val;


      if(val==-1) exit(0);




   }


 return 0;


}
