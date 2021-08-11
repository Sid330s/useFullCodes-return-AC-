#include<iostream>
using namespace std;
int x = 10;
int &fun()
{

    return x;
}
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}
