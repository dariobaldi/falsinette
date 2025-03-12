#include <stdio.h>
#include "../utils/constants.h"
#include <stdlib.h>

int *ft_map(int *tab, int length, int (*f)(int));

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	if (size < 1)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc(size * sizeof(int));
	if (!*range)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

int    ft_test(int a)
{
    return(a + 1);
}

int main()
{
	int length;
	int *array;
	int *result;
	int min;
	int max;
	int i;

	min = -42;
	max = 42;
	length = ft_ultimate_range(&array, min, max);
	
    result = ft_map(array, length, &ft_test);
	i = 0;
	while (i < length)
	{
		if (result[i] != array[i] + 1)
		{
			printf(RED "Error: got \"%d\" instead of \"%d\"\n" DEFAULT, result[i], array[i] + 1);
			return (-42);
		}
		i++;
	}

	free(array);
	free(result);
	return (0);
}