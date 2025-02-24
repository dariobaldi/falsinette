#include<stdio.h>

int ft_str_is_printable(char *str);

int main()
{
	int t1, t2, t3;
	char *str1 = "qweryuiop[]asdfghhjkkl;'zxcvbnm, ./!@#$%^^&**()_+";
	char *str2 = "llllllI\n\tllll";
	char *str3 = "572\0-54";

	t1 = ft_str_is_printable(str1);
	t2 = ft_str_is_printable(str2);
	t3 = ft_str_is_printable(str3);
	if (!t1 && t2 && t3)
	{
		printf("FAILED. Result/Expected\n");
		printf("%s: %d/%d\n", str1, 1, t1);
		printf("%s: %d/%d\n", str2, 0, t2);
		printf("%s: %d/%d\n", str3, 0, t3);
		return (0);
	}
	printf("OK");
}
