#include<stdio.h>
#include<limits.h>

int ft_recursive_factorial(int nb);

int main()
{
	int		result, failed;

	failed = 0;
	result = ft_recursive_factorial(-5);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_recursive_factorial(0);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_recursive_factorial(1);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_recursive_factorial(3);
	if (result != 6)
	{
		printf("Result/Expected:\n%d\n6\n", result);
		failed = 1;
	}

	result = ft_recursive_factorial(9);
	if (result != 362880)
	{
		printf("Result/Expected:\n%d\n362880\n", result);
		failed = 1;
	}

	if (!failed)
		printf("OK");
}

