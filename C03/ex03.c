#include<stdio.h>
#include<string.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);
unsigned int	ft_check_strncat(char *s1, char *s2, char *s3, char *s4, unsigned int nb);

int main()
{
	int result;
	int failed = 0;
	char str1[50] = "This is the dest";
	char str2[] = ", and this is the source";
	char str3[50] = "This is the dest";
	char str4[] = ", and this is the source";

	result = ft_check_strncat(str1, str2, str3, str4, 12);
	if (!result)
	{
		printf("FAILED: simple copy\n");
		failed = 1;
	}

	result = ft_check_strncat(str1, str2, str3, str4, 0);
	if (!result)
	{
		printf("FAILED: size 0\n");
		failed = 1;
	}

	result = ft_check_strncat(str1, str2, str3, str4, 1);
	if (!result)
	{
		printf("FAILED: size1\n");
		failed = 1;
	}

	if (!failed)
		printf("OK");

}

unsigned int	ft_check_strncat(char *s1, char *s2, char *s3, char *s4, unsigned int nb)
{
	int i;

	ft_strncat(s1, s2, nb);
	strncat(s3, s4, nb);
	
	printf("Expected/Result:\n%s\n%s\n", s3, s1);
	i = 0;
	while (s3[i])
	{
		if (s3[i] != s1[i])
			return (0);
		i++;
	}
	return (s3[i] == s1[i]);
}
