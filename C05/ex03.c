#include<stdio.h>

int ft_recursive_power(int nb, int power);

int main()
{
	int		result, failed;

	failed = 0;
	result = ft_recursive_power(1, -5);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_recursive_power(0, 0);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_recursive_power(1, 0);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_recursive_power(3, 3);
	if (result != 27)
	{
		printf("Result/Expected:\n%d\n27\n", result);
		failed = 1;
	}

	result = ft_recursive_power(2, 10);
	if (result != 1024)
	{
		printf("Result/Expected:\n%d\n1024\n", result);
		failed = 1;
	}

	if (!failed)
		printf("OK");
}

