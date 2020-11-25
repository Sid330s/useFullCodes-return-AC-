//BigO(1) code using geometery

#include<iostream>
#include<cmath>
using namespace std;
int min(int a,int b){
    if(a<b) return a;
    else return b;
}
int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int a,b;
    cin>>b;
    cin>>a;
    int total=2*n-2+min(n-a,n-b)+min(n-b,a-1)+min(a-1,b-1)+min(b-1,n-a);
    int arr[8];
    for(int i=0;i<8;i++) arr[i]=0;
    while(k--){
        int x,y;
        cin>>y;
        cin>>x;
        if(x==a || y==b ) {
            if(x-a>0 && y-b==0) if (n-a-abs(x-a)+1>arr[0]) arr[0]=n-a-abs(x-a)+1;
            if(x-a==0 && y-b>0) if (n-b-abs(y-b)+1>arr[1]) arr[1]=n-b-abs(y-b)+1;
            if(x-a<0 && y-b==0) if (a-1-abs(x-a)+1>arr[2]) arr[2]=a-1-abs(x-a)+1;
            if(x-a==0 && y-b<0) if (b-1-abs(y-b)+1>arr[3]) arr[3]=b-1-abs(y-b)+1;



        }
        if(abs(x-a)==abs(y-b)){
            if(x-a>0 && y-b>0)  if (min(n-a,n-b)-abs(y-b)+1>arr[4]) arr[4]=min(n-a,n-b)-abs(y-b)+1;
            if(x-a<0 && y-b>0)  if (min(n-b,a-1)-abs(y-b)+1>arr[5]) arr[5]=min(n-b,a-1)-abs(y-b)+1;
            if(x-a<0 && y-b<0)  if (min(a-1,b-1)-abs(y-b)+1>arr[6]) arr[6]=min(b-1,a-1)-abs(y-b)+1;
            if(x-a>0 && y-b<0)  if (min(b-1,n-a)-abs(y-b)+1>arr[7]) arr[7]=min(b-1,n-a)-abs(y-b)+1;

        }
    }
     int sum2=0;
     for(int i=0;i<8;i++) sum2=sum2+arr[i];
     cout<<total-sum2;
     return 0;
}
