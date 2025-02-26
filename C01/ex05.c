#include<stdio.h>

void ft_putstr(char *str);

int main()
{
	char str[] = "I solemnly swear that I am up to no good.";

	printf("Result/Expected:\n");
	ft_putstr(str);
	printf("\n%s\n", str);
}
