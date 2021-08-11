#include<bits/stdc++.h>
using namespace std;
const int n=5;
int mat[n][n];
int partition(int arr[],int l,int r)
{
    int random = l + rand() % (r-l+1);
    swap(arr[random],arr[r]);
    int pivot=arr[r];
    int k=l-1;

    for(int i=l;i<r;i++)
    {
        mat[i][r]+=1;
        mat[r][i]+=1;
        if(arr[i]<=pivot)
        {
            k++;
            swap(arr[i],arr[k]);
        }
    }
    swap(arr[k+1],arr[r]);
    return(k+1);
}
void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int par=partition(arr,l,r);
        quicksort(arr,l,par-1);
        quicksort(arr,par+1,r);
    }
}
int main()
{
    cout<<"Enter the elements :"<<endl;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) mat[i][j]=0;
    cout<<"Sorted array :"<<endl;
    for(int l=0;l<120;l++) quicksort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Comparison matrix :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<mat[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
