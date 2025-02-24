#include<stdio.h>
#include <string.h>
#include<stdlib.h>

char	*ft_strcpy(char *dest, char *src);
void	ft_print_str(char *str);

int main()
{
	char *str1 = "This is the source";
	char *str2 = (char *) malloc(sizeof(char) * 20);
	char *str3 = (char *) malloc(sizeof(char) * 20);

	ft_strcpy(str2, str1);
	strcpy(str3, str1);
	
	int i = 0;
	while (str1[i])
	{
		if (str3[i] != str2[i])
		{
			printf("FAILED. Result/Expected\n");
			ft_print_str(str2);
			ft_print_str(str3);
			return (0);
		}
		i++;
	}	
	printf("OK");
}

void	ft_print_str(char *str)
{
	int	i = 0;

	while (str[i])
	{	
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}
