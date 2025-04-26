#include <stdio.h>
#include <ctype.h>
#include <libft.h>
#include "../utils/constants.h"

int ft_test_1(int (*f)(int), int (*original)(int), char *name){
    char    c = 0;
    int     result, expected;

    while (c < 127)
    {
        result = (*f)(c);
        expected = (*original)(c);

        if ((!result && expected) || (result && !expected))
        {
			printf(RED "%s: For %c got %d instead of %d\n" DEFAULT, name, c, result, expected);
            return (1);
        }
        c++;
    }
    printf(GREEN "%s: OK\n" DEFAULT, name);
    return (0);
}

int ft_print(){
    char    c = 0;
    int     expected;

    while (c < 127)
    {
        expected = isalpha(c);
		printf(RED "isalpha: For %c (%d) got %d\n" DEFAULT, c, c, expected);
   
        c++;
    }
    return (0);
}

int main()
{
    int errors = 0;

    // ft_print();
    errors += ft_test_1(&ft_isalpha, &isalpha, "isalpha");
    errors += ft_test_1(&ft_isdigit, &isdigit, "isdigit");
    errors += ft_test_1(&ft_isalnum, &isalnum, "isalnum");

    return (errors);
}
