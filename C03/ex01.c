#include<stdio.h>
#include<string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);
unsigned int	ft_check_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
	int result;
	int failed = 0;
	char str1[] = "This is the same";
	char str2[] = "This is the same";
	char str3[] = "This is the different";
	char str4[] = "This too";

	result = ft_check_strncmp(str1, str2, 10);
	if (result != 0)
	{
		printf("FAILED: same string\n");
		failed = 1;
	}
	result = ft_check_strncmp(str1, str3, 10);
	if (result > 0)
	{
		printf("FAILED: longer diff\n");
		failed = 1;
	}
	result = ft_check_strncmp(str1, str4, 10);
	if (result > 0)
	{
		printf("FAILED: shorter diff string\n");
		failed = 1;
	}
	result = ft_check_strncmp(str1, str4, 0);
	if (result > 0)
	{
		printf("FAILED: size 0\n");
		failed = 1;
	}

	if (!failed)
		printf("OK");

}

unsigned int	ft_check_strncmp(char *s1, char *s2, unsigned int n)
{
	int result, expected;

	result = ft_strncmp(s1, s2, n);
	expected = strncmp(s1, s2, n);
	
	return (result - expected);
}
