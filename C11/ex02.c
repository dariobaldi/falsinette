#include <stdio.h>
#include <stdlib.h>
#include "../utils/constants.h"

int	ft_any(char **tab, int (*f)(char*));

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'z')
			return (0);
		if (str[i] < 'a' && str[i] > 'Z')
			return (0);
		i++;
	}
	return (42);
}


int main()
{
	int result;
	int failed = 0;
	
	char **array = (char **)malloc(sizeof(char *) * 3);
	if (!array)
		return (-42);
	array[0] = "Test1";
	array[1] = "Test2";
	array[2] = NULL;
	
    result = ft_any(array, &ft_str_is_alpha);
	if (result != 1)
	{
		printf(RED "Error: got \"%d\" instead of \"%d\"\n" DEFAULT, result, 1);
		failed = -42;
	}

	array[0] = "Test";
	array[1] = "Tests";
	    result = ft_any(array, &ft_str_is_alpha);
	if (result != 0)
	{
		printf(RED "Error: got \"%d\" instead of \"%d\"\n" DEFAULT, result, 1);
		failed = -42;
	}
	return (failed);
}