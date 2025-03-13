#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../C07/ex04/ft_convert_base.c"
#if __has_include("../../C07/ex04/ft_convert_base2.c")
# include "../../C07/ex04/ft_convert_base2.c"
#endif
#include "../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char *nbr;
    char *base_from;
    char *base_to;
    char *expected;
} t_test;

int run_tests(t_test *tests, int count);

int main()
{
	t_test tests[] = {
        {
            .desc = "La muerte",
            .nbr = " -+-11230 56",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "44512",
        },
        {
            .desc = "Convert positive decimal to binary",
            .nbr = "42",
            .base_from = "0123456789",
            .base_to = "01",
            .expected = "101010",
        },
        {
            .desc = "Convert negative decimal to binary",
            .nbr = "-42",
            .base_from = "0123456789",
            .base_to = "01",
            .expected = "-101010",
        },
        {
            .desc = "Convert binary to hexadecimal",
            .nbr = "101010",
            .base_from = "01",
            .base_to = "0123456789ABCDEF",
            .expected = "2A",
        },
        {
            .desc = "Invalid base_from",
            .nbr = "42",
            .base_from = "01234567899",
            .base_to = "01",
            .expected = NULL,
        },
        {
            .desc = "Invalid base_to",
            .nbr = "42",
            .base_from = "0123456789",
            .base_to = "5",
            .expected = NULL,
        },
        {
            .desc = "Invalid base_to",
            .nbr = "-+-1410 56",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "4053",
        },
        {
            .desc = "Int min en Hex",
            .nbr = "-+---80000000",
            .base_from = "0123456789ABCDEF",
            .base_to = "0123456789",
            .expected = "-2147483648",
        },
        {
            .desc = "Int min en Hex",
            .nbr = "-+-2147483647",
            .base_from = "0123456789",
            .base_to = "0123456789ABCDEF",
            .expected = "7FFFFFFF",
        },
        {
            .desc = "Invalid Base 1",
            .nbr = "-+-2147483647",
            .base_from = "012345678+",
            .base_to = "0123456789ABCDEF",
            .expected = NULL,
        },
        {
            .desc = "Invalid Base 2",
            .nbr = "-+-2147483647",
            .base_from = "0123456789",
            .base_to = "0123456789ABCDE-",
            .expected = NULL,
        },
        {
            .desc = "Test Moulinette 1",
            .nbr = "134",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "251",
        },
        {
            .desc = "Test Moulinette 2",
            .nbr = "0",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "0",
        },
        {
            .desc = "Test Moulinette 3",
            .nbr = "-0",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "0",
        },
        {
            .desc = "Test Moulinette 4",
            .nbr = "-10",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "-13",
        },
        {
            .desc = "Test Moulinette 5",
            .nbr = "-7",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "-10",
        },
        {
            .desc = "Test Moulinette 6",
            .nbr = "21311",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "116063",
        },
        {
            .desc = "Test Moulinette 7",
            .nbr = "14",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "20",
        },
        {
            .desc = "Test Moulinette 8",
            .nbr = "-+-1410 56",
            .base_from = "0123456789",
            .base_to = "0123456",
            .expected = "4053",
        },
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        char *result = ft_convert_base(tests[i].nbr, tests[i].base_from, tests[i].base_to);

        if (!result && !tests[i].expected)
        {
            printf(GREEN CHECKMARK GREY " [%d] %s\n" DEFAULT, i + 1, tests[i].desc);
        }
        else if (!result || !tests[i].expected)
        {
            printf(RED "[%d] %s got1 \"%s\" instead of \"%s\"\n" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error -= 1;
        }
        else if (strcmp(result, tests[i].expected) != 0)
        {
			printf("%s\n%s\n%d\n%d\n", result, tests[i].expected, result[2],tests[i].expected[2]);
            printf(RED "[%d] %s got2 \"%s\" instead of \"%s\"\n" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error -= 1;
        }
        else
        {
            printf(GREEN CHECKMARK GREY " [%d] %s got \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, result);
        }

        free(result);
    }

    if (error == 0)
        printf(BG_GREEN BLACK BOLD "OK: Good job!" DEFAULT "\n");
    return error;
}
