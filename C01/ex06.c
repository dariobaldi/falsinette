#include<stdio.h>

int ft_strlen(char *str);

int main()
{
	char str[] = "Bon courage!";
	int len = ft_strlen(str);

	if (len == 12)
		return (0);
	printf("FAILED. Result/Expected: %d =? %d\n", len, 12);
	return (42);
}
