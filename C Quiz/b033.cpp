#include <stdio.h>
int f1() { printf ("Geeks"); return 1;}
int f2() { printf ("Quiz"); return 1;}

int main()
{
  int p = f1() + f2();
  return 0;
}
