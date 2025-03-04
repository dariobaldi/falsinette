#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char *ft_strdup(char *src);

int main()
{
	int failed = 0;
	char src[] = "This is the same";
	char *dest;

	dest = ft_strdup(src);
	if (dest == src && !strcmp(src, dest))
	{
		printf("FAILED: returned same pointer as src\n");
		failed = 1;
	}
	if (strcmp(src, dest))
	{
		printf("FAILED: copied string is not the same\nExpected/Result\n");
		printf("%s\n%s\n%d\n", src, dest, strcmp(src, dest));
		failed = 1;
	}

	free(dest);

	if (!failed)
		printf("OK");

}