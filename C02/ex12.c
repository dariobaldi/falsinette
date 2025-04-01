#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	*print_memory(void *addr, unsigned int size);


int main()
{
	char str1[] = "promover\tel bienestar general,\ny asegurar\0los beneficios de la libertad, para nosotros, para nuestra posteridad, y para todos los hombres del mundo que quieran habitar en el suelo argentino";
	char *str2 = "Mais c'est effrayant ça. Tous les types qui font de la planche a voile piquent la femme de leurs amis alors";
	
	// Redirect stdout to a file
	freopen("diff_result", "w", stdout);

	ft_print_memory(str1, 100);
	ft_print_memory(str2, 100);
	ft_print_memory(str1, 0);

	freopen("diff_expected", "w", stdout);
	print_memory(str1, 100);
	print_memory(str2, 100);
	print_memory(str1, 0);
}

#include <unistd.h>

void	print_addr(void *addr);
void	puthex(unsigned char c);
void	print_hex_chars(void *addr, unsigned int size);
void	print_chars(void *addr, unsigned int size);

void	*print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	while (i < size)
	{
		n = size - i;
		if (n > 16)
			n = 16;
		print_addr(addr + i);
		print_hex_chars(addr + i, n);
		print_chars(addr + i, n);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

void	print_addr(void *addr)
{
	int				i;
	unsigned char	c;

	i = sizeof(addr) - 1;
	while (i >= 0)
	{
		c = *((char *)&addr + i);
		puthex(c);
		i--;
	}
	write(1, ": ", 2);
}

void	puthex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, hex + c / 16, 1);
	write(1, hex + c % 16, 1);
}

void	print_hex_chars(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			c = *((char *)addr + i);
			puthex(c);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_chars(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	while (i < size)
	{
		c = *((char *)addr + i);
		if (c > 31 && c < 127)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
}
