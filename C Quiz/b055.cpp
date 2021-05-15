#include <stdio.h>

int add(int x, int y)
{
	return printf("%*c%*c", x, '\0', y, '\0');
}

// Driver code
int main()
{
	printf("Sum = %d", add(83, 4));
	return 0;
}
