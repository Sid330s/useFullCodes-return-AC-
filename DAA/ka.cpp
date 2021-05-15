#include<bits/stdc++.h>
using namespace std;

long long int findLen(long long int a) {
    long long int len = 0;
    while (a) {
        len++;
        a /= 10;
    }
    return len;
}

long long int karatsuba_algorithm(long long int num1, long long int num2) {
    long long int len1 = findLen(num1);
    long long int len2= findLen(num2);
    long long int lenm = max(len1, len2);
    if (lenm==0) return 0;
    if (lenm==1) return num1*num2;
    long long int actLen = (lenm+1)/2;
    long long int fac = pow(10, actLen);
    long long int a, b, c, d;
    a = num1/fac;
    b = num1%fac;
    c = num2/fac;
    d = num2%fac;
    long long int a1 = karatsuba_algorithm(a, c);
    long long int a2 = karatsuba_algorithm(b, d);
    long long int a3 = karatsuba_algorithm(a+b, c+d)-a2-a1;
    return a1*pow(10, actLen*2) + a3*pow(10, actLen) + a2;
}

int main() {
  int t;
  cin>>t;
  while(t--){
    long long int num1, num2;
    cout<<"Enter Numbers : ";
    cin>>num1>>num2;
    cout<<"Answer: "<< karatsuba_algorithm(num1, num2)<<endl;

  }
  return 0;
}
