#include<stdio.h>
#include <string.h>
#include<stdlib.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main()
{
	char *str1 = "This is the source";
	char *str2 = (char *) malloc(sizeof(char) * 20);
	char *str3 = (char *) malloc(sizeof(char) * 20);

	ft_strncpy(str2, str1, 6);
	strncpy(str3, str1, 6);
	
	int i = 0;
	while (str1[i])
	{
		if (str3[i] != str2[i])
		{
			printf("FAILED. Result/Expected\n");
			printf("%s\n",str2);
			printf("%s\n",str3);
			return (0);
		}
		i++;
	}	
	printf("OK");
	free(str2);
	free(str3);
}
