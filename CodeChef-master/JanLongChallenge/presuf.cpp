
#include<bits/stdc++.h>
using namespace std;

int t;

int n;

long int arr[1234567];



int main(){

   cin>>t;

   while(t--){

         cin>>n;

         for(int i=0;i<2*n;i++) cin>>arr[i];

         sort(arr,arr+2*n);



         if(arr[2*n-1]!=arr[2*n-2]) cout<<0<<endl;
         else{

           long int sum = arr[2*n-1];

           int i=0;

           int j=n-2;

           unsigned long long int ans=1;

           bool flag=false;

           while(i<=j){



                  if((arr[2*i]+arr[2*j]==sum && arr[2*i+1]+arr[2*j+1]==sum) && (arr[2*i]+arr[2*j+1]==sum && arr[2*i+1]+arr[2*j]==sum)  ) ans=ans*1;
                  else if((arr[2*i]+arr[2*j]==sum && arr[2*i+1]+arr[2*j+1]==sum) || (arr[2*i]+arr[2*j+1]==sum && arr[2*i+1]+arr[2*j]==sum)  ) {
                        if(i==j)    ans=ans*2;
                        else ans=ans*4;
                  }
                  else {

                    flag=true;
                    cout<<0<<endl;
                    break;

                  }


                 i++;

                 j--;




           }

           if(flag) continue;
           else cout<<ans%1000000007<<endl;






         }









   }


 return 0;


}
