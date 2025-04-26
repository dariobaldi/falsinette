#include <stdio.h>
#include <ctype.h>
#include <libft.h>
#include "../utils/constants.h"

int ft_test_isalpha(){
    char    c = 0;
    int     result, expected;

    while (c < 127)
    {
        result = ft_isalpha(c);
        expected = isalpha(c);

        if (result != expected)
        {
			printf(RED "isalpha: For %c got %d instead of %d\n" DEFAULT, c, result, expected);
            return (1);
        }
        c++;
    }
    printf(GREEN "isalpha: OK\n" DEFAULT);
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
    errors += ft_test_isalpha();

    return (errors);
}
