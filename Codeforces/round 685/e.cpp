#include<bits/stdc++.h>
using namespace std;
long long int n,xor12,and12,xor23,and23,and13,a,b,c;
int main(){
  cin>>n;
  cout<<"XOR 1 2"<<endl;
  cin>>xor12;
  cout<<"AND 1 2"<<endl;
  cin>>and12;
  cout<<"XOR 2 3"<<endl;
  cin>>xor23;
  cout<<"AND 2 3"<<endl;
  cin>>and23;
  cout<<"AND 1 3"<<endl;
  cin>>and13;
  a=0;
  b=0;
  c=0;

  while(xor12||and12||xor23||and23||and13){
    if(xor12%2==0 && xor23%2==0){
      a=a+and12%2;
      b=b+and23%2;
      c=c+and23%2;
    }
    else if(xor12%2==1 && xor23%2==0){
      a=a+and12%2;
      b=b+and23%2;
      c=c+and23%2;
    }
    else if(xor12%2==0 && xor23%2==1){

    }
    else {

    }
  }

  return 0;
}
