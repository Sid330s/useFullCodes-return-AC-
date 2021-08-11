#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int n,k,arr[10000];

int partition (int low, int high)
{
	int pivot = arr[low+k%(high-low+1)];
  int temp[high-low+1];
  
	for (int i = 0; i <= high-low; i++)
	{
    temp[i]=;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int low, int high)
{
	if (low < high)
	{
		int pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

void printArray(int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main(){

    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    quickSort(0, n - 1);
    printArray(n);
    return 0;
}
