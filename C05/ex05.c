#include<stdio.h>

int ft_sqrt(int nb);

int main()
{
	int		result, failed;

	failed = 0;
	result = ft_sqrt(-5);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_sqrt(0);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_sqrt(1);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_sqrt(2);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_sqrt(9);
	if (result != 3)
	{
		printf("Result/Expected:\n%d\n3\n", result);
		failed = 1;
	}

	result = ft_sqrt(100);
	if (result != 10)
	{
		printf("Result/Expected:\n%d\n10\n", result);
		failed = 1;
	}

	result = ft_sqrt(25);
	if (result != 5)
	{
		printf("Result/Expected:\n%d\n4181\n", result);
		failed = 1;
	}

	if (!failed)
		printf("OK");
}

