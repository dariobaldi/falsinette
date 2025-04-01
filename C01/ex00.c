#include<stdio.h>

void ft_ft(int *nbr);

int main()
{
	int a = 3;

	ft_ft(&a);
	if (a != 42)
	{
		printf("FAILED. Value returned: %d\n", a);
		return (42);
	}
}
