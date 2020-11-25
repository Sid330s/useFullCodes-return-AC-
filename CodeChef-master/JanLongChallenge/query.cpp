#include<iostream>
using namespace std;

bool fw , mc , lw;

int main(){



      int n , q , l, r , countmax, countmin ;


      cin>>n>>q;


      long int arr[n+2];

      int arr1[n],arr2[n];

      for(int i=1;i<=n;i++) cin>>arr[i];




      arr[0]=1234567890;
      arr[n+1]=0;


      for(int i=1;i<=n;i++){

            if(arr[i]<arr[i-1])  arr1[i-1]=0;                                                 //wanted
            else if(arr[i]>arr[i-1])  arr1[i-1]=1;                                          //consitant
            else  arr1[i-1]=2;                                                                //unwanted



      }

      arr[n+1]=1234567890;
      arr[0]=0;


      for(int i=1;i<=n;i++){

            if(arr[i]>arr[i-1])  arr2[i-1]=0;                                                 //wanted
            else if(arr[i]<arr[i-1])  arr2[i-1]=1;                                          //consitant
            else  arr2[i-1]=2;                                                                 //unwanted

      }





      while(q--){

           cin>>l>>r;
           countmax=0;


                fw=false;
                mc=false;
                lw=false;
           for(int i=l-1;i<=r;i++){

                if(arr1[i]==0 && !fw) fw=true;
                else if(arr1[i]==1 && fw) mc=true;
                else if(arr1[i]==0 && fw && mc ){
                  lw=true;
                  if(fw && mc && lw ){


                    countmax++;

                    fw=true;
                    mc=false;
                    lw=false;


                  }
                       }
                else if(arr1[i]==2) {
                  fw=false;
                  mc=false;
                  lw=false;
                }
                else continue;
           }


           countmin=0;

           fw=false;
           mc=false;
           lw=false;


           for(int i=l-1;i<=r;i++){

                if(arr2[i]==0 && !fw) fw=true;
                else if(arr2[i]==1 && fw) mc=true;
                else if(arr2[i]==0 && fw && mc ){
                  lw=true;
                  if(fw && mc && lw ){


                    countmin++;

                    fw=true;
                    mc=false;
                    lw=false;


                  }
                       }
                else if(arr2[i]==2) {
                  fw=false;
                  mc=false;
                  lw=false;
                }
                else continue;
           }






         if(countmax==countmin) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;






      }



    return 0;


}
