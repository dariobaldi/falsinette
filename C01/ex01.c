#include<stdio.h>

void ft_ultimate_ft(int *********nbr);

int main()
{
	int a = 3;
	int* ptr1 = &a; 
	int** ptr2 = &ptr1; 
	int*** ptr3 = &ptr2; 
	int**** ptr4 = &ptr3; 
	int***** ptr5 = &ptr4; 
	int****** ptr6 = &ptr5; 
	int******* ptr7 = &ptr6; 
	int******** ptr8 = &ptr7; 
	int********* nbr = &ptr8;

	ft_ultimate_ft(nbr);
	if (a != 42)
	{
		printf("FAILED. Value returned: %d\n", a);
		return (42);
	}
}
