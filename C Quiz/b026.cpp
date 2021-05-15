#include<stdio.h>

void func( )
{
static int tmp=10;
printf("%d ",tmp);
}

int main( )
{
	int tmp=20;
printf("%d ",tmp);
func( );
printf("%d ",tmp);
return 0;
}
