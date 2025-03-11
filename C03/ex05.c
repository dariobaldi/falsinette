#include<stdio.h>
#include<bsd/string.h>

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_check_strlcat(char *dest1, char *src, char *dest2, unsigned int size);

int main()
{
	int result;
	int failed = 0;
	char src1[] = "working?";
	char src2[] = "";
	char dest1[50] = "Is this ";
	char dest2[50] = "Is this ";


	result = ft_check_strlcat(dest1, src1, dest2, 17);
	if (!result)
	{
		printf("FAILED: basic\n");
		failed = 1;
	}

	result = ft_check_strlcat(dest1, src2, dest2, 14);
	if (!result)
	{
		printf("FAILED: empty\n");
		failed = 1;
	}

	result = ft_check_strlcat(NULL, src1, NULL, 5);
	if (!result)
	{
		printf("FAILED: NULL destination\n");
		failed = 1;
	}

	// char dest3[] = "0123456789";
	// char dest4[] = "0123456789";
	// dest3[10] = '0';
	// dest4[10] = '0';
	// result = ft_check_strlcat(dest3, src1, dest4, 0);
	// if (!result)
	// {
	// 	printf("FAILED: dest not NUL terminated\n");
	// 	failed = 1;
	// }

	if (!failed)
		printf("OK");

}

unsigned int	ft_check_strlcat(char *dest1, char *src, char *dest2, unsigned int size)
{
	int expected, result;

	result = ft_strlcat(dest1, src, size);
	expected = strlcat(dest2, src, size);
	
	printf("\nstrlcat:\t%s\nft_strlcat:\t%s\n", dest2, dest1);
	return (result == expected);
}
