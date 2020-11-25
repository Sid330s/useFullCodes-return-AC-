
#include<bits/stdc++.h>
using namespace std;

int t;

int n;



string arr[123456];

int beuty[12345][12345];


int factorial(int n)
{
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}




int minfix(string str1, string str2){

  int result=0;

  int n1 = str1.length(), n2 = str2.length();

  for (int i1=0, j1=0 , i2=n1-1, j2=n2-1; i1<=n1-1 && j1<=n2-1 && i2>=0 && j2>=0; i1++,j1++,i2--,j2--)
  {
      if ( (str1[i1] != str2[j1] ) || (str1[i2] != str2[j2] )  )
          break;

      result++;
  }

  return result;


}




int max_val;

int count1;


void rec(int i,int val,vector<bool> isMember){

  if(i>n-2) {

    if (val>max_val) max_val=val;

    count1++;

    return;

  }

  if(isMember[i])  {

         rec(i+1,val,isMember);

         return ;

  }


    for(int j=i+1;j<=n;j++){


        if(isMember[j]) continue;


        val=val+beuty[i][j]*beuty[i][j];

         isMember[i]=true;
         isMember[j]=true;





         rec(i+1,val,isMember);





  }



}




int main(){

   cin>>t;

   while(t--){



            cin>>n;

            for(int i=0;i<n;i++) cin>>arr[i];

            cout<<endl;

            for(int i=0;i<=n-2;i++){

                beuty[i][n]=0;


                for(int j=i+1;j<=n-1;j++){

                    beuty[i][j]=minfix(arr[i],arr[j]);
                    cout<<beuty[i][j]<<"  ";



                }

                cout<<beuty[i][n]<<"  ";

                cout<<endl;


            }






          int i=0;

          max_val=0;

          int val=0;

          vector<bool> isMember(n+1, false);



          count1=0;
          rec(i,val,isMember);


          cout << max_val <<"  "<<count1<< '\n';



}


 return 0;


}
