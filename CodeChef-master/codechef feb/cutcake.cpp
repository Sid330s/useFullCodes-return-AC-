#include <bits/stdc++.h>
using namespace std;
int t,n,m,r,f,p1,p2,p3;
struct point{
  int x;
  int y;
  int idx;
};
struct triangle{
  int p1;
  int p2;
  int p3;
};
struct line{
  int u;
  int v;
  bool isConvex;
  int x;
  int y;
};
point points[100005];
triangle triangles[100005];
line encLines[100005];
int brr[100005];
bool isSame(int i,int j){
  return (points[i].x==points[j].x && points[i].y==points[j].y);
}
bool isEnclosed(int i,int j){
  int count=0;
  for(int t=0;t<m;t++){
    if((triangles[t].p1==i || triangles[t].p2==i || triangles[t].p3==i) &&
     (triangles[t].p1==j || triangles[t].p2==j || triangles[t].p3==j) && isSame(i,j)==false) count++;
     if(count==2){
       double m=
     }
  }

  return (count==2);
}
int main()
{

    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
      cin>>points[i].x>>points[i].y;
      points[i].idx=i;
    }
    for(int i=0;i<m;i++) {
      cin>>triangles[i].p1>>triangles[i].p2>>triangles[i].p3;
    }
    for(int i=0;i<r;i++) cin>>brr[i];
    // cout<<"inp"<<endl;
    // for(int i=1;i<=n;i++) cout<<points[i].x<<" "<<points[i].y<<endl;
    // for(int i=0;i<m;i++) cout<<triangles[i].p1<<" "<<triangles[i].p2<<" "<<triangles[i].p3<<endl;
    int k=0;
    bool flag=false;
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if(k==m-r){
          flag=true;
          break;
        }
        if(isEnclosed(i,j)) {
          encLines[k].u=i;
          encLines[k].v=j;
          k++;
        }

      }
      if(flag) break;
    }

    cout<<0<<endl;
    for(int i=0;i<m-r;i++) cout<<encLines[i].u<<" "<<encLines[i].v<<endl;


    return 0;
}
