#include<stdio.h>

void ft_putstr(char *str);

int main()
{
	char str[] = "Bon courage!";

	printf("Result/Expected:\n%s\n", str);
	ft_putstr(str);
}
