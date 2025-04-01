#include<stdio.h>

int ft_str_is_alpha(char *str);

int main()
{
	int t1, t2, t3;
	char *str1 = "Test";
	char *str2 = "Test deux";
	char *str3 = "Test3";

	t1 = ft_str_is_alpha(str1);
	t2 = ft_str_is_alpha(str2);
	t3 = ft_str_is_alpha(str3);
	if (!t1 && t2 && t3)
	{
		printf("Result/Expected\n");
		printf("%s: %d/%d\n", str1, 1, t1);
		printf("%s: %d/%d\n", str2, 0, t2);
		printf("%s: %d/%d\n", str3, 0, t3);
		return (42);
	}
}
