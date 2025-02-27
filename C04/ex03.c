#include<stdio.h>
#include<limits.h>

int ft_atoi(char *str);

int main()
{
	int		result, failed;
	char	*str = " ---+--+1234ab567";

	failed = 0;
	result = ft_atoi(str);
	if (result != -1234)
	{
		printf("FAILED: \" ---+--+1234ab567\"\n");
		failed = 1;
	}

	str = "56789";
	result = ft_atoi(str);
	if (result != 56789)
	{
		printf("FAILED: \"56789\"\n");
		failed = 1;
	}

	str = "+--2147483647";
	result = ft_atoi(str);
	if (result != 2147483647)
	{
		printf("FAILED: \"+--2147483647\"\n");
		failed = 1;
	}

	str = "-2147483648";
	result = ft_atoi(str);
	if (result != -2147483648)
	{
		printf("FAILED: \"-2147483648\"\n");
		failed = 1;
	}

	str = "  –+-I2147483647";
	result = ft_atoi(str);
	if (result != 0)
	{
		printf("FAILED: \"  –+-I2147483647\"\n");
		failed = 1;
	}

	if (!failed)
		printf("OK");
}

