#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int ft_ultimate_range(int **range, int min, int max);

int main()
{
	int failed = 0;
	int result;
	int *array;
	int min;
	int max;
	int i;

	min = 0;
	max = 42;
	result = ft_ultimate_range(&array, min, max);
	if (result != 42)
	{
		printf("FAILED: return for range 0 up to 42\n");
		failed = 1;
	}
	i = 0;
	while (i < max - min)
	{
		if (i + min != array[i])
		{
			printf("FAILED: range 0 up to 42\n");
			failed = 1;
		}
		i++;
	}

	min = INT_MIN;
	max = INT_MIN + 250;
	result = ft_ultimate_range(&array, min, max);
	if (result != 250)
	{
		printf("FAILED: return for range INT_MIN up to INT_MIN + 250\n");
		failed = 1;
	}
	i = 0;
	while (i < max - min)
	{
		if (i + min != array[i])
		{
			printf("FAILED: range INT_MIN up to INT_MIN + 250\n");
			failed = 1;
		}
		i++;
	}

	min = INT_MAX - 250;
	max = INT_MAX;
	result = ft_ultimate_range(&array, min, max);
	if (result != 250)
	{
		printf("FAILED: return for range INT_MAX - 250up to INT_MAX\n");
		failed = 1;
	}
	i = 0;
	while (i < max - min)
	{
		if (i + min != array[i])
		{
			printf("FAILED: range INT_MAX - 250up to INT_MAX\n");
			failed = 1;
		}
		i++;
	}

	min = 10;
	max = 0;
	result = ft_ultimate_range(&array, min, max);
	if (result != 0)
	{
		printf("FAILED: return for range min > max\n");
		failed = 1;
	}
	if (result)
	{
		printf("FAILED: range min > max\n");
		failed = 1;
	}

	min = 10;
	max = 10;
	result = ft_ultimate_range(&array, min, max);
	if (result != 0)
	{
		printf("FAILED: return for range min == max\n");
		failed = 1;
	}
	if (result)
	{
		printf("FAILED: range min == max\n");
		failed = 1;
	}

	free(array);

	if (!failed)
		printf("OK");

}
