#include <stdio.h>
#include <iostream>
using namespace std;


int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	int arr[n];

	cout << "Enter array" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0, n-1);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}

	return 0;
}


int partition(int arr[], int low, int high){

	int pivot = arr[high];

	int j = low - 1;
	for (int i = low; i < high-1; ++i)
	{
		if (arr[i]<=arr[pivot])
		{
			j++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[j] = temp;
		}
	}

	return j+1;

}

 void quickSort(int arr[], int low, int high){
 	if (low < high)
 	{
 		int pi = partition(arr, low, high);
 		quickSort(arr, low, pi-1);
 		quickSort(arr, pi+1, high);
 	}
 }
