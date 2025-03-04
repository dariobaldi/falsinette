#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int *ft_range(int min, int max);

int main()
{
	int failed = 0;
	int *result;
	int min = 0;
	int max = 42;
	int i;

	result = ft_range(min, max);

	i = 0;
	while (i < max - min)
	{
		if (i + min != result[i])
		{
			printf("FAILED: range 0 up to 42\n");
			failed = 1;
		}
		i++;
	}

	min = INT_MIN;
	max = INT_MIN + 250;
	result = ft_range(min, max);
	i = 0;
	while (i < max - min)
	{
		if (i + min != result[i])
		{
			printf("FAILED: range INT_MIN up to INT_MIN + 250\n");
			failed = 1;
		}
		i++;
	}

	min = INT_MAX - 250;
	max = INT_MAX;
	result = ft_range(min, max);
	i = 0;
	while (i < max - min)
	{
		if (i + min != result[i])
		{
			printf("FAILED: range INT_MAX - 250up to INT_MAX\n");
			failed = 1;
		}
		i++;
	}

	min = 10;
	max = 0;
	result = ft_range(min, max);
	if (result)
	{
		printf("FAILED: range min > max\n");
		failed = 1;
	}

	min = 10;
	max = 10;
	result = ft_range(min, max);
	if (result)
	{
		printf("FAILED: range min == max\n");
		failed = 1;
	}

	free(result);

	if (!failed)
		printf("OK");

}
