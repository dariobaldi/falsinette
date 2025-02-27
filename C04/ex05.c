#include<stdio.h>
#include<limits.h>

int ft_atoi_base(char *str, char *base);

int main()
{
	char decimal[] = "0123456789";
	char binaire[] = "01";
	char hex[] = "0123456789ABCDEF";
	char ecole[] = "#@!";
	int		result, failed;
	char	*str = " ---+--+1234ab567";

	failed = 0;
	result = ft_atoi_base(str, decimal);
	if (result != -1234)
	{
		printf("FAILED: \" ---+--+1234ab567\"\n");
		failed = 1;
	}


	str = "\f\n\r\t\v56789";
	result = ft_atoi_base(str, decimal);
	if (result != 56789)
	{
		printf("FAILED: \"\\f\\n\\r\\t\\v56789\"\n");
		failed = 1;
	}

	str = "56789";
	result = ft_atoi_base(str, decimal);
	if (result != 56789)
	{
		printf("FAILED: \"56789\"\n");
		failed = 1;
	}

	str = "+--2147483647";
	result = ft_atoi_base(str, decimal);
	if (result != 2147483647)
	{
		printf("FAILED: \"+--2147483647\"\n");
		failed = 1;
	}

	str = "-2147483648";
	result = ft_atoi_base(str, decimal);
	if (result != -2147483648)
	{
		printf("FAILED: \"-2147483648\"\n");
		failed = 1;
	}

	str = "  –+-I2147483647";
	result = ft_atoi_base(str, decimal);
	if (result != 0)
	{
		printf("FAILED: \"  –+-I2147483647\"\n");
		failed = 1;
	}

	str = "---1010";
	result = ft_atoi_base(str, binaire);
	if (result != -10)
	{
		printf("FAILED: \"1010\"\n");
		failed = 1;
	}

	str = "4EF";
	result = ft_atoi_base(str, hex);
	if (result != 1263)
	{
		printf("FAILED: \"4EF\"\n");
		failed = 1;
	}

	str = "@@!#";
	result = ft_atoi_base(str, ecole);
	if (result != 42)
	{
		printf("FAILED: \"@@!#\"\n");
		failed = 1;
	}

	if (!failed)
		printf("OK");
}

