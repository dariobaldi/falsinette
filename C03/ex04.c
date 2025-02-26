#include<stdio.h>
#include<string.h>

char *ft_strstr(char *str, char *to_find);
unsigned int	ft_check_strstr(char *str, char *to_find);

int main()
{
	int result;
	int failed = 0;
	char str1[] = "This is the dest";
	char str2[] = "his";
	char str3[] = " is";
	char str4[] = "destination";

	result = ft_check_strstr(str1, str2);
	if (!result)
	{
		printf("FAILED: basic\n");
		failed = 1;
	}

	result = ft_check_strstr(str1, str3);
	if (!result)
	{
		printf("FAILED: leading space\n");
		failed = 1;
	}

	result = ft_check_strstr(str1, str4);
	if (!result)
	{
		printf("FAILED: bigger word than source\n");
		failed = 1;
	}

	if (!failed)
		printf("OK");

}

unsigned int	ft_check_strstr(char *str,char *to_find)
{
	char *found1;
	char *found2;

	found1 = ft_strstr(str, to_find);
	found2 = strstr(str, to_find);

	printf("\nstrstr:\t\t%p\nft_strstr:\t%p\n",found2,found1);
	if (found1 != found2)
		return (0);
	return (1);
}
