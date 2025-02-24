#include<stdio.h>
#include <string.h>

char *ft_strcapitalize(char *str);

int main()
{
	int t1;
	char str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char *str2 = "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un";

	ft_strcapitalize(str1);
	t1 = strcmp(str1, str2);
	if (t1)
	{
		printf("FAILED. Result/Expected\n");
		printf("%s\n%s", str1, str2);
		return (0);
	}
	printf("OK");
}
