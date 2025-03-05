#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main()
{
	int failed = 0;
	char *str1 = "First line"; 
	char *str2 = "Second line"; 
	char *str3 = "Third line";
	char *sep = "-/-";
	char *result;
	char *expected = "First line-/-Second line-/-Third line";
	char **strs = (char **)malloc(sizeof(char **) * 3);
	if (!strs)
	{
		printf("Error: could not allocate memory for strs\n");
		return (-42);
	}

	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;
	
	result = ft_strjoin(0, strs, sep);
	if (!result)
	{
		printf("FAILED: size 0, pointer is NULL and should be empty string\n");
		failed = 1;
	}
	else if (*result != 0)
	{
		printf("FAILED: size 0, it should return an empty string\n");
		failed = 1;
	}

	free(result);

	result = ft_strjoin(3, strs, sep);
	if (strcmp(result, expected))
	{
		printf("FAILED: simple join of 3 elements\n");
		failed = 1;
	}

	free(result);
	free(strs);

	if (!failed)
		printf("OK");

}
