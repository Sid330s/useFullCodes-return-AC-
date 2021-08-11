#include<bits/stdc++.h>
using namespace std;
const int n=5;
int mat[n][n];
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Given a number as a char array number[], this function finds the
// next greater number.  It modifies the same array to store the result
void findNextPermutation(char number[], int n)
{
    int i, j; 
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;


    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;

    swap(&number[smallest], &number[i-1]);

    // IV) Sort the digits after (i-1) in ascending order
    sort(number + i, number + n);

    cout << "Next number with same set of digits is " << number;

    return;
}
int partition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int k=l-1;
    for(int i=l;i<=r-1;i++)
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
    quicksort(v[k],0,n-1);
    do{v.push_back(arr1);} while(next_permutation(arr1.begin(),arr1.end()));
    for(int k=0;k<v.size();k++) quicksort(v[k],0,n-1);
    cout<<"Sorted array is :"<<endl;
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    cout<<endl;
    cout<<"Comparison matrix is :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<mat[i][j]<<"\t";
        cout<<endl;
    }

    return 0;

}
