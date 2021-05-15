#include <iostream>
#include <vector>
using namespace std;

class a
{
public :
    a(){
			cout<<"Construct"<<endl;
		}
    ~a()
    {
        cout << "destroy"<<endl;
    }
};
int main()
{
   vector <a*> *v1  = new vector<a*>;
   vector <a> *v2  = new vector<a>;
	 a * aa = new a();
	 a a2;
	 a * a3 = (a*)malloc(sizeof(a));
   return 0;
}
