#include<bits/stdc++.h>
using namespace std;

bool isMember(vector<int> vec,int ser){

  std::vector<int>::iterator it;

  it = find (vec.begin(), vec.end(), ser);
  if (it != vec.end()) return true;
  else return false;

}

int minfix(string str1, string str2){

  int result=0;

  int n1 = str1.length(), n2 = str2.length();

  for (int i1=0, j1=0 , i2=n1-1, j2=n2-1; i1<=n1-1 && j1<=n2-1 && i2>=0 && j2>=0; i1++,j1++,i2--,j2--)
  {
      if ( (str1[i1] != str2[j1] ) || (str1[i2] != str2[j2] )  )
          break;

      result++;
  }

  return result;


}



int main(){

vector<int> v;

/*v.push_back(9);
v.push_back(5);
v.push_back(91);
v.push_back(1);
v.push_back(7);


cout<<endl;

for(int i=0;i<=n;i++) cout<<isMember[i]<<" ";

cout<<endl;


if(isMember(v,4)) printf("Yes");
else printf("No");*/

cout<<minfix("problem","problem")<<endl;


return 0;
}
