#include<stdio.h>

int ft_ten_queens_puzzle(void);

int main()
{
	int total_solutions;
	
	total_solutions = ft_ten_queens_puzzle();
	if (total_solutions != 724)
	{
		printf("Total solutions not the same. Result/Expected:\n%d\n724\n", total_solutions);
	}
}

