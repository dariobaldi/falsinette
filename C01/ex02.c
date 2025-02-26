#include<stdio.h>

void ft_swap(int *a, int *b);

int main()
{
	int a = 2;
	int b = 4;

	ft_swap(&a, &b);
	if (a == 4 && b == 2)
	{
		printf("OK");
		return (0);
	}
	printf("FAILED. Value returned: %d\n", a);
}
