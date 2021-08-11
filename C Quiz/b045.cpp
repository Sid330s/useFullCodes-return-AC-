#include <stdio.h>
int main(void)
{
    // Note that fun() is not declared
    printf("%d\n", fun());
    return 0;
}

char fun()
{
   return 'G';
}
