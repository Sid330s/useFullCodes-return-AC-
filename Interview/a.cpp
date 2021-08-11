#include<iostream>
using nams
struct st{

  char
  int
}

bool comparator(pair<char,int> p1,pair<char,int> p2){
  if(p1.second<p2.second) return true;
  return false;
}

{

  int freq[26]={0};
  cin>>str;

  for(int i=0;i<str.length();i++){
    freq[str[i]-'a']++; //O(1)
  }

  pair<char,int> vec;

  for(int i=0;i<26;i++){
    vec.insert(i+'a',freq[i]);
  }


  vec.sort(vec.begin(),vec.end(),comparator)


  for(int i=0;i<vec.size();i++) cout<<vec.first<<" :"vec.second;

}
