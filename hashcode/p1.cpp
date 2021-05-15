#include<bits/stdc++.h>
using namespace std;
int D,I,S,V,F,A=0,num;
string inp;
struct street{
  int B;
  int E;
  string name;
  int L;
};
struct car{
  int P;
  vector<string> paths;
};
street arr[100005];
car brr[1005];
vector<int> chowk[100005];
int nos[100005];
int weight[100005];
unordered_map<string,int> ump;
bool sortby(int a,int b)
{
    return ( weight[a] > weight[b]);
}
int main()
{
    freopen("f.txt","r",stdin);
    freopen("f.out", "w", stdout);
    cin>>D>>I>>S>>V>>F;
    for(int i=0;i<S;i++) {
      cin>>arr[i].B;
      cin>>arr[i].E;
      cin>>arr[i].name;
      cin>>arr[i].L;
      chowk[arr[i].E].push_back(i);
      ump[arr[i].name]=i;
    }
    for(int i=0;i<V;i++) {
      cin>>brr[i].P;
      for(int j=0;j<brr[i].P;j++){
        cin>>inp;
        brr[i].paths.push_back(inp);
        weight[ump[inp]]++;
      }
    }

    for(int i=0;i<I;i++){
      nos[i]=chowk[i].size();
      num=0;
      for(int j=0;j<nos[i];j++) if(weight[chowk[i][j]]!=0) num++;
      if(num || nos[i]==1) A++;
    }

    cout<<A<<endl;
    for(int i=0;i<I;i++){
      if(nos[i]==0) ;
      else if(nos[i]==1) {
        cout<<i<<endl;
        cout<<"1"<<endl;
        cout<<arr[chowk[i][0]].name<<" "<<D<<endl;
      }
      else {

        num=0;
        for(int j=0;j<nos[i];j++) if(weight[chowk[i][j]]!=0) num++;
        if(num>0){
          cout<<i<<endl;
          cout<<num<<endl;
          sort(chowk[i].begin(),chowk[i].end(),sortby);
          for(int j=0;j<nos[i];j++) if(weight[chowk[i][j]]!=0) cout<<arr[chowk[i][j]].name<<" "<<1<<endl;
        }

      }
    }
    return 0;
}
