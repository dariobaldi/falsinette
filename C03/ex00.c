#include<stdio.h>
#include<string.h>

int ft_strcmp(char *s1, char *s2);
unsigned int	ft_check_strcmp(char *s1, char *s2);

int main()
{
	int result;
	int failed = 0;
	char str1[] = "This is the same";
	char str2[] = "This is the same";
	char str3[] = "This is the different";
	char str4[] = "This too";

	result = ft_check_strcmp(str1, str2);
	if (result != 0)
	{
		printf("FAILED: same string\n");
		failed = 1;
	}
	result = ft_check_strcmp(str1, str3);
	if (result > 0)
	{
		printf("FAILED: longer diff\n");
		failed = 1;
	}
	result = ft_check_strcmp(str1, str4);
	if (result > 0)
	{
		printf("FAILED: shorter diff string\n");
		failed = 1;
	}

	if (!failed)
		printf("OK");

}

unsigned int	ft_check_strcmp(char *s1, char *s2)
{
	int result, expected;

	result = ft_strcmp(s1, s2);
	expected = strcmp(s1, s2);
	
	return (result - expected);
}
