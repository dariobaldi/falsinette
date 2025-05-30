#include "ft.h"

typedef struct s_test
{
    char *desc;
    int  n;
    char *expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_itoa_test()
{
    t_test tests[] = {
        {
             .desc = "Basic case:",
             .n = 27,
             .expected = "27",
        },
        {
            .desc = "Negative number:",
            .n = -42,
            .expected = "-42",
        },
        {
            .desc = "Zeror:",
            .n = 0,
            .expected = "0",
        },
        {
            .desc = "One digit negative:",
            .n = -5,
            .expected = "-5",
        },
        {
            .desc = "All Numbers:",
            .n = 1234567890,
            .expected = "1234567890",
        },
        {
            .desc = "INT MAX",
            .n = 2147483647,
            .expected = "2147483647",
        },
        {
            .desc = "INT_MIN",
            .n = -2147483648,
            .expected = "-2147483648",
        },
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

static int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        char *result = ft_itoa(tests[i].n);

        if (!result && !tests[i].expected)
        {
            // printf(GREEN CHECKMARK GREY "\n [%d] %s" DEFAULT, i + 1, tests[i].desc);
        }
        else if (!result || !tests[i].expected)
        {
            printf(RED "\n[%d] %s got \"%s\" instead of \"%s\"" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error++;
        }
        else if (strcmp(result, tests[i].expected) != 0)
        {
            printf(RED "\n[%d] %s got \"%s\" instead of \"%s\"" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error++;
        }
        else
        {
            // printf(GREEN CHECKMARK GREY "\n [%d] %s got \"%s\" as expected" DEFAULT, i + 1, tests[i].desc, result);
        }

        if (result)
            free(result);
    }
    if (error == 0)
        printf(GREEN "OK" DEFAULT);
    return (error);
}