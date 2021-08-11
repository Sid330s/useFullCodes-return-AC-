#include<bits/stdc++.h>
using namespace std;
int c[100][100];
int a[100];
int partition(int arr[], int low, int high)
{
     int pivot = arr[high];
     int i = (low - 1);
     for (int j = low; j <= high - 1; j++) {
        c[j][high]++;
        c[high][j]++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partition_r(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}
 void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)    c[i][j]=0;
    int n,N;
    cout<<"Enter the number of elements of array\n";
    cin>>n;
    cout<<"Enter the number N\n";
    cin>>N;
    cout<<"Enter the elements of array\n";
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<N;i++)
        quickSort(a,0,n-1);
    cout<<endl;
    cout<<"\t";
    for(int i=0;i<n;i++)    cout<<a[i]<<"\t";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t";
        for(int j=0;j<n;j++)    cout<<c[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
