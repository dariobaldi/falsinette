#include<stdio.h>

int ft_str_is_printable(char *str);

int main()
{
	int t1;
	char *str1 = "acbdefg";

	str1[2] = 127;
	t1 = ft_str_is_printable(str1);
	if (t1)
	{
		printf("FAILED. Result/Expected\n");
		printf("%s: %d/%d\n", str1, 1, t1);
		return (0);
	}

	int i = 0;
	while (i++ < 127)
	{
		str1[2] = '\0' + i;
		t1 = ft_str_is_printable(str1);
		if ((t1 && t1 < 32) || (!t1 && t1 > 31))
		{
			printf("FAILED. Result/Expected\n");
			printf("%s: %d/%d\n", str1, 1, t1);
			return (0);
		}
	}
	printf("OK");
}
