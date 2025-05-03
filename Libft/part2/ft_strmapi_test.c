#include "ft.h"

typedef char (*ActionFunc)(unsigned int, char);

char ft_odd_toupper(unsigned int i, char c)
{
    if (i % 2 != 0)
        return toupper(c);
    else
        return tolower(c);
}

typedef struct s_test
{
    char *desc;
    char *s;
    ActionFunc f;
    char *expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_strmapi_test()
{
    t_test tests[] = {
        {
             .desc = "Basic case:",
             .s = "Is this going to work?",
             .f = &ft_odd_toupper,
             .expected = "iS ThIs gOiNg tO WoRk?",
        },
        {
             .desc = "Empty string:",
             .s = "",
             .f = &ft_odd_toupper,
             .expected = "",
        },
        {
             .desc = "s == NULL",
             .s = NULL,
             .f = &ft_odd_toupper,
             .expected = NULL,
        },
        {
             .desc = "f == NULL",
             .s = "Does this work too?",
             .f = NULL,
             .expected = NULL,
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
        char *result = ft_strmapi(tests[i].s, tests[i].f);

        if (!result && !tests[i].expected)
        {
            printf(GREEN CHECKMARK GREY " [%d] %s\n" DEFAULT, i + 1, tests[i].desc);
        }
        else if (!result || !tests[i].expected)
        {
            printf(RED "[%d] %s got \"%s\" instead of \"%s\"\n" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error++;
        }
        else if (strcmp(result, tests[i].expected) != 0)
        {
            printf(RED "[%d] %s got \"%s\" instead of \"%s\"\n" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error++;
        }
        else
        {
            printf(GREEN CHECKMARK GREY " [%d] %s got \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, result);
        }

        if (result)
            free(result);
    }

    return (error);
}