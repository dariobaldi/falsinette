#include<limits.h>

void ft_is_negative(int n);

int main()
{
	ft_is_negative(INT_MIN);
	ft_is_negative(0);
	ft_is_negative(-5);
	ft_is_negative(500);
	ft_is_negative(INT_MAX);
}

