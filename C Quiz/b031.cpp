#include "stdio.h"

int foo(int a)
{
 printf("%d",a);
 return 0;
}
int f (int n) { if (n == 0)  return n; else return n + f(n-2); }
int main()
{
 foo;
 printf("%d\n",f(100));
 return 0;
}
