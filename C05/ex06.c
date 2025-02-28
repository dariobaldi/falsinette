#include<stdio.h>

int ft_is_prime(int nb);

int main()
{
	int		result, failed;

	failed = 0;
	result = ft_is_prime(0);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_is_prime(1);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_is_prime(2);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_is_prime(3);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_is_prime(9);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_is_prime(11);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	result = ft_is_prime(97);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\1\n", result);
		failed = 1;
	}

	result = ft_is_prime(999333);
	if (result != 0)
	{
		printf("Result/Expected:\n%d\n0\n", result);
		failed = 1;
	}

	result = ft_is_prime(999331);
	if (result != 1)
	{
		printf("Result/Expected:\n%d\n1\n", result);
		failed = 1;
	}

	if (!failed)
		printf("OK");
}

