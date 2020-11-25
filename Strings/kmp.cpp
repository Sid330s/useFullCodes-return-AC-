#include<bits/stdc++.h>
using namespace std;
long long int t;
string str1;
string str2;
vector<int> computeLPSArray(string str)
{
    int M = str.length();
    vector<int> lps(M);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) len = lps[len-1];
            else lps[i] = 0,i++;
        }
    }
    return lps;
}

int main(){
  cin>>t;
  while(t--){
  cin>>str1;
  cin>>str2;
  
  return 0;
}
