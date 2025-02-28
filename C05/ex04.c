#include<stdio.h>

int ft_fibonacci(int index);

int main()
{
	int		result, failed;

	failed = 0;
	result = ft_fibonacci(-5);
	if (result != -1)
	{
		printf("Result/Expected:\n%d\n-1\n", result);
		failed = 1;
	}

	result = ft_fibonacci(0);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_fibonacci(1);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_fibonacci(2);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_fibonacci(3);
	if (result != 2)
	{
		printf("Result/Expected:\n%d\n2\n", result);
		failed = 1;
	}

	result = ft_fibonacci(10);
	if (result != 55)
	{
		printf("Result/Expected:\n%d\n55\n", result);
		failed = 1;
	}

	result = ft_fibonacci(19);
	if (result != 4181)
	{
		printf("Result/Expected:\n%d\n4181\n", result);
		failed = 1;
	}

	if (!failed)
		printf("OK");
}

