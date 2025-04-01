#include<stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main()
{
	int tab[10] = {4,2,7,5,6,9,3,0,1,8};

	ft_sort_int_tab(&tab[0], 10);

	if (tab[0] == 0
		&& tab[1] == 1
		&& tab[2] == 2
		&& tab[3] == 3
		&& tab[4] == 4
		&& tab[5] == 5
		&& tab[6] == 6
		&& tab[7] == 7
		&& tab[8] == 8
		&& tab[9] == 9)
	{
		return (0);
	}
	printf("FAILED. Result/Expected\n");

	int i = 0 - 1;
	while (++i < 10)
	{
		printf("%d", tab[i]);
	}
	printf("\n0123456789\n");
	return (42);
}
