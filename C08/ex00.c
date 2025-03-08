#include<stdio.h>
#include<string.h>
#include "ft.h"

int main()
{
	int a = 21;
	int b = 42;
	char c = '4';
	char str1[] = "This is a sting";
	char str2[] = "This one too";


	ft_putchar(c);
	ft_swap(&a, &b);
	ft_putstr(str1);
	
	a = ft_strlen(str1);
	b = ft_strcmp(str1, str2);
	printf("OK\n");
}

void    ft_putchar(char c){
	if (c == 'a')
		return ;
}
void    ft_swap(int *a, int *b){
	*a = *b;
}
void    ft_putstr(char *str){
	if (!str)
		return ;
}

int		ft_strlen(char *str) {
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
int		ft_strcmp(char *s1, char *s2){return (*s1 - *s2);}
