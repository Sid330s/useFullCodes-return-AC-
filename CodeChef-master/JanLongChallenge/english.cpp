
#include<bits/stdc++.h>
using namespace std;

int t;

int n;



string arr[123456];

int beuty[123456];


int commonPrefixUtil(string str1, string str2)
{
    int result=0;

    int n1 = str1.length(), n2 = str2.length();


    for (int i=0, j=0; i<=n1-1 && j<=n2-1; i++,j++)
    {
        if (str1[i] != str2[j])
            break;

        result++;
    }

    return result;
}



int main(){

   cin>>t;

   while(t--){



            cin>>n;

            for(int i=0;i<n;i++) cin>>arr[i];

            sort(arr,arr+n);


            if(n%2==0){
               arr[n]=arr[0];
               n++;
             }


            for(int i=0;i<n-1;i++)   beuty[i]=commonPrefixUtil(arr[i],arr[i+1]);

            int ans1=0;

            int ans2=0;


            for(int i=0;i<n;i++) {

              if(i%2==0) ans1=ans1+beuty[i]*beuty[i];
              else ans2=ans2+beuty[i]*beuty[i];
            }





            if(ans1>ans2) cout<<ans1<<endl;
            else cout<<ans2<<endl;


}


 return 0;


}
