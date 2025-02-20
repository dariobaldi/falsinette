#include <stdio.h>

void ft_putchar(char c);

int main()
{
	char c1 = 'A';
	char c2 = 'B';
	char c3 = 'C';

	printf("%c%c%c\n", c1, c2, c3);

	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);

	printf("\n");
}
