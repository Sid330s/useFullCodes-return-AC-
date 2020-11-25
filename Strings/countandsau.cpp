#include<bits/stdc++.h>
using namespace std;
string func(string str){
   string saystr="";
   int n=str.length();
   for(int i=0;i<n;i++) {
     int count1=1;
     while(i<n-1 && str[i]==str[i+1]){
       count1++;
       i++;
     }
     saystr=saystr+(char)(count1+48)+ str[i];
   }

   return saystr;
}

string countAndSay(int n) {
  if(n==1) return "1";

  return func(countAndSay(n-1));

}

int main(){

  int t,n;
  string str;
  cin>>t;
  while(t--){
    cin>>n;
    //cout<<func(str)<<endl;
    cout<<countAndSay(n)<<endl;
  }
  return 0;
}
