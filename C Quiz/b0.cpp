#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void func(int &a)
{
	int temp = 10;
	a = temp;
	cout<<a;
}

int main(int argc, char const *argv[])
{
	int a = 5;
	func(a);
	return 0;
}
