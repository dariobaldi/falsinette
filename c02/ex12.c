#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int main()
{
	char str[] = "promover\tel bienestar general,\ny asegurar\0los beneficios de la libertad, para nosotros, para nuestra posteridad, y para todos los hombres del mundo que quieran habitar en el suelo argentino";
	
	ft_print_memory(str, 100);
	ft_print_memory("Mais c'est effrayant ça. Tous les types qui font de la planche a voile piquent la femme de leurs amis alors", 100);
	printf("Test size 0\n");
	ft_print_memory(str, 0);
}
