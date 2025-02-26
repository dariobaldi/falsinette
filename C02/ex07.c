#include<stdio.h>
#include <string.h>

char *ft_strupcase(char *str);

int main()
{
	int t1;
	char str1[] = "Qwerty? Azerty? Most definetly not QWERTZ!";
	char *str2 = "QWERTY? AZERTY? MOST DEFINETLY NOT QWERTZ!";

	ft_strupcase(str1);
	t1 = strcmp(str1, str2);
	if (t1)
	{
		printf("FAILED. Result/Expected\n");
		printf("%s\n%s", str1, str2);
		return (0);
	}
	printf("OK");
}
