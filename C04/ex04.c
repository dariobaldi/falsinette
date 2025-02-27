#include<stdio.h>
#include<limits.h>

void ft_putnbr_base(int nbr, char *base);

int main()
{
	char decimal[] = "0123456789";
	char binaire[] = "01";
	char hex[] = "0123456789ABCDEF";
	char ecole[] = "ecole42";

	printf("-Expected/Result:\n");
	printf("7\n");
	ft_putnbr_base(7, decimal);
	printf("-25\n");
	ft_putnbr_base(10, decimal);
	printf("0\n");
	ft_putnbr_base(0, decimal);
	printf("10\n");
	ft_putnbr_base(10, decimal);
	printf("\n\nINT_MAX\n");
	ft_putnbr_base(INT_MAX, decimal);
	printf("\n\nINT_MIN\n");
	ft_putnbr_base(INT_MIN, decimal);
	printf("\n\n0\n");
	ft_putnbr_base(10, binaire);
	printf("\n\n1\n");
	ft_putnbr_base(17, hex);
	printf("\n\n-7\n");
	ft_putnbr_base(5, ecole);
	printf("\n");
}

