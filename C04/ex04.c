#include<stdio.h>
#include<limits.h>

void ft_putnbr_base(int nbr, char *base);

int main()
{
	char decimal[] = "0123456789";
	char binaire[] = "01";
	char hex[] = "0123456789ABCDEF";
	char ecole[] = "#@!";

	printf("-Expected/Result:\n");
	printf("\n7\n");
	ft_putnbr_base(7, decimal);
	printf("\n\n-25\n");
	ft_putnbr_base(-25, decimal);
	printf("\n\n0\n");
	ft_putnbr_base(0, decimal);
	printf("\n\n10\n");
	ft_putnbr_base(10, decimal);
	printf("\n\n2147483647(INT_MAX)\n");
	ft_putnbr_base(INT_MAX, decimal);
	printf("\n\n-2147483648(INT_MIN)\n");
	ft_putnbr_base(INT_MIN, decimal);
	printf("\n\n1010\n");
	ft_putnbr_base(10, binaire);
	printf("\n\n4EF\n");
	ft_putnbr_base(1263, hex);
	printf("\n\n@@!#\n");
	ft_putnbr_base(42, ecole);
	printf("\n");
}

