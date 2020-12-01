#include<bits/stdc++.h>
using namespace std;
struct dish{
  long long int a;
  long long int b;
};
long long int t,n,time1,time2,ans;
dish arr[200005];
bool compareTwoDishes(dish obj1, dish obj2)
{
    if (obj1.a != obj2.a)
        return obj1.a > obj2.a;

    return (obj1.b < obj2.b);
}

int main(){
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].a;
    for(int i=0;i<n;i++) cin>>arr[i].b;
    sort(arr,arr+n,compareTwoDishes);
    dish d;
    d.a=0;
    d.b=0;
    arr[n]=d;
    time1=arr[0].a;
    time2=0;
    ans=max(time1,time2);
    int i=1;
    while(i<=n){
      time1=arr[i].a;
      time2=time2+arr[i-1].b;
      ans=min(ans,max(time1,time2));
      i++;
    }
    cout<<ans<<endl;

  }
  return 0;
}
