#include<iostream>
using namespace std;

int main()
{
int x = 10;
int y = 20;
// ref is a reference to x.
int& ref = x;

int& ref2 = y;

ref=ref2;


y=30;
cout<<ref<<endl;
cout<<ref2<<endl;

return 0;
}
