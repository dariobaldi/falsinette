#include<stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

int main()
{
	int a = 42;
	int b = 5;

	ft_ultimate_div_mod(&a, &b);	
	if (a == 8 && b == 2)
	{
		printf("OK");
		return (0);
	}
	printf("FAILED. Result/Expected - a: %d =? %d - b %d =? %d\n", a, 8, b, 2);
}
