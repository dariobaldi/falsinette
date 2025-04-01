#include<stdio.h>
#include "../utils/constants.h"

unsigned int	 ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_check_strlcpy(char *dest, char *src, unsigned int size);

int main()
{
	unsigned int size = 19;
	unsigned int len;
	int failed = 0;
	char str1[] = "This is the source";
	char str2[] = "This is the destination";
	char str3[] = "This is the d";

	len = ft_check_strlcpy(str2, str1, size);
	if (len == 0)
	{
		failed = 1;
		printf(RED "[1] Long dest\n" DEFAULT);
	}
	else
		printf(GREEN CHECKMARK GREY "[1] Long dest\n" DEFAULT);

	len = ft_check_strlcpy(str3, str1, size);
	if (len == 0)
	{
		failed = 1;
		printf(RED "[2] Short dest\n" DEFAULT);
	}
	else
		printf(GREEN CHECKMARK GREY  "[2] Short dest\n" DEFAULT);
	if (failed)
		return (42);
}

unsigned int	ft_check_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int result;

	result = ft_strlcpy(dest, src, size);
	
	 
	unsigned int i = 0;
	while (i < size - 1 && dest[i] )
	{
		if (src[i] != dest[i])
		{
			printf("diferent characters. Original/Copy\n%s\n%s\n",src, dest);
			return (0);
		}
		i++;
	}
	if (dest[i] != 0)
	{
		printf("no line return\n");
		return (0);
	}
	return (result);
}
