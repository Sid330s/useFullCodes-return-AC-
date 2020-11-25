#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
long long  int num;

long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
{

    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    long long int x1, y1;
    long long int gcd = gcdExtended(b%a, a, &x1, &y1);


    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}





void modInverse(long long int a, long long int m)
{
    long long int x, y;
    long long int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {

        int res = (x%m + m) % m;
         cout<< ((num%MOD)*(res%MOD))%MOD<<endl;

    }
}

long long  int den;


long long int   n;
long long int   t;
string str;

long long int nclose[10000007];
long long int nopen[10000007];
long long int last_ans;

long long int pos[10000007];
long long int neg[10000007];



long long int max_neg;
long long int max_pos;

int main(){

cin>>t;
while(t--){

  cin>>n;


  cin>>str;

  num=0;
  den=(n*(n+1))/2;
  last_ans=0;
  nclose[0]=0;
  nopen[0]=0;

  max_neg=1;
  max_pos=0;
  pos[0]=0;

  for(int i=1;i<=n;i++){



    if(str[i-1] == '(') {
      nclose[i]=nclose[i-1];
      nopen[i]=nopen[i-1]+1;

      num=num+last_ans;

      if(nclose[i]-nopen[i]< 0){

             neg[nopen[i] - nclose[i]]=last_ans;
      }
      else{

      pos[nclose[i]-nopen[i]]=last_ans;

      }



    }
    else if(str[i-1]==')'){

      nclose[i]=nclose[i-1]+1;
      nopen[i]=nopen[i-1];


       last_ans=0;

       for(long long int j=i-1;j>=0;j--){

        // if(( nclose[i]-nopen[i] >=0 && vis_pos[abs(nclose[i]-nopen[i])]) || ( nclose[i]-nopen[i] <0 && vis_neg[abs(nclose[i]-nopen[i])]) )

        if( nclose[i] - nclose[j] > nopen[i] - nopen[j]   ) {

             last_ans = last_ans + ((nclose[i] - nclose[j]) - (nopen[i] - nopen[j]) +1)/2 ;
        }
        else if(  nclose[i] - nclose[j] == nopen[i] - nopen[j] ){

          if(nclose[i]-nopen[i]< 0){

                 last_ans=last_ans+neg[nopen[i] - nclose[i]];
          }
          else{

              last_ans=last_ans+pos[nclose[i]-nopen[i]];

          }

          break;




        }

       }

       num=num+last_ans;

       if(nclose[i]-nopen[i]< 0){

              neg[nopen[i] - nclose[i]]=last_ans;
       }
       else{

           pos[nclose[i]-nopen[i]]=last_ans;

       }






    }
    else{

      nclose[i]=nclose[i-1];
      nopen[i]=nopen[i-1];

      num=num+last_ans;

      if(nclose[i]-nopen[i]< 0){

             neg[nopen[i] - nclose[i]]=last_ans;
      }
      else{

          pos[nclose[i]-nopen[i]]=last_ans;

      }

      }


    }

    modInverse(den, MOD);


  }








return 0;

}
