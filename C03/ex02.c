#include<stdio.h>
#include<string.h>

char *ft_strcat(char *dest, char *src);
unsigned int	ft_check_strcat(char *s1, char *s2, char *s3, char *s4);

int main()
{
	int result;
	int failed = 0;
	char str1[50] = "This is the dest";
	char str2[] = ", and this is the source";
	char str3[50] = "This is the dest";
	char str4[] = ", and this is the source";

	result = ft_check_strcat(str1, str2, str3, str4);
	if (!result)
	{
		printf("FAILED\n");
		failed = 1;
	}

	if (!failed)
		printf("OK");

}

unsigned int	ft_check_strcat(char *s1, char *s2, char *s3, char *s4)
{
	int i;

	ft_strcat(s1, s2);
	strcat(s3, s4);
	
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
