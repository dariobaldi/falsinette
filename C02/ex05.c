#include<stdio.h>

int ft_str_is_uppercase(char *str);

int main()
{
	int t1, t2, t3;
	char *str1 = "SDFSSFDSE";
	char *str2 = "IIIIIlIIIII";
	char *str3 = "ASDAS$#%$";

	t1 = ft_str_is_uppercase(str1);
	t2 = ft_str_is_uppercase(str2);
	t3 = ft_str_is_uppercase(str3);
	if (!t1 && t2 && t3)
	{
		printf("Result/Expected\n");
		printf("%s: %d/%d\n", str1, 1, t1);
		printf("%s: %d/%d\n", str2, 0, t2);
		printf("%s: %d/%d\n", str3, 0, t3);
		return (42);
	}
}

