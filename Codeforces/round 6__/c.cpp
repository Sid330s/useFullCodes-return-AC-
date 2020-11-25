#include<bits/stdc++.h>
using namespace std;

long long int arr[100005],n;

int main(){

  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  if(n==1){

    cout<<"1 1"<<endl;
    cout<<-arr[0]<<endl;
    cout<<"1 1"<<endl;
    cout<<arr[0]<<endl;
    cout<<"1 1"<<endl;
    cout<<-arr[0]<<endl;
    return 0;
  }
  cout<<"1 1"<<endl;
  cout<<(n-1)*arr[0]<<endl;
  cout<<"2 "<<n<<endl;
  for(int i=1;i<n;i++) cout<<(n-1)*arr[i]<<" ";
  cout<<endl;
  cout<<"1 "<<n<<endl;
  for(int i=0;i<n;i++) cout<<(-n)*arr[i]<<" ";
  cout<<endl;
  return 0;

}
