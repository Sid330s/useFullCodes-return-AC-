#include<bits/stdc++.h>
using namespace std;
int Count(int arr[],int num,int l,int r)
{
 int c = 0;
 for(int i=l;i<=r;i++)
    if(arr[i]==num) c++;
 return c;
}

int majority(int arr[],int l,int r)
{
    if(l==r)   return arr[l];
    int mid   =  (r+l)/2;
    int left  =   majority(arr,l,mid);
    int right =  majority(arr,mid+1,r);
    if(left==right) return left;
    int c1 = Count(arr,left,l,r);
    int c2 = Count(arr,right,l,r);
    if(c1>c2) return left;
    else    return right;
}

int main()
{
 int t;
 cin>>t;
 while(t--){
    int c,i,n,ct=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)   cin>>arr[i];
    int m = majority(arr,0,n-1);
    for(i=0;i<n;i++)    if(arr[i]==m)  ct++;
    if(ct>n/2) cout<<m<<"\n";
    else  cout << "Does Not Exists" << endl;
    }
 return 0;
}
