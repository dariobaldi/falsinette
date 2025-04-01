#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main()
{
	char *str1 = "This is the source";
	char *str2 = (char *) malloc(sizeof(char) * 20);
	char *str3 = (char *) malloc(sizeof(char) * 20);
	unsigned int	len = 19;

	ft_strncpy(str2, str1, len);
	strncpy(str3, str1, len);
	
	unsigned int i = 0;
	while (str1[i] && i < len)
	{
		if (str3[i] != str2[i])
		{
			printf("Result/Expected\n");
			printf("%s\n",str2);
			printf("%s\n",str3);
			return (42);
		}
		i++;
	}
	while (i < len)
	{
		if (str2[i])
		{
			printf("characters are not null after len");
			return (42);
		}
		i++;
	}
	free(str2);
	free(str3);
}
