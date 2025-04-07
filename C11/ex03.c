#include <stdio.h>
#include <stdlib.h>
#include "../utils/constants.h"

int ft_count_if(char **tab, int length, int(*f)(char*));

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
	int result, expected;
	int failed = 0;
	
	char **array = (char **)malloc(sizeof(char *) * 3);
	if (!array)
		return (-42);
	array[0] = "Test1";
	array[1] = "Test2";
	array[2] = "Test3";
	
  result = ft_count_if(array, 3, &ft_str_is_alpha);
	expected = 0;
	if (result != expected)
	{
		printf(RED "Error: got \"%d\" instead of \"%d\"\n" DEFAULT, result, expected);
		failed = -42;
	}

	array[0] = "Test";
	array[1] = "Tests";
	result = ft_count_if(array, 3, &ft_str_is_alpha);
	expected = 2;
	if (result != expected)
	{
		printf(RED "Error: got \"%d\" instead of \"%d\"\n" DEFAULT, result, expected);
		failed = -42;
	}
	return (failed);
}