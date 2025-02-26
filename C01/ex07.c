#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int main()
{
	int a1[] = {1,2,3,4};
	int a2[] = {1,2,3,4,5,6,7};

	ft_rev_int_tab(a1, 4);
	ft_rev_int_tab(a2, 7);

	if (a1[0] == 4 && a1[1] == 3 && a1[2] == 2 && a1[3] == 1
	&& a2[0] == 7 && a2[1] == 6 && a2[2] == 5 && a2[3] == 4
	&& a2[4] == 3 && a2[5] == 2 && a2[6] == 1)
	{
		printf("OK");
		return (0);
	}
	printf("FAILED");
}
