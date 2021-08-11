#include <stdio.h>
 struct {int a[2];} arr[] = {{1},{2}};
int main()
{


 printf("%d %d %d %d",arr[0].a[0],arr[0].a[1],arr[1].a[0],arr[1].a[1]);

 return 0;
}
