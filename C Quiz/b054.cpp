#include <iostream>

using namespace std;
class C {
public:
	int a;
	int b;
public:
	C operator - (){
		a=-a;
		b=-b;
		return *this;
	}
};

int main(){
	C c;
 	c.a=2;
	c.b=-3;
	-c;
	cout<<c.a<<" "<<c.b<<endl;
 	return 0;
}
