// Works in C, but compilation error in C++
#include<stdio.h>
int main()
{
  // arr[] is not terminated with '\0'
  // and its size is 5
  char arr[5] = "geek";

  printf("%lu", sizeof(arr));

  return 0;
}
