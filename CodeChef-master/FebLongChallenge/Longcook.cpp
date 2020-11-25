#include <bits/stdc++.h>
using namespace std;


int t,m0,m1;


bool checkYear(long int year)
{

  // Return true if year is a multiple
  // 0f 4 and not multiple of 100.
  // OR year is multiple of 400.
  return (((year % 4 == 0) && (year % 100 != 0)) ||
           (year % 400 == 0));
}

int dayofweek(int d, int m, long int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y / 4 - y / 100 +
             y / 400 + t[m - 1] + d) % 7;
}

long int countDivisibles(long int A, long int B, long int M)
{
	// Add 1 explicitly as A is divisible by M
	if (A % M == 0)
		return (B / M) - (A / M) + 1;

	// A is not divisible by M
	return (B / M) - (A / M);
}

long int year_range(long int y1, long int y2){

    long int count=0;

   if(y2-y1>200){



     while( y1 % 100!=1 ){

         if( (!checkYear(y1) && dayofweek(1, 2 , y1)==0) || (dayofweek(1, 2 , y1)==6) ) count++;
         y1++;

     }

     while( y2 % 100!=0 ){

         if( (!checkYear(y2) && dayofweek(1, 2 , y2)==0) || (dayofweek(1, 2 , y2)==6) ) count++;
         y2--;

     }


    count=count+countDivisibles(y1, y2, 400);
    count=count+((y2-y1+1)/100)*25;


   }

   else {

     for( int i = y1; i<=y2; i++)
     {
       int temp = dayofweek(1, 2 , i);
       if(temp == 6) count++;
       else if( !checkYear(i) && temp==0 ) count++;
     }

   }

  return count;


}





int main(){

 long int y0,y1;

 cin>>t;


 while(t--){




   cin>>m0>>y0;
   cin>>m1>>y1;


  if(m0>2) y0++;
  if(m1<2) y1--;



   cout<<year_range(y0,y1)<<endl;


 }





/*for(int j=1;j<100000;j=j+100){

  int count1=0;

  for(int i=j; i <= j+99; i++)
  {

    int temp=dayofweek(1, 2 , i);
    if(temp == 6) count1++;
    else if( !checkYear(i) && temp==0 ) count1++;

  }

  cout<<count1<<endl;
*/




return 0;



}
