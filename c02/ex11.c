#include <stdio.h>

void ft_putstr_non_printable(char *str);

int main()
{
	printf("\n-Expected/Result:\nCoucou\\0atu vas\\09bien ?\n");
	ft_putstr_non_printable("Coucou\ntu vas\tbien ?");

	printf("\n");
}
