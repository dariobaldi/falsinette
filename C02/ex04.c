#include<stdio.h>

int ft_str_is_lowercase(char *str);

int main()
{
	int t1, t2, t3;
	char *str1 = "asdsfdsdsf";
	char *str2 = "llllllIllll";
	char *str3 = "asdasd$#%$";

	t1 = ft_str_is_lowercase(str1);
	t2 = ft_str_is_lowercase(str2);
	t3 = ft_str_is_lowercase(str3);
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
