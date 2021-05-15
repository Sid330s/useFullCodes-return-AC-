#include<bits/stdc++.h>
using namespace std;
long long int m,t2,t3,t4,I,k,n2,n3,n4;
unordered_set<string,long long int> ump;
//int arr[][100000];
pair<long long int,long long int>freq[100005];
string inp;
bool sortby(const pair<long long int,long long int>&a,
              const pair<long long int,long long int> &b)
{
    return (a.first > b.first);
}
int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out", "w", stdout);
    cin>>m>>t2>>t3>>t4;
    k=0;
    for(int i=0;i<m;i++){
      cin>>I;
      freq[i]= make_pair(I,i);
      for(int j=0;j<I;j++){
         cin>>inp;
         //if(ump.find(inp)==ump.end()) ump[inp]=k,k++;
         //arr[i][j]=ump[inp];
      }
    }
    sort(freq,freq+m,sortby);
    n4=min(m/4,t4);
    m=m-4*n4;
    n3=min(m/3,t3);
    m=m-3*n3;
    n2=min(m/2,t2);
    m=m-2*n2;


    cout<<n3+n2+n4<<endl;
    k=0;
    for(int i=0;i<n4;i++){
      cout<<"4 ";
      cout<<freq[k].second<<" "<<freq[k+1].second<<" "<<freq[k+2].second<<" "<<freq[k+3].second<<endl;
      k+=4;
    }
    for(int i=0;i<n3;i++){
      cout<<"3 ";
      cout<<freq[k].second<<" "<<freq[k+1].second<<" "<<freq[k+2].second<<endl;
      k+=3;
    }
    for(int i=0;i<n2;i++){
      cout<<"2 ";
      cout<<freq[k].second<<" "<<freq[k+1].second<<endl;
      k+=2;
    }


    return 0;
}
