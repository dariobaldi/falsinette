#include<stdio.h>

int ft_str_is_numeric(char *str);

int main()
{
	int t1, t2, t3;
	char *str1 = "12345215";
	char *str2 = "132 5465";
	char *str3 = "555S5555";

	t1 = ft_str_is_numeric(str1);
	t2 = ft_str_is_numeric(str2);
	t3 = ft_str_is_numeric(str3);
	if (!t1 && t2 && t3)
	{
		printf("Result/Expected\n");
		printf("%s: %d/%d\n", str1, 1, t1);
		printf("%s: %d/%d\n", str2, 0, t2);
		printf("%s: %d/%d\n", str3, 0, t3);
		return (42);
	}
}
