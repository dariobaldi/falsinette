#include <limits.h>
#include <stdlib.h>

void ft_print_combn(int n);

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = atoi(av[1]);
		ft_print_combn(i);
	}
}

