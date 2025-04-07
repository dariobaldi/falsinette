#include <stdio.h>
#include "../utils/constants.h"
#include <stdlib.h>

void    ft_foreach(int *tab, int length, void(*f)(int));

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

void    ft_putnbr(int nbr)
{
    printf("%d", nbr);
}

int main()
{
	int length;
	int *array;
	int min;
	int max;

	min = -42;
	max = 42;
	length = ft_ultimate_range(&array, min, max);

  ft_foreach(array, length, &ft_putnbr);

	free(array);
}