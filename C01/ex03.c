#include<stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod);

int main()
{
	int a = 42;
	int b = 5;
	int div = 0;
	int mod = 0;

	ft_div_mod(a, b, &div, &mod);	
	if (div == 8 && mod == 2)
	{
		printf("OK");
		return (0);
	}
	printf("FAILED. Result/Expected - div: %d =? %d - mod %d =? %d\n", div, 8, mod, 2);
}
