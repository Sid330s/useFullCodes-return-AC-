#include<bits/stdc++.h>
using namespace std;

struct node{
   node * children[26];
   bool isEnd;
};

node * getNode(){
  node * new_node = new node;
  new_node->isEnd=false;
  for(int i=0;i<26;i++)
    new_node->children[i]=NULL;
  return new_node;
}

void insert(node * root,string str){
  int n=str.length();
  node * pCrawl = root;
  for(int i=0;i<n;i++){
     int index=str[i]-'a';
     if (!pCrawl->children[index])
      pCrawl->children[index]=getNode();
     pCrawl=pCrawl->children[index];
  }
  pCrawl->isEnd=true;
}

bool search(node * root,string key){
  node * pCrawl = root;
  for (int i = 0; i < key.length(); i++)
   {
       int index = key[i] - 'a';
       if (!pCrawl->children[index])
           return false;

       pCrawl = pCrawl->children[index];
   }

   return (pCrawl != NULL && pCrawl->isEnd);
}

int main(){
  int t;
  cin>>t;
  node * root=getNode();
  while(t--){
      string str;
      cin>>str;
      insert(root,str);
  }
  cout<<search(root,"siddharth")<<endl;
  cout<<search(root,"maruti")<<endl;
  cout<<search(root,"kale")<<endl;
  return 0;
}
