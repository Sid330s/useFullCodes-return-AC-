
#include<bits/stdc++.h>
using namespace std;
int random(int l,int r){
  return l + (rand()%(r-l+1));
}
int main()
{
  int t;
  cin>>t;
  while(t--){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    while(true){
      int i = random(0,n-1);
      int p=arr[i];
      int freqp=0;
      for(int j=0;j<n;j++)
        if(arr[i]==p)
          freqp++;
      if(freqp>n/2) cout<<"Majority element is: "<<p<<endl,exit(0);
    }
  }
 return 0;
}
