#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int main(int argc, char const *argv[])
{
	int x=5;
	int& a = x;
	int& b = a;
	cout<<a<<" "<<b<<endl;
	a=6;
	cout<<a<<" "<<b<<endl;

	return 0;
}
