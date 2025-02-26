#include<stdio.h>
#include<limits.h>

void ft_putnbr(int nb);

int main()
{
	printf("-Expected/Result:\n");
	printf("10\n");
	ft_putnbr(10);
	printf("\n\n0\n");
	ft_putnbr(0);
	printf("\n\n1\n");
	ft_putnbr(1);
	printf("\n\n-7\n");
	ft_putnbr(-7);
	printf("\n\n500\n");
	ft_putnbr(500);
	printf("\n\nINT_MAX\n");
	ft_putnbr(INT_MAX);
	printf("\n\nINT_MIN\n");
	ft_putnbr(INT_MIN);
	printf("\n");
}

