#include<bits/stdc++.h>
using namespace std;
long long int n,m,ans,count1;
string str1,str2,str3="";
long long int freq1[26]={0};
long long int freq2[26]={0};
int main(){
    cin>>str1;
    cin>>str2;
    n=str1.length();
    m=str2.length();
    for(int i=0;i<n;i++) freq1[str1[i]-'a']++;
    for(int i=0;i<m;i++) freq2[str2[i]-'a']++;
    count1=n+1;
    for(int i=0;i<26;i++) if(freq2[i]) count1=min(count1,freq1[i]/freq2[i]);
    for(int i=0;i<26;i++) if(freq2[i]) freq1[i]=freq1[i]-freq2[i]*(count1);
    int i=1;
    while(i<m && str2[i]==str2[0]) i++;
    if(i==m ||str2[i]<=str2[0]){
      for(int i=0;i<26;i++) {
        if(i==str2[0]-'a') while(count1--) str3=str3+str2;
        while(freq1[i]--) str3=str3+(char)(i+'a');
      }
    }
    else {
      for(int i=0;i<26;i++) {
        while(freq1[i]--) str3=str3+(char)(i+'a');
        if(i==str2[0]-'a') while(count1--) str3=str3+str2;
      }
    }
    cout<<str3<<endl;
    return 0;
}
