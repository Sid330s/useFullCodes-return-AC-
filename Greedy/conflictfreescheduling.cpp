#include<iostream>
using namespace std;
void merge(int arr[][2], int l, int m, int r)
{
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;
  int L[n1][2], R[n2][2];
  for (i = 0; i < n1; i++){
      L[i][0] = arr[l + i][0];
      L[i][1] = arr[l + i][1];
  }
  for (j = 0; j < n2; j++){
      R[j][0] = arr[m + 1 + j][0];
      R[j][1] = arr[m + 1 + j][1];
  }
  i=0,j = 0,k = l;
  while (i < n1 && j < n2){
      if (L[i][1] <= R[j][1]){
          arr[k][0] = L[i][0];
          arr[k][1] = L[i][1];
          i++;
      }
      else{
          arr[k][0] = R[j][0];
          arr[k][1] = R[j][1];
          j++;
      }
      k++;
  }
  while (i < n1){
      arr[k][0] = L[i][0];
      arr[k][1] = L[i][1];
      i++;
      k++;
  }
  while (j < n2){
      arr[k][0] = R[j][0];
      arr[k][1] = R[j][1];
      j++;
      k++;
  }
}
void mergeSort(int arr[][2], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void printArray(int A[][2], int size)
{
  for (int i = 0; i < size; i++)
      cout<<i+1<<" ("<<A[i][0]<<" "<<A[i][1]<<")"<<endl;
}
int main()
{
  int n, i, k;
  cout<<"Enter Number Of Intervals : ";
  cin>>n;
  int arr[n][2], s[n][2];
  cout<<"Enter Number Of Intervals (start,end): "<<endl;
  for (i = 0; i < n; i++) cin>>arr[i][0]>>arr[i][1];
  mergeSort(arr,0,n);
  printArray(arr,n);
  s[0][0] = arr[0][0];
  s[0][1] = arr[0][1];
  k = 1;
  for (i = 1; i < n; i++){
      if (arr[i][0] >= s[k - 1][1]){
          s[k][0] = arr[i][0];
          s[k][1] = arr[i][1];
          k++;
      }
  }
  cout<<"No of conflict free schedules : "<<k<<endl;
  cout<<"Conflict free schedules : "<<endl;
  printArray(s, k);
  return 0;
}
