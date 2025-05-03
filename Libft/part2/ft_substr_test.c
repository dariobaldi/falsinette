#include "ft.h"

typedef struct s_test
{
    char *desc;
    char *s;
    int  start;
    int  len;
    char *expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_substr_test()
{
    t_test tests[] = {
        {
             .desc = "Basic test:",
             .s = "Weisst du schon wie schoen das ist",
             .start = 7,
             .len = 8,
             .expected = "du schon",
        },
        {
            .desc = "Full substring from beginning:",
            .s = "ein Apfelbaum und Pferdemist",
            .start = 0,
            .len = 8,
            .expected = "ein Apfe",
        },
        {
            .desc = "Length exceeds string end:",
            .s = "und Wolken, die sich selber ziehen",
            .start = 28,
            .len = 15,
            .expected = "ziehen",
        },
        {
            .desc = "Start index past the end of string:",
            .s = "als wuerden sie die Luefte fliehen",
            .start = 34,
            .len = 15,
            .expected = "",
        },
        {
            .desc = "Zero length:",
            .s = "Bueno, me canse",
            .start = 0,
            .len = 0,
            .expected = "",
        },
        {
            .desc = "Empty source string:",
            .s = "",
            .start = 0,
            .len = 42,
            .expected = "",
        },
        {
            .desc = "NULL input string",
            .s = NULL,
            .start = 0,
            .len = 42,
            .expected = NULL,
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
        char *result = ft_substr(tests[i].s, tests[i].start, tests[i].len);

        if (!result && !tests[i].expected)
        {
            // printf(GREEN CHECKMARK GREY " [%d] %s" DEFAULT, i + 1, tests[i].desc);
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
            // printf(GREEN CHECKMARK GREY " [%d] %s got \"%s\" as expected" DEFAULT, i + 1, tests[i].desc, result);
        }

        if (result)
            free(result);
    }

    if (error == 0)
        printf(GREEN "OK" DEFAULT);
    return (error);
}