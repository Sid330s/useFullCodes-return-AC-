#include<iostream>
using namespace std;

class Base
{
public :
    int x, y;
public:
	  //Base(){}
    Base(int i, int j){ x = i; y = j; }
};

class Derived : public Base
{
public:
    Derived(int i, int j){
			x=i;
			y=j;
		}
    void print() {cout << x <<" "<< y; }
};

int main(void)
{
    Derived q(10, 10);
    q.print();
    return 0;
}
