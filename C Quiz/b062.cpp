#include<stdio.h>
int t=printf("GDGF");
void f(int x)
{
printf("%d", x);
}



int main()
{
f(2); /* Poor style in C, invalid in C++*/
getchar();
return 0;
}
