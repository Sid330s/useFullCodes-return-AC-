#include<bits/stdc++.h>
using namespace std;
void fun1(int a){
  a++;
}
void fun2(int& a){
  a++;
}
void fun3(int* a){
  (*a)++;
}


int main(){
    char * s;
    s="Siddharth";
    printf("%d\n",s);
    cout<<s<<endl;
    s++;
    printf("%d\n",s);
    cout<<s<<endl;
    return 0;
}
