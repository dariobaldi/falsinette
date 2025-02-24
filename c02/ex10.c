#include<stdio.h>
#include<string.h>

unsigned int	 ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_check_strlcpy(char *dest, char *src, unsigned int size);

int main()
{
	unsigned int size = 19;
	unsigned int len;
	char str1[] = "This is the source";
	char str2[] = "This is the destination";
	char str3[] = "This is the d";

	len = ft_check_strlcpy(str2, str1, size);
	if (len > 0)
		printf("OK: Long dest\n");
	len = ft_check_strlcpy(str3, str1, size);
	if (len > 0)
		printf("OK: Short dest");
}

unsigned int	ft_check_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int len;

	len = ft_strlcpy(dest, src, size);
	
	unsigned int i = 0;
	while (i < size - 1 && dest[i] )
	{
		if (src[i] != dest[i])
		{
			printf("FAILED. diferent characters. Original/Copy\n%s\n%s\n",src, dest);
			return (0);
		}
		i++;
	}
	if (dest[i] != 0)
	{
		printf("FAILED: no line return\n");
		return (0);
	}
	return (len);
}
