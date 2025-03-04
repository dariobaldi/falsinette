#include<stdio.h>

int    ft_find_next_prime(int nb);

int main()
{
	int		result, failed;

	failed = 0;
	result = ft_find_next_prime(1);
	if (result != 2)
	{
		printf("Result/Expected:\n%d\n2\n", result);
		failed = 1;
	}

	result = ft_find_next_prime(3);
	if (result != 3)
	{
		printf("Result/Expected:\n%d\n3\n", result);
		failed = 1;
	}
	
	result = ft_find_next_prime(14572866);
	if (result != 14572871)
	{
		printf("Result/Expected:\n%d\n14572871\n", result);
		failed = 1;
	}

	if (!failed)
		printf("OK");
}

