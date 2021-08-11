#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
		int * p1 = arr;
		int * p2 = &arr[0];
		int * p3 = &arr;
    printf("%d : %d : %d",p1,p2,p3);
    return 0;
}
