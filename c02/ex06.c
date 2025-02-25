#include<stdio.h>

int ft_str_is_printable(char *str);

int main()
{
	int t1;
	char str1[] = "abc-_-abc";

	str1[4] =  '\0' + 127;
	t1 = ft_str_is_printable(str1);
	if (t1)
	{
		printf("FAILED. Result/value\n");
		printf("%s: %d/%d\n", str1, t1, 127);
		return (0);
	}

	int i = 0;
	while (++i < 127)
	{
		str1[4] = '\0' + i;
		t1 = ft_str_is_printable(str1);
		if ((t1 && i < 32) || (!t1 && i > 31))
		{
			printf("FAILED. Result/value\n");
			printf("%s: %d/%d\n", str1, t1, i);
			return (0);
		}
	}
	printf("OK");
}
